//
// Created by catog on 2024/11/12.
//
#include <iostream>
#include <ostream>
#include <service/AccountService.h>

#include "common/ResultCommon.h"
#include "common/TokenCommon.h"
#include "common/database/DBCommon.h"
#include <google/protobuf/util/json_util.h>

AccountService::AccountService()
{
    std::cout << "AccountService::AccountService()" << std::endl;
}

AccountService::~AccountService()
{
    std::cout << "AccountService::~AccountService()" << std::endl;
}

std::string AccountService::signIn(const std::string& account, const std::string& password)
{
    std::cout << account << "  " << password << std::endl;
    const auto db = DBCommon::getInstance();
    const auto userInfo = db->queryUserInfoByUserAccount(account);
    int32_t uid = -1;
    if (userInfo.user_pwd() == password)
    {
        std::cout << "UserId:" << userInfo.id() << std::endl;
        uid = userInfo.id();
    }

    std::cout << uid << std::endl;
    if (uid != -1)
    {
        const auto token = TokenCommon::getInstance()->generateToken(uid);
        auto jsonData = R"({"token": ")" + token + R"("})";
        const std::vector vec{nlohmann::json::parse(jsonData)};
        return ResultCommon::generateResultJson(vec);
    }
    return ResultCommon::generateResultJson(PASSWORD_FAIL, "Failed to sign in");
}

std::string AccountService::queryUserInfoByUId(int32_t uid)
{
    const auto db = DBCommon::getInstance();
    const auto uInfo = db->queryUserInfoById(uid);
    if (uInfo == nullptr)
    {
        return ResultCommon::generateResultJson(DATA_IS_EMPTY, "未查询到数据");
    }
    std::string uInfoJsonStr{};
    auto a = google::protobuf::util::MessageToJsonString(*uInfo, &uInfoJsonStr);
    const std::vector vec{nlohmann::json::parse(uInfoJsonStr)};
    return ResultCommon::generateResultJson(vec);
}
