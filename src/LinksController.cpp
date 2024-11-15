//
// Created by catog on 2024/11/13.
//
#include <controller/LinksController.h>

#include "common/StringCommon.h"
#include "common/TokenCommon.h"

LinksController::LinksController(): linkServicePtr{std::make_unique<LinksService>()}
{
}

void LinksController::queryLinks(const drogon::HttpRequestPtr &req,
                                 std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    const auto jsonList = linkServicePtr->queryLinkList(uId);
    const auto resp = StringCommon::toHttpJsonResponse(jsonList);
    callback(resp);
}

void LinksController::addLink(const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
    drogon::MultiPartParser parser{};
    parser.parse(req);
    const auto name = parser.getParameter<std::string>("name");
    const auto link = parser.getParameter<std::string>("link");
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    const auto sss = linkServicePtr->addLink(uId, name, link);
    callback(StringCommon::toHttpJsonResponse(sss));
}

void LinksController::deleteLinkById(const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
    drogon::MultiPartParser parser{};
    parser.parse(req);
    const auto linkId = parser.getParameter<std::string>("id");
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    const auto sss = linkServicePtr->deleteLinkById(uId, std::stoi(linkId));
    callback(StringCommon::toHttpJsonResponse(sss));
}

void LinksController::modifyLink(const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
    drogon::MultiPartParser parser{};
    parser.parse(req);
    const auto linkId = parser.getParameter<std::string>("id");
    const auto name = parser.getParameter<std::string>("name");
    const auto link = parser.getParameter<std::string>("link");
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    const auto sss = linkServicePtr->modifyLink(uId, std::stoi(linkId), name, link);
    callback(StringCommon::toHttpJsonResponse(sss));
}
