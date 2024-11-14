//
// Created by catog on 2024/11/14.
//

#ifndef TOKENFILTER_H
#define TOKENFILTER_H
#include <drogon/HttpFilter.h>

class TokenFilter final: public drogon::HttpFilter<TokenFilter>
{
public:
    void doFilter(const drogon::HttpRequestPtr &req, drogon::FilterCallback &&fcb,
        drogon::FilterChainCallback &&fccb) override;
};
#endif //TOKENFILTER_H
