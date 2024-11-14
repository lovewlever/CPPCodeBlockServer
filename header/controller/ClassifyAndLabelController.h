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
    ADD_METHOD_TO(ClassifyAndLabelController::queryClassifyList, "/classify/query-classify-list", drogon::Post);
    ADD_METHOD_TO(ClassifyAndLabelController::queryLabelListByClassId, "/label/query-label-by-class-id", drogon::Post);
    ADD_METHOD_TO(ClassifyAndLabelController::addAClassify, "/classify/add-classify", drogon::Post);
    ADD_METHOD_TO(ClassifyAndLabelController::addALabel, "/label/add-label", drogon::Post);
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
