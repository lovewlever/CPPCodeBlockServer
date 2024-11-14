//
// Created by catog on 2024/11/13.
//

#ifndef STRINGCOMMON_H
#define STRINGCOMMON_H
#include <string>
#include <drogon/HttpResponse.h>

class StringCommon
{
public:
    static drogon::HttpResponsePtr toHttpJsonResponse(const std::string &json);
};

inline drogon::HttpResponsePtr StringCommon::toHttpJsonResponse(const std::string &json)
{
    std::istringstream i{json};
    Json::Value root;
    Json::parseFromStream(Json::CharReaderBuilder{}, i, &root, nullptr);
    return drogon::HttpResponse::newHttpJsonResponse(root);
}
#endif //STRINGEXT_H
