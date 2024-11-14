//
// Created by catog on 2024/11/12.
//
#include <common/database/DBCommon.h>


DBCommon::DBCommon()

{
    std::cout<<"DBCommon::DBCommon()"<<std::endl;
}

int32_t DBCommon::findIndexByColumnName(const std::vector<std::string> &columns, const std::string &column)
{
    auto ite = std::find(columns.begin(), columns.end(), column);
    if (ite != columns.end())
    {
        return std::distance(columns.begin(), ite);
    }
    return -1;
}

DBCommon::~DBCommon()
{
    session.close();
    std::cout<<"DBCommon::~DBCommon()"<<std::endl;
}

std::unique_ptr<DBCommon> DBCommon::getInstance()
{
    return std::unique_ptr<DBCommon>(new DBCommon());
}

std::unique_ptr<gq::UserInfo> DBCommon::queryUserInfoById(int32_t userId)
{
    auto table = session.getSchema(dbSchema).getTable("tcb_user");
    mysqlx::RowResult result = table.select("id", "user_name", "user_account", "is_admin", "ss_mt", "ss_mdi", "ss_mcb").where("id=" + std::to_string(userId)).execute();
    if (result.count() <= 0)
    {
        return nullptr;
    }
    auto row = result.fetchOne();
    std::vector<std::string> columnNames;
    auto &colums = result.getColumns();

    auto userInfo = std::make_unique<gq::UserInfo>();

    for (auto &column : colums)
    {
        columnNames.push_back(column.getColumnName());
    }

    userInfo->set_id(row[findIndexByColumnName(columnNames, "id")].get<int32_t>());
    userInfo->set_user_name(row[findIndexByColumnName(columnNames, "user_name")].get<std::string>());
    userInfo->set_user_account(row[findIndexByColumnName(columnNames, "user_account")].get<std::string>());
    userInfo->set_is_admin(row[findIndexByColumnName(columnNames, "is_admin")].get<int32_t>());
    userInfo->set_ss_mt(row[findIndexByColumnName(columnNames, "ss_mt")].get<int32_t>());
    userInfo->set_ss_mdi(row[findIndexByColumnName(columnNames, "ss_mdi")].get<int32_t>());
    userInfo->set_ss_mcb(row[findIndexByColumnName(columnNames, "ss_mcb")].get<int32_t>());

    return userInfo;
}

gq::UserInfo DBCommon::queryUserInfoByUserName(const std::string &userName)
{
    auto table = session.getSchema(dbSchema).getTable("tcp_user");
    auto rowsResult = table.select("user_account", "user_pwd").where("user_name=" + userName).execute();
    if (rowsResult.count() <= 0)
    {
        return gq::UserInfo{};
    }
    auto row = rowsResult.fetchOne();
    auto userAccount = row[0].get<std::string>();
    auto userPwd = row[1].get<std::string>();
    gq::UserInfo userInfo;
    userInfo.set_user_account(userAccount);
    userInfo.set_user_pwd(userPwd);
    return userInfo;
}
gq::UserInfo DBCommon::queryUserInfoByUserAccount(const std::string &userAccount)
{
    auto table = session.getSchema(dbSchema).getTable("tcb_user");
    auto rowsResult = table.select("id","user_account", "user_pwd").where("user_account='" + userAccount + "'").execute();
    if (rowsResult.count() <= 0)
    {
        return gq::UserInfo{};
    }
    auto row = rowsResult.fetchOne();
    const auto uId = row[0].get<int32_t>();
    auto account = row[1].get<std::string>();
    auto userPwd = row[2].get<std::string>();
    gq::UserInfo userInfo;
    userInfo.set_user_account(account);
    userInfo.set_user_pwd(userPwd);
    userInfo.set_id(uId);
    return userInfo;
}
