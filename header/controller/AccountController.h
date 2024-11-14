//
// Created by catog on 2024/11/12.
//

#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include <iostream>
#include <drogon/drogon.h>
#include <service/AccountService.h>

class AccountController final : public drogon::HttpController<AccountController>
{
private:
    std::unique_ptr<AccountService>  _accountService{nullptr};
public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(AccountController::signIn, "/api/user/sign-in", drogon::Post);
    ADD_METHOD_TO(AccountController::signUp, "/api/user/register", drogon::Post);
    ADD_METHOD_TO(AccountController::queryUserByUserId, "/api/user/query-user-by-uid", drogon::Post);
    METHOD_LIST_END

    AccountController();
    ~AccountController() override;
    void signIn(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback);
    void signUp(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback);
    void queryUserByUserId(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback);

};

#endif //ACCOUNTCONTROLLER_H
