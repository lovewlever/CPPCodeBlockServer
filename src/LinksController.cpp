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
    const auto name = req->getParameter("name");
    const auto link = req->getParameter("link");
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    const auto sss = linkServicePtr->addLink(uId, name, link);
    callback(StringCommon::toHttpJsonResponse(sss));
}

void LinksController::deleteLinkById(const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
    const auto linkId = req->getParameter("id");
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    const auto sss = linkServicePtr->deleteLinkById(uId, std::stoi(linkId));
    callback(StringCommon::toHttpJsonResponse(sss));
}

void LinksController::modifyLink(const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
    const auto linkId = req->getParameter("id");
    const auto name = req->getParameter("name");
    const auto link = req->getParameter("link");
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    const auto sss = linkServicePtr->modifyLink(uId, std::stoi(linkId), name, link);
    callback(StringCommon::toHttpJsonResponse(sss));
}
