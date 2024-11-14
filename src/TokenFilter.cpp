//
// Created by catog on 2024/11/14.
//
#include "common/filter/TokenFilter.h"

#include "common/ResultCommon.h"
#include "common/StringCommon.h"
#include "common/TokenCommon.h"

void TokenFilter::doFilter(const drogon::HttpRequestPtr &req, drogon::FilterCallback &&fcb,
    drogon::FilterChainCallback &&fccb)
{
    const auto token = req->getHeader("token");
    if (const auto iss = TokenCommon::getInstance()->verifyToken(token); iss)
    {
        fccb();
    } else
    {
        const auto resp = StringCommon::toHttpJsonResponse(ResultCommon::generateResultJson(LoginExpired, "请重新登录!"));
        fcb(resp);
    }
}
