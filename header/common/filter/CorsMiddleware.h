//
// Created by catog on 2024/11/15.
//

#ifndef CORSMIDDLEWARE_H
#define CORSMIDDLEWARE_H
#include <drogon/drogon.h>
class CorsMiddleware final : public drogon::HttpMiddleware<CorsMiddleware>
{
public:
    CorsMiddleware();
    ~CorsMiddleware() override;

    void invoke(const drogon::HttpRequestPtr &req, drogon::MiddlewareNextCallback &&nextCb,
        drogon::MiddlewareCallback &&mcb) override;
};
#endif //CORSMIDDLEWARE_H
