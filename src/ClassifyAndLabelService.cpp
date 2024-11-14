//
// Created by catog on 2024/11/13.
//
#include <service/ClassifyAndLabelService.h>

#include "common/ResultCommon.h"
#include "common/database/DBClassifyLabelCommon.h"

std::string ClassifyAndLabelService::queryClassifyList(const int32_t isContainLabel) const
{
    const auto dbPtr = DBClassifyLabelCommon::getInstance();
    const auto vec = dbPtr->queryClassifyList(isContainLabel);
    return ResultCommon::generateResultJson(vec);
}

std::string ClassifyAndLabelService::queryLabelListByClassifyId(const int32_t uId, const int32_t classifyId) const
{
    const auto dbPtr = DBClassifyLabelCommon::getInstance();
    const auto vec = dbPtr->queryLabelListByClassifyId(uId, classifyId);
    return ResultCommon::generateResultJson(vec);
}

std::string ClassifyAndLabelService::addAClassify(int32_t uId, const std::string &className) const
{
    const auto dbPtr = DBClassifyLabelCommon::getInstance();
    const auto [first, second] = dbPtr->addAClassify(uId, className);
    if (first)
    {
        return ResultCommon::generateResultJson(SUCCESS);
    }
    return ResultCommon::generateResultJson(INSERT_FAIL, second);
}

std::string ClassifyAndLabelService::addALabel(int32_t uId, int32_t classId, const std::string &labelName) const
{
    const auto dbPtr = DBClassifyLabelCommon::getInstance();
    const auto [first, second] = dbPtr->addALabel(uId, classId, labelName);
    if (first)
    {
        return ResultCommon::generateResultJson(SUCCESS);
    }
    return ResultCommon::generateResultJson(INSERT_FAIL, second);
}
