//
// Created by catog on 2024/11/14.
//

#ifndef CODEBLOCKCONTROLLER_H
#define CODEBLOCKCONTROLLER_H
#include <drogon/HttpController.h>
#include <service/CodeBlockService.h>

class CodeBlockController final : public drogon::HttpController<CodeBlockController>
{
    std::unique_ptr<CodeBlockService> _servicePtr;
public:
    CodeBlockController();
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(CodeBlockController::addCodeBlock, "/codeblock/add-codeblock", drogon::Post);
    ADD_METHOD_TO(CodeBlockController::modifyCodeBlock, "/codeblock/modify-codeblock", drogon::Post);
    ADD_METHOD_TO(CodeBlockController::search, "/codeblock/search", drogon::Post);
    // 查询已删除的CodeBlock
    //ADD_METHOD_TO(CodeBlockController::queryMineDeleteCB, "/user/query-mine-delete-cb", drogon::Post);
    // 查询私有的CodeBlock
    //ADD_METHOD_TO(CodeBlockController::queryMinePrivateCB, "/user/query-mine-private-cb", drogon::Post);
    // 代码块标记过时
    //ADD_METHOD_TO(CodeBlockController::codeBlockDeprecated, "/codeblock/modify-deprecated", drogon::Post);
    //ADD_METHOD_TO(CodeBlockController::codeBlockDelete, "/codeblock/modify-delete", drogon::Post);
    // 彻底删除代码块
    //ADD_METHOD_TO(CodeBlockController::codeBlockRemoveCompletely, "/codeblock/remove-completely", drogon::Post);
    // 私有或公开代码
    //ADD_METHOD_TO(CodeBlockController::modifyVisibility, "/codeblock/modify-visibility", drogon::Post);
    METHOD_LIST_END

    void addCodeBlock(const drogon::HttpRequestPtr &req,std::function<void(const drogon::HttpResponsePtr &)> &&callback);
    void modifyCodeBlock(const drogon::HttpRequestPtr &req,std::function<void(const drogon::HttpResponsePtr &)> &&callback);
    void search(const drogon::HttpRequestPtr &req,std::function<void(const drogon::HttpResponsePtr &)> &&callback);

    //void queryMineDeleteCB(const drogon::HttpRequestPtr &req,std::function<void(const drogon::HttpResponsePtr &)> &&callback);
    //void queryMinePrivateCB(const drogon::HttpRequestPtr &req,std::function<void(const drogon::HttpResponsePtr &)> &&callback);
    //void codeBlockDeprecated(const drogon::HttpRequestPtr &req,std::function<void(const drogon::HttpResponsePtr &)> &&callback);

    //void codeBlockDelete(const drogon::HttpRequestPtr &req,std::function<void(const drogon::HttpResponsePtr &)> &&callback);
    //void codeBlockRemoveCompletely(const drogon::HttpRequestPtr &req,std::function<void(const drogon::HttpResponsePtr &)> &&callback);
    //modifyVisibility(const drogon::HttpRequestPtr &req,std::function<void(const drogon::HttpResponsePtr &)> &&callback);
};
#endif //CODEBLOCKCONTROLLER_H