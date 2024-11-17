//
// Created by catog on 2024/11/13.
//

#ifndef RESULTCOMMON_H
#define RESULTCOMMON_H
#include <cstdint>
#include <string>
#include <google/protobuf/util/json_util.h>

#include "nlohmann/json.hpp"
#include "protobuf/UserInfo.pb.h"

enum ResultDataCode
{
    SUCCESS = 200,
    PASSWORD_FAIL = 1001,
    DATA_IS_EMPTY = 1002,
    PARAMS_FAIL = 1003,
    INSERT_FAIL = 1005,
    LoginExpired = 4089,
    DeleteFail = 1006

};

class ResultCommon
{
public:
    ResultCommon() = default;

    ~ResultCommon() = default;

    int32_t code{SUCCESS};
    std::string msg{"Success"};

    static std::string generateResultJson(int32_t code = SUCCESS,const std::string &msg = "Success", const nlohmann::json::array_t &data = "[]"_json);
    static std::string generateResultJson(const nlohmann::json::array_t &data = "[]"_json);

};

inline std::string ResultCommon::generateResultJson(int32_t code, const std::string &msg, const nlohmann::json::array_t &data)
{
    gq::ResultData result_data{};
    result_data.set_code(code);
    result_data.set_msg(msg);
    std::string jsonOut;
    auto a = google::protobuf::util::MessageToJsonString(result_data, &jsonOut);
    auto json = nlohmann::json::parse(jsonOut);
    json["data"] = data;
    return json.dump();
}

inline std::string ResultCommon::generateResultJson(const nlohmann::json::array_t &data)
{
    gq::ResultData result_data{};
    result_data.set_code(SUCCESS);
    result_data.set_msg("Success");
    std::string jsonOut;
    auto a = google::protobuf::util::MessageToJsonString(result_data, &jsonOut);
    auto json = nlohmann::json::parse(jsonOut);
    json["data"] = data;
    return json.dump();
}

#endif //RESULTCOMMON_H
