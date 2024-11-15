//
// Created by catog on 2024/11/14.
//

#ifndef DBCODEBLOCKCOMMON_H
#define DBCODEBLOCKCOMMON_H
#include "DBCommon.h"

class DBCodeBlockCommon final : DBCommon
{
private:
    DBCodeBlockCommon();

    struct CodeBlockData
    {
        int64_t addTime{};
        std::string content{};
        int32_t deprecated{};
        std::string deprecatedReason{};
        std::string description{};
        int64_t id{};
        int32_t ifDelete{};
        std::string title{};
        int32_t userId{};
        int32_t visibility{};
        std::vector<nlohmann::json> tcbLabelEntityList{};

        nlohmann::json toJson()
        {
            nlohmann::json json{
                {"addTime", addTime},
                {"content", content},
                {"deprecated", deprecated},
                {"deprecatedReason", deprecatedReason},
                {"description", description},
                {"id", id},
                {"ifDelete", ifDelete},
                {"title", title},
                {"userId", userId},
                {"visibility", visibility},
                {"tcbLabelEntityList", tcbLabelEntityList},
            };
            return json;
        }
    };

    std::string composeSearchCodeBlockSql(const std::string &kw,
                                          const int32_t &labelId,
                                          const int32_t &classId,
                                          const int32_t &userId,
                                          const int32_t &matchDesc,
                                          const int32_t &matchContent);

public:
    static std::unique_ptr<DBCodeBlockCommon> getInstance();

    std::pair<bool, std::string> addCodeBlock(const std::string &title, const std::string &description,
                                              const std::string &content, std::vector<int32_t> &labelIds,
                                              const int32_t &uId);

    std::pair<bool, std::string> modifyCodeBlock(const int32_t &uId,
                                                 const std::string &title,
                                                 const int32_t &id,
                                                 const std::string &description,
                                                 const std::string &content);

    std::vector<nlohmann::json> searchCodeBlock(const std::string &kw,
                                                            const int32_t &labelId,
                                                            const int32_t &classId,
                                                            const int32_t &userId,
                                                            const int32_t &matchDesc,
                                                            const int32_t &matchContent);

    std::pair<bool, std::string> codeBlockDeprecated(const int32_t &uId, const int32_t &blockId, const int32_t &deprecated, const std::string &deprecatedReason);
    std::pair<bool, std::string> modifyVisibility(const int32_t &uId, const int32_t &blockId, const int32_t &visibility);
};

inline DBCodeBlockCommon::DBCodeBlockCommon(): DBCommon()
{
}

inline std::unique_ptr<DBCodeBlockCommon> DBCodeBlockCommon::getInstance()
{
    return std::unique_ptr<DBCodeBlockCommon>(new DBCodeBlockCommon());
}

inline std::pair<bool, std::string> DBCodeBlockCommon::addCodeBlock(
    const std::string &title,
    const std::string &description,
    const std::string &content,
    std::vector<int32_t> &labelIds,
    const int32_t &uId)
{
    session.startTransaction();
    const auto addTime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()).
            time_since_epoch().count();

    try
    {
        auto table = session.getSchema(dbSchema).getTable("tcb_content");
        const auto insRes = table.insert("title", "description", "content", "is_delete", "user_id", "add_time",
                                         "visibility", "deprecated", "deprecated_reason", "is_admin")
                .values(title, description, content, "0", uId, addTime, 0, 0, "", 0).execute();
        if (insRes.getAffectedItemsCount() != 1)
        {
            session.rollback();
            return std::make_pair(false, "插入失败！！");
        }
        // 获取插入的最后一条数据的ID
        auto resRows = table.select("LAST_INSERT_ID()").execute();
        const auto lastId = resRows.fetchOne()[0].get<int64_t>();

        //std::cout << genId << std::endl;
        auto ilTable = session.getSchema(dbSchema).getTable("tcb_intermediate_label");

        auto insertOpt = ilTable.insert("code_block_id", "label_id");
        for (auto &labelId: labelIds)
        {
            insertOpt.values(lastId, labelId);
        }
        if (const auto insertRes = insertOpt.execute(); insertRes.getAffectedItemsCount() <= 0)
        {
            session.rollback();
            return std::make_pair(false, "插入失败！！");
        }

        session.commit();
        return std::make_pair(true, "Success");
    } catch (const std::exception &e)
    {
        session.rollback();
        return std::make_pair(false, e.what());
    }
}


inline std::pair<bool, std::string> DBCodeBlockCommon::modifyCodeBlock(const int32_t &uId, const std::string &title,
                                                                       const int32_t &id,
                                                                       const std::string &description,
                                                                       const std::string &content)
{
    try
    {
        auto table = session.getSchema(dbSchema).getTable("tcb_content");
        const auto updateRes = table.update()
                .set("title", title)
                .set("description", description)
                .set("content", content)
                .where("id=:id AND user_id=:uId")
                .bind("id", id)
                .bind("uId", uId)
                .execute();
        const auto isDone = updateRes.getAffectedItemsCount() == 1;
        return std::make_pair(isDone, isDone ? "Success" : "更新失败!!");
    } catch (const std::exception &e)
    {
        return std::make_pair(false, e.what());
    }
}


