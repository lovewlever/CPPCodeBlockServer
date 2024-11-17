//
// Created by catog on 2024/11/12.
//

#ifndef DBCOMMON_H
#define DBCOMMON_H

#include <memory>
#include <mysqlx/xdevapi.h>
#include <mutex>
#include "common/protobuf/UserInfo.pb.h"

class DBCommon
{
protected:
    DBCommon();
    DBCommon(const DBCommon &) = delete;
    static std::once_flag _onceFlag;

    std::string dbHost{"localhost"};
    std::string dbUser{"root"};
    std::string dbPassword{"Root@123456"};
    std::int32_t dbPort{33060};
    std::string dbSchema{"mysql"};
    mysqlx::Session session{dbHost, dbPort, dbUser, dbPassword, dbSchema};
    int32_t findIndexByColumnName(const std::vector<std::string> &columns, const std::string &column);

public:
    virtual ~DBCommon();
    static std::unique_ptr<DBCommon> getInstance();

    std::unique_ptr<gq::UserInfo> queryUserInfoById(int32_t userId);
    gq::UserInfo queryUserInfoByUserName(const std::string &userName);
    gq::UserInfo queryUserInfoByUserAccount(const std::string &userAccount);

    std::pair<bool, std::string> signUp(const std::string &account, const std::string &password, const std::string &userName);

    bool accountIsExist(const std::string &account);
    bool userNameIsExist(const std::string &uName);

};
#endif //DBCOMMON_H
