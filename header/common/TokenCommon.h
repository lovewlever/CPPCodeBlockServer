//
// Created by catog on 2024/11/12.
//

#ifndef TOKENCOMMON_H
#define TOKENCOMMON_H
#define JWT_DISABLE_PICOJSON
#include <jwt-cpp/jwt.h>
#include <jwt-cpp/traits/nlohmann-json/traits.h>

#include <memory>
#include <string>

class TokenCommon
{
private:
    TokenCommon();


public:
    ~TokenCommon();

    std::string generateToken(int32_t userId);

    int32_t parseTokenGetUid(const std::string& token);

    static std::unique_ptr<TokenCommon> getInstance();
};

inline TokenCommon::TokenCommon()
{
}

inline TokenCommon::~TokenCommon()
{
}

inline std::string TokenCommon::generateToken(int32_t userId)
{
    auto now = std::chrono::system_clock::now();
    auto deadline = now + std::chrono::hours{30 * 24};
    auto token = jwt::create<jwt::traits::nlohmann_json>()
            .set_type("JWS")
            .set_issuer("auth0")
            .set_algorithm("secret")
            .set_expires_at(deadline)
            .set_payload_claim("userId", jwt::traits::nlohmann_json::serialize(nlohmann::json::parse(std::to_string(userId))))
            .sign(jwt::algorithm::hs256("secret"));
    return token;
}

inline int32_t TokenCommon::parseTokenGetUid(const std::string &token)
{
    auto payloadClaim = jwt::decode<jwt::traits::nlohmann_json>(token).get_payload_claim("userId");
    auto uId = std::stoi(payloadClaim.as_string());
    return uId;
}

inline std::unique_ptr<TokenCommon> TokenCommon::getInstance()
{
    return std::unique_ptr<TokenCommon>(new TokenCommon());
}

#endif //TOKENCOMMON_H
