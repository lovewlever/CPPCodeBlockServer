//
// Created by catog on 2024/11/15.
//

#include <common/filter/CorsMiddleware.h>


CorsMiddleware::CorsMiddleware()
{
}

CorsMiddleware::~CorsMiddleware()
{
}

void CorsMiddleware::invoke(const drogon::HttpRequestPtr &req, drogon::MiddlewareNextCallback &&nextCb,
                            drogon::MiddlewareCallback &&mcb)
{

    nextCb([mcb = std::move(mcb)](const drogon::HttpResponsePtr &resp)
    {
        // 设置 CORS 响应头
        resp->addHeader("Access-Control-Allow-Origin", "*"); // 允许所有源
        resp->addHeader("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
        resp->addHeader("Access-Control-Allow-Headers", "*");
        resp->addHeader("Access-Control-Allow-Credentials", "true");
        mcb(resp);
    });
}
