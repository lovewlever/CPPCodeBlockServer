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
    if (account.empty() || password.empty())
    {
        return ResultCommon::generateResultJson(PASSWORD_FAIL, "账号或密码不能为空！");
    }
    const auto db = DBCommon::getInstance();
    const auto userInfo = db->queryUserInfoByUserAccount(account);
    if (userInfo.user_pwd().empty())
    {
        return ResultCommon::generateResultJson(PASSWORD_FAIL, "未找到用户！");
    }
    int32_t uid = -1;
    if (userInfo.user_pwd() == password)
    {
        std::cout << "UserId:" << userInfo.id() << std::endl;
        uid = userInfo.id();
    } else
    {
        return ResultCommon::generateResultJson(PASSWORD_FAIL, "账号或密码错误！");
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

std::string AccountService::signUp(const std::string &account, const std::string &password, const std::string &userName)
{
    if (account.empty() || password.empty() || userName.empty())
    {
        return ResultCommon::generateResultJson(PARAMS_FAIL, "参数错误!");
    }
    if (password.length() < 6)
    {
        return ResultCommon::generateResultJson(PARAMS_FAIL, "密码不能少于6位!");
    }
    const auto db = DBCommon::getInstance();
    if (db->accountIsExist(account) || db->userNameIsExist(userName))
    {
        return ResultCommon::generateResultJson(INSERT_FAIL, "用户名或账号已存在！");
    }
    const auto [fst, snd] = db->signUp(account, password, userName);
    return ResultCommon::generateResultJson(fst ? SUCCESS : PARAMS_FAIL, snd);
}
