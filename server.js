const express = require("express");
const mysql = require("mysql");
const dotenv = require("dotenv");
const cors = require("cors");
const fs = require("fs");
const path = require("path");
const { Parser } = require("json2csv");

dotenv.config();

const app = express();
app.use(cors());
app.use(express.json());

const db = mysql.createConnection({
  host: process.env.DB_HOST,
  user: process.env.DB_USER,
  password: process.env.DB_PASSWORD,
  database: process.env.DB_SCHEMA,
});

app.post("/generate_report", (req, res) => {
  const { month, year } = req.body;
  const days = new Date(year, month, 0).getDate();

  const headers = ["Emp Id", "Name", "Deploy Site"];
  for (let i = 1; i <= days; i++) {
    headers.push(
      new Date(year, month - 1, i).toLocaleDateString("en-US", {
        day: "2-digit",
        month: "long",
      })
    );
  }
  headers.push("Total Days", "Total OT");

  db.query("SELECT * FROM employees", (err, employees) => {
    if (err) {
      return res.status(500).json({ error: err.message });
    }

    const data = employees.map((employee) => ({
      "Emp Id": employee.empId,
      Name: employee.employeeName,
      "Deploy Site": employee.employeeDeploySite,
      "Total Days": 0,
      "Total OT": 0,
    }));

    let query =
      "SELECT * FROM attendance_record WHERE emp_id IN (?) AND date BETWEEN ? AND ? ORDER BY date";
    db.query(
      query,
      [
        employees.map((e) => e.empId),
        `${year}-${month}-01`,
        `${year}-${month}-${days}`,
      ],
      (err, attendances) => {
        if (err) {
          return res.status(500).json({ error: err.message });
        }

        attendances.forEach((attendance) => {
          const employee = data.find((e) => e["Emp Id"] === attendance.emp_id);
          const dateKey = new Date(attendance.date).toLocaleDateString(
            "en-US",
            { day: "2-digit", month: "long" }
          );
          employee[dateKey] = `${
            attendance.punch_in ? attendance.punch_in.slice(11, 19) : "NaN"
          }\n${
            attendance.punch_out ? attendance.punch_out.slice(11, 19) : "NaN"
          }`;
        });

        query =
          "SELECT * FROM attendance_history WHERE emp_id IN (?) AND year = ? AND month = ?";
        db.query(
          query,
          [employees.map((e) => e.empId), year, month],
          (err, histories) => {
            if (err) {
              return res.status(500).json({ error: err.message });
            }

            histories.forEach((history) => {
              const employee = data.find((e) => e["Emp Id"] === history.emp_id);
              employee["Total Days"] = Math.ceil(history.days);
              employee["Total OT"] = history.ot_hours;
            });

            const json2csv = new Parser({ fields: headers });
            const csv = json2csv.parse(data);
            const outputPath = path.join(__dirname, "output.csv");
            fs.writeFileSync(outputPath, csv);

            res.sendFile(outputPath);
          }
        );
      }
    );
  });
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});
