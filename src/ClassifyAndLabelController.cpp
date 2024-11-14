//
// Created by catog on 2024/11/13.
//
#include "controller/ClassifyAndLabelController.h"

#include "common/ResultCommon.h"
#include "common/StringCommon.h"
#include "common/TokenCommon.h"


ClassifyAndLabelController::ClassifyAndLabelController(): _service{std::make_unique<ClassifyAndLabelService>()}
{
}

void ClassifyAndLabelController::queryClassifyList(const drogon::HttpRequestPtr &req,
                                                   std::function<void(const drogon::HttpResponsePtr &)> &&callback) const
{
    const auto isContainLabel = req->getParameter("isContainLabel");
    int32_t isContL = 0;
    if (isContainLabel == "1")
    {
        isContL = 1;
    }
    const auto resultJson = _service->queryClassifyList(isContL);
    const auto resp = StringCommon::toHttpJsonResponse(resultJson);
    callback(resp);
}

void ClassifyAndLabelController::queryLabelListByClassId(const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback) const
{

    const auto classId = req->getParameter("classId");
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    const auto resultJson = _service->queryLabelListByClassifyId(uId, std::stoi(classId));
    const auto resp = StringCommon::toHttpJsonResponse(resultJson);
    callback(resp);
}

void ClassifyAndLabelController::addAClassify(const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback) const
{
    const auto className = req->getParameter("name");
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    const auto res = _service->addAClassify(uId, className);
    callback(StringCommon::toHttpJsonResponse(res));
}

void ClassifyAndLabelController::addALabel(const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback) const
{
    const auto classId = req->getParameter("classId");
    const auto labelName = req->getParameter("labelName");
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    const auto res = _service->addALabel(uId, std::stoi(classId), labelName);
    callback(StringCommon::toHttpJsonResponse(res));
}
