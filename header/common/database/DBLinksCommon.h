//
// Created by catog on 2024/11/13.
//

#ifndef DBLINKSCOMMON_H
#define DBLINKSCOMMON_H
#include "DBCommon.h"
#include "nlohmann/json.hpp"

class DBLinksCommon final : DBCommon
{
private:
    DBLinksCommon();

public:
    ~DBLinksCommon() override;

    std::unique_ptr<nlohmann::json::array_t> queryLinkList(int32_t uId);

    std::pair<bool, std::string> addALink(int32_t uId, const std::string &name, const std::string &link);

    std::pair<bool, std::string> deleteLinkById(int32_t uId, int32_t linkId);

    std::pair<bool, std::string> modifyLink(int32_t uId, int32_t linkId, const std::string &name,
                                            const std::string &link);

    int32_t modifyLink(int32_t uId, int32_t linkId);

    bool isAlreadyExistsByLinkName(const std::string &name);

    static std::unique_ptr<DBLinksCommon> getInstance();
};

inline DBLinksCommon::DBLinksCommon(): DBCommon()
{
}

inline DBLinksCommon::~DBLinksCommon()
{
}

inline std::unique_ptr<nlohmann::json::array_t> DBLinksCommon::queryLinkList(const int32_t uId)
{
    auto table = session.getSchema(dbSchema).getTable("tcb_link");
    auto rows = table.select("id", "add_time", "name", "link").where("user_id='" + std::to_string(uId) + "'").execute();
    auto links = std::make_unique<std::vector<nlohmann::json> >();
    for (auto row: rows)
    {
        auto id = row[0].get<int32_t>();
        auto addTime = row[1].get<long long>();
        auto name = row[2].get<std::string>();
        auto link = row[3].get<std::string>();
        nlohmann::json linkJson{};
        linkJson["id"] = id;
        linkJson["addTime"] = addTime;
        linkJson["name"] = name;
        linkJson["link"] = link;
        links->push_back(linkJson);
    }
    return links;
}

inline std::pair<bool, std::string> DBLinksCommon::addALink(const int32_t uId, const std::string &name,
                                                            const std::string &link)
{
    try
    {
        const auto now = std::chrono::system_clock::now();
        const auto timestamp = std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count();
        auto table = session.getSchema(dbSchema).getTable("tcb_link");
        auto result = table.insert("add_time", "name", "link", "user_id").values(timestamp, name, link, uId).execute();
        return std::make_pair(true, "Success");
    } catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return std::make_pair(false, e.what());
    }
}

inline std::pair<bool, std::string> DBLinksCommon::deleteLinkById(int32_t uId, int32_t linkId)
{
    try
    {
        auto table = session.getSchema(dbSchema).getTable("tcb_link");
        const auto result = table.remove()
                .where("user_id=:user_id AND id=:linkId")
                .bind("user_id", uId).
                bind("linkId", linkId).execute();
        if (result.getAffectedItemsCount() > 0)
        {
            return std::make_pair(true, "Success");
        }
        return std::make_pair(false, "删除失败");
    } catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return std::make_pair(false, e.what());
    }
}

inline std::pair<bool, std::string> DBLinksCommon::modifyLink(const int32_t uId, const int32_t linkId,
                                                              const std::string &name,
                                                              const std::string &link)
{
    auto table = session.getSchema(dbSchema).getTable("tcb_link");
    auto result = table.update()
            .set("name", name)
            .set("link", link)
            .where("user_id=:user_id AND id=:linkId")
            .bind("user_id", uId)
            .bind("linkId", linkId)
            .execute();
    if (result.getAffectedItemsCount() > 0)
    {
        return std::make_pair(true, "Success");
    }
    return std::make_pair(false, "");
}


inline bool DBLinksCommon::isAlreadyExistsByLinkName(const std::string &name)
{
    auto table = session.getSchema(dbSchema).getTable("tcb_link");
    auto result = table.select("COUNT(0)").where("name='" + name + "'").execute();
    auto row = result.fetchOne();
    return row[0].get<int32_t>() > 0;
}

inline std::unique_ptr<DBLinksCommon> DBLinksCommon::getInstance()
{
    return std::unique_ptr<DBLinksCommon>(new DBLinksCommon());
}
#endif //DBLINKSCOMMON_H
