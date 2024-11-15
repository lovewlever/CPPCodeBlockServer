//
// Created by catog on 2024/11/13.
//

#ifndef CLASSIFYANDLABELCONTROLLER_H
#define CLASSIFYANDLABELCONTROLLER_H
#include <drogon/HttpController.h>
#include <service/ClassifyAndLabelService.h>

class ClassifyAndLabelController final : public drogon::HttpController<ClassifyAndLabelController>
{
private:
    std::unique_ptr<ClassifyAndLabelService> _service;
public:
    ClassifyAndLabelController();
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(ClassifyAndLabelController::queryClassifyList, "/api/classify/query-classify-list", drogon::Options, drogon::Post, "CorsMiddleware", "TokenFilter");
    ADD_METHOD_TO(ClassifyAndLabelController::queryLabelListByClassId, "/api/label/query-label-by-class-id", drogon::Options, drogon::Post, "CorsMiddleware", "TokenFilter");
    ADD_METHOD_TO(ClassifyAndLabelController::addAClassify, "/api/classify/add-classify", drogon::Options, drogon::Post, "CorsMiddleware", "TokenFilter");
    ADD_METHOD_TO(ClassifyAndLabelController::addALabel, "/api/label/add-label", drogon::Options, drogon::Post, "CorsMiddleware", "TokenFilter");
    METHOD_LIST_END

    void queryClassifyList(const drogon::HttpRequestPtr &req,
                           std::function<void(const drogon::HttpResponsePtr &)> &&callback) const;
    void queryLabelListByClassId(const drogon::HttpRequestPtr &req,
                           std::function<void(const drogon::HttpResponsePtr &)> &&callback) const;
    void addAClassify(const drogon::HttpRequestPtr &req,
                           std::function<void(const drogon::HttpResponsePtr &)> &&callback) const;
    void addALabel(const drogon::HttpRequestPtr &req,
                           std::function<void(const drogon::HttpResponsePtr &)> &&callback) const;
};
#endif //CLASSIFYANDLABELCONTROLLER_H
