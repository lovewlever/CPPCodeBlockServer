//
// Created by catog on 2024/11/12.
//
#include <execution>
#include <controller/AccountController.h>
#include <common/TokenCommon.h>
#include <json/json.h>

AccountController::AccountController(): _accountService{std::make_unique<AccountService>()}
{
    std::cout << "AccountController::AccountController()" << std::endl;
}

AccountController::~AccountController()
{
    std::cout << "AccountController::~AccountController()" << std::endl;
}

void AccountController::signIn(const drogon::HttpRequestPtr &req,
                               std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
    drogon::MultiPartParser parser{};
    parser.parse(req);
    const auto account = parser.getParameter<std::string>("account");
    const auto pwd = parser.getParameter<std::string>("pwd");

    auto tokenCommonPtr = TokenCommon::getInstance();
    const auto str = _accountService->signIn(account, pwd);

    std::istringstream i{str};
    Json::Value root;
    Json::parseFromStream(Json::CharReaderBuilder{}, i, &root, nullptr);
    const auto resp = drogon::HttpResponse::newHttpJsonResponse(root);
    callback(resp);
}

void AccountController::signUp(const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
}

void AccountController::queryUserByUserId(const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
    const auto token = req->getHeader("token");
    const auto uId = TokenCommon::getInstance()->parseTokenGetUid(token);
    const auto uInfoJsonStr = _accountService->queryUserInfoByUId(uId);
    std::cout << "AccountController::queryUserByUserId: " << uId << std::endl;

    std::istringstream i{uInfoJsonStr};
    Json::Value root;
    Json::parseFromStream(Json::CharReaderBuilder{}, i, &root, nullptr);
    const auto resp = drogon::HttpResponse::newHttpJsonResponse(root);
    callback(resp);
}
