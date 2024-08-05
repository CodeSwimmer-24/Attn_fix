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

// Handle database connection errors and reconnect if necessary
const connectToDatabase = () => {
  db.connect((err) => {
    if (err) {
      console.error("Error connecting to the database:", err);
      setTimeout(connectToDatabase, 2000); // Attempt to reconnect after 2 seconds
    } else {
      console.log("Connected to the database");
    }
  });
};

connectToDatabase();

// Handle connection errors during runtime
db.on("error", (err) => {
  console.error("Database error:", err);
  if (err.code === "PROTOCOL_CONNECTION_LOST") {
    connectToDatabase(); // Reconnect on connection loss
  } else {
    throw err;
  }
});

app.get("/", (req, res) => {
  res.send(`
    <!DOCTYPE html>
    <html lang="en">
      <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Attendance Report Generator</title>
        <style>
          body {
            font-family: Arial, sans-serif;
            background-color: #f8f9fa;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
          }
          .container {
            background-color: #ffffff;
            padding: 2rem;
            border-radius: 8px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            max-width: 400px;
            width: 100%;
          }
          h1 {
            text-align: center;
            color: #343a40;
          }
          form {
            display: flex;
            flex-direction: column;
          }
          label {
            margin-top: 1rem;
            color: #495057;
          }
          select {
            padding: 0.5rem;
            border: 1px solid #ced4da;
            border-radius: 4px;
            margin-top: 0.5rem;
          }
          button {
            margin-top: 2rem;
            padding: 0.75rem;
            background-color: #007bff;
            border: none;
            border-radius: 4px;
            color: white;
            font-size: 1rem;
            cursor: pointer;
            transition: background-color 0.3s;
            display: flex;
            align-items: center;
            justify-content: center;
          }
          button:hover {
            background-color: #0056b3;
          }
          .form-group {
            margin-bottom: 1.5rem;
          }
          .spinner {
            display: none;
            width: 1rem;
            height: 1rem;
            border: 2px solid rgba(255, 255, 255, 0.6);
            border-top: 2px solid white;
            border-radius: 50%;
            animation: spin 1s linear infinite;
            margin-left: 0.5rem;
          }
          @keyframes spin {
            0% {
              transform: rotate(0deg);
            }
            100% {
              transform: rotate(360deg);
            }
          }
        </style>
      </head>
      <body>
        <div class="container">
          <h1>Generate Attendance Report</h1>
          <form id="reportForm">
            <div class="form-group">
              <label for="month">Month:</label>
              <select id="month" name="month" required>
                <option value="1">January</option>
                <option value="2">February</option>
                <option value="3">March</option>
                <option value="4">April</option>
                <option value="5">May</option>
                <option value="6">June</option>
                <option value="7">July</option>
                <option value="8">August</option>
                <option value="9">September</option>
                <option value="10">October</option>
                <option value="11">November</option>
                <option value="12">December</option>
              </select>
            </div>
            <div class="form-group">
              <label for="year">Year:</label>
              <select id="year" name="year" required>
                <script>
                  const currentYear = new Date().getFullYear();
                  for (let year = currentYear; year >= 2000; year--) {
                    document.write(\`<option value="\${year}">\${year}</option>\`);
                  }
                </script>
              </select>
            </div>
            <button type="submit">
              Generate Report
              <div class="spinner" id="spinner"></div>
            </button>
          </form>
        </div>
        <script>
          document
            .getElementById("reportForm")
            .addEventListener("submit", async function (event) {
              event.preventDefault();
              const month = document.getElementById("month").value;
              const year = document.getElementById("year").value;

              const button = event.target.querySelector("button");
              const spinner = document.getElementById("spinner");

              button.disabled = true;
              spinner.style.display = "inline-block";

              try {
                const response = await fetch(
                  "/generate_report",
                  {
                    method: "POST",
                    headers: {
                      "Content-Type": "application/json",
                    },
                    body: JSON.stringify({ month, year }),
                  }
                );

                if (response.ok) {
                  const blob = await response.blob();
                  const url = window.URL.createObjectURL(blob);
                  const a = document.createElement("a");
                  a.style.display = "none";
                  a.href = url;
                  a.download = "output.csv";
                  document.body.appendChild(a);
                  a.click();
                  window.URL.revokeObjectURL(url);
                } else {
                  alert("Failed to generate report");
                }
              } catch (error) {
                alert("An error occurred while generating the report");
              } finally {
                button.disabled = false;
                spinner.style.display = "none";
              }
            });
        </script>
      </body>
    </html>
  `);
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
      console.error("Error fetching employees:", err);
      return res.status(500).json({ error: "Error fetching employees" });
    }

    const data = employees.map((employee) => ({
      "Emp Id": employee.empId,
      Name: employee.employeeName,
      "Deploy Site": employee.employeeDeploySite,
      "Total Days": 0,
      "Total OT": 0,
    }));

    const query =
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
          console.error("Error fetching attendance records:", err);
          return res
            .status(500)
            .json({ error: "Error fetching attendance records" });
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

        const historyQuery =
          "SELECT * FROM attendance_history WHERE emp_id IN (?) AND year = ? AND month = ?";
        db.query(
          historyQuery,
          [employees.map((e) => e.empId), year, month],
          (err, histories) => {
            if (err) {
              console.error("Error fetching attendance histories:", err);
              return res
                .status(500)
                .json({ error: "Error fetching attendance histories" });
            }

            histories.forEach((history) => {
              const employee = data.find((e) => e["Emp Id"] === history.emp_id);
              employee["Total Days"] = Math.ceil(history.days);
              employee["Total OT"] = history.ot_hours;
            });

            const json2csv = new Parser({ fields: headers });
            try {
              const csv = json2csv.parse(data);
              const outputPath = path.join(__dirname, "output.csv");
              fs.writeFileSync(outputPath, csv);
              res.download(outputPath, "output.csv", (err) => {
                if (err) {
                  console.error("Error sending file:", err);
                }
                fs.unlinkSync(outputPath); // Delete the file after sending it
              });
            } catch (err) {
              console.error("Error generating CSV:", err);
              res.status(500).json({ error: "Error generating CSV" });
            }
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

// Global error handlers
process.on("uncaughtException", (err) => {
  console.error("Uncaught Exception:", err);
  process.exit(1);
});

process.on("unhandledRejection", (reason, promise) => {
  console.error("Unhandled Rejection at:", promise, "reason:", reason);
  process.exit(1);
});
