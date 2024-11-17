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
    drogon::MultiPartParser parser{};
    parser.parse(req);

    const auto title = parser.getParameter<std::string>("title");
    const auto labelIds = parser.getParameter<std::string>("labelIds");
    const auto description = parser.getParameter<std::string>("description");
    const auto content = parser.getParameter<std::string>("content");
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
    drogon::MultiPartParser parser{};
    parser.parse(req);

    const auto id = parser.getParameter<std::string>("id");
    const auto title = parser.getParameter<std::string>("title");
    const auto description = parser.getParameter<std::string>("description");
    const auto content = parser.getParameter<std::string>("content");
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
    drogon::MultiPartParser parser{};
    parser.parse(req);

    auto classId = parser.getParameter<std::string>("classId");
    auto labelId = parser.getParameter<std::string>("labelId");
    const auto kw = parser.getParameter<std::string>("kw");
    const auto matchTitle = parser.getParameter<std::string>("matchTitle");
    const auto matchDescription = parser.getParameter<std::string>("matchDescription");
    const auto matchContent = parser.getParameter<std::string>("matchContent");
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

void CodeBlockController::codeBlockDeprecated(const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
    drogon::MultiPartParser parser{};
    parser.parse(req);

    const auto id = parser.getParameter<std::string>("id");
    const auto deprecated = parser.getParameter<std::string>("deprecated");
    const auto deprecatedReason = parser.getParameter<std::string>("deprecatedReason");
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    const auto resJson = _servicePtr->codeBlockDeprecated(uId, id, deprecated, deprecatedReason);
    callback(StringCommon::toHttpJsonResponse(resJson));
}

void CodeBlockController::codeBlockDelete(const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
    drogon::MultiPartParser parser{};
    parser.parse(req);
    const auto blockId = parser.getParameter<int32_t>("id");
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    const auto resJson = _servicePtr->codeBlockDelete(uId, blockId);
    callback(StringCommon::toHttpJsonResponse(resJson));
}

void CodeBlockController::modifyVisibility(const drogon::HttpRequestPtr &req,
                                           std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
    drogon::MultiPartParser parser{};
    parser.parse(req);

    const auto id = parser.getParameter<std::string>("id");
    const auto visibility = parser.getParameter<std::string>("visibility");
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    const auto resJson = _servicePtr->modifyVisibility(uId, id, visibility);
    callback(StringCommon::toHttpJsonResponse(resJson));

}
