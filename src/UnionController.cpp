//
// Created by catog on 2024/11/12.
//
#include <controller/UnionController.h>

void UnionController::asyncHandleHttpRequest(const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
    Json::Value root;
    root["code"] = 200;
    root["message"] = "OK";
    root["data"] = Json::Value(Json::objectValue);
    auto resp = drogon::HttpResponse::newHttpJsonResponse(root);
    callback(resp);
}
