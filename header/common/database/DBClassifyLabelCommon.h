//
// Created by catog on 2024/11/13.
//

#ifndef DBCLASSIFYLABELCOMMON_H
#define DBCLASSIFYLABELCOMMON_H
#include "DBCommon.h"
#include "nlohmann/json.hpp"

class DBClassifyLabelCommon final : DBCommon
{
private:
    DBClassifyLabelCommon();

public:

    struct ClassificationData
    {
        int64_t id{};
        std::string classification_name{};
        std::int64_t add_time{};
        std::vector<nlohmann::json> refTcbLabelEntities{};

        nlohmann::json toJson()
        {
            nlohmann::json j;
            j["id"] = id;
            j["classification_name"] = classification_name;
            j["add_time"] = add_time;
            j["refTcbLabelEntities"] = refTcbLabelEntities;
            return j;
        }
    };

    static std::unique_ptr<DBClassifyLabelCommon> getInstance();

    std::vector<nlohmann::json> queryClassifyList(int32_t isContainLabel);

    std::vector<nlohmann::json> queryLabelListByClassifyId(int32_t uId, int classifyId);

    std::pair<bool, std::string> addAClassify(int32_t uId, const std::string &className);

    std::pair<bool, std::string> addALabel(int32_t uId, int32_t classId, const std::string &labelName);

    bool isClassifyIsExist(const std::string &className);

    bool isClassifyIsExistByClassId(int32_t classId);

    bool isLabelIsExist(const std::string &labelName);
};

inline DBClassifyLabelCommon::DBClassifyLabelCommon(): DBCommon()
{
}

inline std::unique_ptr<DBClassifyLabelCommon> DBClassifyLabelCommon::getInstance()
{
    return std::unique_ptr<DBClassifyLabelCommon>(new DBClassifyLabelCommon());
}

inline std::vector<nlohmann::json> DBClassifyLabelCommon::queryClassifyList(const int32_t isContainLabel)
{
    // refTcbLabelEntities

    auto sqlResult = session.sql(R"(
SELECT
  tc.id,
  tc.classification_name,
  tc.add_time,
  tl.id,
  tl.add_time,
  tl.label_name
FROM
  tcb_classification tc
  LEFT JOIN tcb_label tl ON tc.id = tl.classification_id
WHERE
  tc.is_delete = "0"
  AND tl.is_delete = "0"
)").execute();

    std::map<int64_t, ClassificationData> resultsById;
    for (auto && ite : sqlResult)
    {

        const auto tcId = (ite)[0].get<int64_t>();
        const auto tcCName = (ite)[1].get<std::string>();
        const auto tcAddTime = (ite)[2].get<int64_t>();

        auto &[id, classification_name, add_time, refTcbLabelEntities] = resultsById[tcId];
        if (classification_name.empty())
        {
            id = tcId;
            classification_name = tcCName;
            add_time = tcAddTime;
        }


        if (!(ite)[3].isNull() && isContainLabel != 0)
        {
            const auto tlId = (ite)[3].get<int64_t>();
            const auto tlAddTime = (ite)[4].get<int64_t>();
            const auto tlLabelName = (ite)[5].get<std::string>();

            nlohmann::json tl;
            tl["id"] = tlId;
            tl["add_time"] = tlAddTime;
            tl["label_name"] = tlLabelName;

            refTcbLabelEntities.push_back(tl);
        }
    }

    std::vector<nlohmann::json> datas;

     for (auto&[fst, snd] : resultsById)
     {
         datas.push_back(snd.toJson());
     }

     nlohmann::json j = datas;
    std::cout << j.dump() << std::endl;

    return datas;
}

inline std::vector<nlohmann::json> DBClassifyLabelCommon::queryLabelListByClassifyId(
    const int32_t uId, const int32_t classifyId)
{
    auto table = session.getSchema(dbSchema).getTable("tcb_label");
    auto rows = table.select("id", "add_time", "label_name")
            .where("is_delete='0' AND classification_id=:cId")
            .bind("cId", classifyId)
            .execute();
    std::vector<nlohmann::json> result;
    for (auto ite = rows.begin(); ite != rows.end(); ++ite)
    {
        auto id = (*ite)[0].get<int32_t>();
        auto addTime = (*ite)[1].get<int64_t>();
        auto className = (*ite)[2].get<std::string>();
        nlohmann::json item{{"id", id}, {"addTime", addTime}, {"classificationName", className}};
        result.push_back(item);
    }
    return result;
}

inline std::pair<bool, std::string> DBClassifyLabelCommon::addAClassify(int32_t uId, const std::string &className)
{
    try
    {
        if (isClassifyIsExist(className))
        {
            return std::make_pair(false, className + " is already exist");
        }
        auto table = session.getSchema(dbSchema).getTable("tcb_classification");
        const auto now = std::chrono::system_clock::now();
        const auto timestamp = std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count();
        const auto rows = table.insert("add_time", "classification_name", "is_delete", "user_id")
                .values(timestamp, className, "0", uId).execute();
        if (rows.getAffectedItemsCount() == 1)
        {
            return std::make_pair(true, "Success");
        }
        return std::make_pair(false, "插入失败!!");
    } catch (std::exception &e)
    {
        return std::make_pair(false, e.what());
    }
}

inline std::pair<bool, std::string> DBClassifyLabelCommon::addALabel(int32_t uId, int32_t classId,
                                                                     const std::string &labelName)
{
    try
    {
        if (isLabelIsExist(labelName))
        {
            return std::make_pair(false, labelName + " is already exist");
        }
        if (!isClassifyIsExistByClassId(classId))
        {
            return std::make_pair(false, "ClassifyId: " + std::to_string(classId) + " is not exist");
        }
        auto table = session.getSchema(dbSchema).getTable("tcb_label");
        const auto now = std::chrono::system_clock::now();
        const auto timestamp = std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count();
        const auto rows = table.insert("add_time", "label_name", "is_delete", "classification_id", "user_id")
                .values(timestamp, labelName, "0", classId, uId).execute();
        if (rows.getAffectedItemsCount() == 1)
        {
            return std::make_pair(true, "Success");
        }
        return std::make_pair(false, "插入失败!!");
    } catch (std::exception &e)
    {
        return std::make_pair(false, e.what());
    }
}

inline bool DBClassifyLabelCommon::isClassifyIsExist(const std::string &className)
{
    auto table = session.getSchema(dbSchema).getTable("tcb_classification");
    auto rows = table.select("COUNT(0)").where("classification_name=:cn").bind("cn", className).execute();
    return rows.fetchOne()[0].get<int64_t>() > 0;
}

inline bool DBClassifyLabelCommon::isClassifyIsExistByClassId(const int32_t classId)
{
    auto table = session.getSchema(dbSchema).getTable("tcb_classification");
    auto rows = table.select("COUNT(0)").where("id=:ci").bind("ci", classId).execute();
    return rows.fetchOne()[0].get<int64_t>() > 0;
}

inline bool DBClassifyLabelCommon::isLabelIsExist(const std::string &labelName)
{
    auto table = session.getSchema(dbSchema).getTable("tcb_label");
    auto rows = table.select("COUNT(0)").where("label_name=:ln").bind("ln", labelName).execute();
    return rows.fetchOne()[0].get<int64_t>() > 0;
}
#endif //DBCLASSIFYLABELCOMMON_H
