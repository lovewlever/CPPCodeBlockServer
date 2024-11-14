//
// Created by catog on 2024/11/14.
//
#include "controller/CodeBlockController.h"

#include "common/ResultCommon.h"
#include "common/StringCommon.h"
#include "common/TokenCommon.h"


CodeBlockController::CodeBlockController(): _servicePtr{std::make_unique<CodeBlockService>()}
{
}

void CodeBlockController::addCodeBlock(const drogon::HttpRequestPtr &req,
                                       std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
    const auto title = req->getParameter("title");
    const auto labelIds = req->getParameter("labelIds");
    const auto description = req->getParameter("description");
    const auto content = req->getParameter("content");
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    if (title.empty() || labelIds.empty() || description.empty() || content.empty())
    {
        const auto json = ResultCommon::generateResultJson(PARAMS_FAIL, "参数错误!!!");
        const auto resp = StringCommon::toHttpJsonResponse(json);
        callback(resp);
        return;
    }

    const auto resJson = _servicePtr->addCodeBlock(uId, title, labelIds, description, content);
    const auto resp = StringCommon::toHttpJsonResponse(resJson);
    callback(resp);
}

void CodeBlockController::modifyCodeBlock(const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
    const auto id = req->getParameter("id");
    const auto title = req->getParameter("title");
    const auto description = req->getParameter("description");
    const auto content = req->getParameter("content");
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    if (title.empty() || description.empty() || content.empty())
    {
        const auto json = ResultCommon::generateResultJson(PARAMS_FAIL, "参数错误!!!");
        const auto resp = StringCommon::toHttpJsonResponse(json);
        callback(resp);
        return;
    }
    const auto resJson = _servicePtr->modifyCodeBlockById(uId, title, id, description, content);
    const auto resp = StringCommon::toHttpJsonResponse(resJson);
    callback(resp);
}

void CodeBlockController::search(const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
    auto classId = req->getParameter("classId");
    auto labelId = req->getParameter("labelId");
    const auto kw = req->getParameter("kw");
    const auto matchTitle = req->getParameter("matchTitle");
    const auto matchDescription = req->getParameter("matchDescription");
    const auto matchContent = req->getParameter("matchContent");
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    if (classId.empty())
    {
        classId = "-1";
    }
    if (labelId.empty())
    {
        labelId = "-1";
    }
    const auto resJson = _servicePtr->searchCodeBlock(kw, labelId, classId, uId, matchDescription, matchContent);
    const auto resp = StringCommon::toHttpJsonResponse(resJson);
    callback(resp);
}
