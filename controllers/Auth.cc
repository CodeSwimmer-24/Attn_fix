#include "Auth.h"
#include "models/Customers.h"
// Add definition of your processing function here
void Auth::signupWorker(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback) {
    LOG_DEBUG << "Worker Signup";

    Json::Value ret;
    ret["result"]="ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void Auth::signupCustomer(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback) {
    LOG_DEBUG << "Customer Signup";

    auto data = req->getJsonObject();
    Json::Value ret;
    HttpResponsePtr resp;

    if (data) {
        if ((*data)["full_name"].asString() == "" ||
            (*data)["email"].asString() == "" ||
            (*data)["contact"].asString() == "" ||
            (*data)["address"].asString() == "" ||
            (*data)["locality"].asString() == "" ||
            (*data)["district"].asString() == "" ||
            (*data)["state"].asString() == ""
        ) {
            ret["message"] = "Invalid json data";
            resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(k400BadRequest);
        } else {
            drogon::orm::DbClientPtr dbPtr;
            auto contact = (*data)["contact"].asInt64();
            drogon::orm::Criteria criterion("contact", drogon::orm::CompareOperator::EQ, contact);
            drogon::orm::Mapper<drogon_model::workersdb::Customers> customerMap(dbPtr);
            auto records = customerMap.findBy(criterion);

            if (records.empty()) {
                drogon_model::workersdb::Customers customerObj(*data);
                customerMap.insert(customerObj);
                
                ret["message"] = "Customer signup successful";
                resp = HttpResponse::newHttpJsonResponse(ret);
                resp->setStatusCode(k201Created);
            } else {
                ret["message"] = "Customer already exists";
                resp = HttpResponse::newHttpJsonResponse(ret);
                resp->setStatusCode(k403Forbidden);
            }            
        }
    } else {
        ret["message"] = "Invalid request, provide the json data";
        
        resp = HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k400BadRequest);
    }
    
    callback(resp);
}

void Auth::loginWorker(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback) {
    LOG_DEBUG << "Worker Login";

    Json::Value ret;
    ret["result"]="ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void Auth::loginCustomer(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback) {
    LOG_DEBUG << "Customer Login";

    Json::Value ret;
    ret["result"]="ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
