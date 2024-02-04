#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class Auth : public drogon::HttpController<Auth>
{
  public:
    METHOD_LIST_BEGIN
    METHOD_ADD(Auth::signupWorker, "/worker/signup", Post);
    METHOD_ADD(Auth::signupCustomer, "/customer/signup", Post);
    METHOD_ADD(Auth::loginWorker, "/worker/login", Post);
    METHOD_ADD(Auth::loginCustomer, "/customer/login", Post);
    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    void signupWorker(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);
    void signupCustomer(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);
    void loginWorker(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);
    void loginCustomer(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);
};
