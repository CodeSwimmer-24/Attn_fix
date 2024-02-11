#include <drogon/drogon.h>

int main() {
    //Load config file
#ifdef _WIN32
    drogon::app().loadConfigFile("../../config.json");
#else
    drogon::app().loadConfigFile("../config.json");
#endif
    
    // drogon::app().registerHandler("/", [](const drogon::HttpRequest& req
    //     , std::function<void (const drogon::HttpResponsePtr&)> &&callback) {
    //     auto resp = drogon::HttpResponse::newHttpResponse();
    //     resp->setBody("Hello world!");
    //     callback(resp);
    // }, {drogon::Get});

    //Run HTTP framework,the method will block in the internal event loop
    // drogon::app().addListener("0.0.0.0", 5555);
    LOG_INFO << "Server running on 127.0.0.1:80";
    drogon::app().run();

    return 0;
}
