//
// Created by catog on 2024/11/12.
//

#ifndef UNIONCONTROLLER_H
#define UNIONCONTROLLER_H

#include <drogon/drogon.h>

class UnionController final : public drogon::HttpSimpleController<UnionController>
{
public:
    void asyncHandleHttpRequest(const drogon::HttpRequestPtr &req,std::function<void(const drogon::HttpResponsePtr &)> &&callback) override;

    PATH_LIST_BEGIN;
    PATH_ADD("/getUnion", drogon::Options, drogon::Get, "CorsMiddleware", "TokenFilter");
    PATH_LIST_END;
};

#endif //UNIONCONTROLLER_H
