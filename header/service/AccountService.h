//
// Created by catog on 2024/11/12.
//

#ifndef ACCOUNTSERVICE_H
#define ACCOUNTSERVICE_H
#include "common/ResultCommon.h"

class AccountService
{
private:

public:
    AccountService();
    ~AccountService();

    std::string signIn(const std::string& account, const std::string& password);
    std::string queryUserInfoByUId(int32_t uid);
    std::string signUp(const std::string& account, const std::string& password, const std::string& userName);
};

#endif //ACCOUNTSERVICE_H
