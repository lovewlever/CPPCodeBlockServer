//
// Created by catog on 2024/11/13.
//

#ifndef LINKSCONTROLLER_H
#define LINKSCONTROLLER_H
#include <drogon/HttpController.h>
#include <service/LinksService.h>

class LinksController final: public drogon::HttpController<LinksController>
{
private:
    std::unique_ptr<LinksService> linkServicePtr{nullptr};
    public:
    LinksController();
    METHOD_LIST_BEGIN;
    ADD_METHOD_TO(LinksController::queryLinks, "/link/query_links", drogon::Post, "TokenFilter");
    ADD_METHOD_TO(LinksController::addLink, "/link/add-link", drogon::Post, "TokenFilter");
    ADD_METHOD_TO(LinksController::deleteLinkById, "/link/delete_link_by_id", drogon::Post, "TokenFilter");
    ADD_METHOD_TO(LinksController::modifyLink, "/link/modify_link", drogon::Post, "TokenFilter");
    METHOD_LIST_END;
    void queryLinks(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback);
    void addLink(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback);
    void deleteLinkById(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback);
    void modifyLink(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback);

};

#endif //LINKSCONTROLLER_H