inline std::string DBCodeBlockCommon::composeSearchCodeBlockSql(const std::string &kw,
                                                                const int32_t &labelId,
                                                                const int32_t &classId,
                                                                const int32_t &userId,
                                                                const int32_t &matchDesc,
                                                                const int32_t &matchContent)
{
    std::string s1{
        R"(select tc.id,tc.title,tc.description,tc.content,tc.add_time,tc.is_delete,tc.user_id,
        tl.id label_id,tl.add_time,tl.label_name,tl.is_delete, tc.visibility, tc.deprecated,
        tc.deprecated_reason
        from )"
    };
    std::string labelStr{
        R"((select * from tcb_content where id in(
                select code_block_id from tcb_intermediate_label where label_id = )"
    };
    labelStr.append(std::to_string(labelId)).append(")) tc ");

    std::string classStr{
        R"((select tc.* from tcb_content tc where tc.id in(
                select til.code_block_id from tcb_intermediate_label til where til.label_id in (
                select tl.id from tcb_label tl where tl.classification_id = )"
    };
    classStr.append(std::to_string(classId)).append("))) tc ");

    std::string el{" tcb_content tc "};

    std::string center{
        R"(inner join tcb_intermediate_label til
        on tc.id = til.code_block_id
        inner join tcb_label tl on til.label_id = tl.id
        where (tc.title like '%)"
    };
    center.append(kw).append("%' ");

    std::string md{R"(or tc.description like '%)"};
    md.append(kw).append("%' ");
    std::string mc{R"(or tc.content like '%)"};
    mc.append(kw).append("%' ");

    std::string end{
        R"(and (tc.visibility = 1
        or (tc.visibility = 0 and tc.user_id = )"
    };
    end.append(std::to_string(userId)).append("))) and tc.is_delete = 0 ");

    std::ostringstream oss;


    oss << s1;
    if (labelId != -1)
    {
        oss << labelStr;
    } else if (classId != -1)
    {
        oss << classStr;
    } else
    {
        oss << el;
    }
    oss << center;
    if (matchDesc == 1)
    {
        oss << md;
    }
    if (matchContent == 1)
    {
        oss << mc;
    }
    oss << end;
    std::cout << oss.str();
    return oss.str();
}

inline std::vector<nlohmann::json> DBCodeBlockCommon::searchCodeBlock(
    const std::string &kw,
    const int32_t &labelId,
    const int32_t &classId,
    const int32_t &userId,
    const int32_t &matchDesc,
    const int32_t &matchContent)
{
    const auto sql = composeSearchCodeBlockSql(kw, labelId, classId, userId, matchDesc, matchContent);
    auto queryRes = session.sql(sql).execute();

    std::map<int64_t, CodeBlockData> results;
    for (auto &&row: queryRes)
    {
        //tc.id, tc.title, tc.description, tc.content, tc.add_time, tc.is_delete, tc.user_id,
        //tl.id label_id, tl.add_time, tl.label_name, tl.is_delete, tc.visibility, tc.deprecated,
        //tc.deprecated_reason
        const auto tcId = row[0].get<int64_t>();
        auto &map = results[tcId];
        const auto isEmpty = map.id == 0;
        if (isEmpty)
        {
            const auto tcTitle = row[1].get<std::string>();
            const auto tcDesc = row[2].get<std::string>();
            const auto tcContent = row[3].get<std::string>();
            const auto tcAddTime = row[4].get<int64_t>();
            const auto tcIsDel = row[5].get<int32_t>();
            const auto tcUserId = row[6].get<int32_t>();
            map.id = tcId;
            map.title = tcTitle;
            map.description = tcDesc;
            map.content = tcContent;
            map.addTime = tcAddTime;
            map.ifDelete = tcIsDel;
            map.userId = tcUserId;
        }

        const auto tlId = row[7].get<int32_t>();
        const auto tlAddTime = row[8].get<int64_t>();
        const auto tlLabelName = row[9].get<std::string>();
        const auto tlIsDel = row[10].get<std::string>();
        nlohmann::json j{
            {"id", tlId},
            {"addTime", tlAddTime},
            {"labelName", tlLabelName},
        };

        map.tcbLabelEntityList.push_back(j);

        if (isEmpty)
        {
            const auto tcVisibility = row[11].get<int32_t>();
            const auto tcDeprecated = row[12].get<int32_t>();
            const auto tcDeprecatedReason = row[13].get<std::string>();
            map.visibility = tcVisibility;
            map.deprecated = tcDeprecated;
            map.deprecatedReason = tcDeprecatedReason;
        }
    }

    std::vector<nlohmann::json> resultsJson;
    for (auto &snd: results | std::views::values)
    {
        resultsJson.push_back(snd.toJson());
    }

    return resultsJson;
}

inline std::pair<bool, std::string> DBCodeBlockCommon::codeBlockDeprecated(
    const int32_t &uId,
    const int32_t &blockId,
    const int32_t &deprecated, const std::string &deprecatedReason)
{
    auto table = session.getSchema(dbSchema).getTable("tcb_content");
    const auto result = table.update().set("deprecated", deprecated).set("deprecated_reason", deprecatedReason)
    .where("id=:id AND user_id=:uId")
    .bind("id", blockId)
    .bind("uId", uId).execute();
    if (result.getAffectedItemsCount() == 1)
    {
        return std::make_pair(true, "Success");
    }
    return std::make_pair(false, "更新失败！");

}

inline std::pair<bool, std::string> DBCodeBlockCommon::modifyVisibility(const int32_t &uId, const int32_t &blockId,
    const int32_t &visibility)
{
    auto table = session.getSchema(dbSchema).getTable("tcb_content");
    const auto result = table.update().set("visibility", visibility)
    .where("id=:id AND user_id=:uId")
    .bind("id", blockId)
    .bind("uId", uId).execute();
    if (result.getAffectedItemsCount() == 1)
    {
        return std::make_pair(true, "Success");
    }
    return std::make_pair(false, "更新失败！");
}
#endif //DBCODEBLOCKCOMMON_H
