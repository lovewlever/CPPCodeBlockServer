//
// Created by catog on 2024/11/14.
//
#include <service/CodeBlockService.h>

#include "common/ResultCommon.h"
#include "common/database/DBCodeBlockCommon.h"

std::string CodeBlockService::addCodeBlock(const int32_t &uId,
                                           const std::string &title,
                                           const std::string &labelIds,
                                           const std::string &description,
                                           const std::string &content)
{
    std::stringstream strs{labelIds};
    std::string t;
    std::vector<int32_t> tokens;
    while (std::getline(strs, t, ','))
    {
        tokens.push_back(std::stoi(t));
    }

    const auto db = DBCodeBlockCommon::getInstance();
    const auto [fst, snd] = db->addCodeBlock(title, description, content, tokens, uId);
    return ResultCommon::generateResultJson(fst ? SUCCESS : ResultDataCode::INSERT_FAIL, snd);
}

std::string CodeBlockService::modifyCodeBlockById(const int32_t &uId,
                                                  const std::string &title,
                                                  const std::string &id,
                                                  const std::string &description,
                                                  const std::string &content)
{
    const auto codeId = std::stoi(id);
    const auto db = DBCodeBlockCommon::getInstance();
    const auto [fst, snd] = db->modifyCodeBlock(uId, title, codeId, description, content);
    return ResultCommon::generateResultJson(fst ? SUCCESS : ResultDataCode::INSERT_FAIL, snd);
}

std::string CodeBlockService::searchCodeBlock(const std::string &kw, const std::string &labelId, const std::string &classId,
    const int32_t &userId, const std::string &matchDesc, const std::string &matchContent)
{
    const auto db = DBCodeBlockCommon::getInstance();
    const auto res = db->searchCodeBlock(kw, std::stoi(labelId), std::stoi(classId), userId, std::stoi(matchDesc), std::stoi(matchContent));
    const nlohmann::json json = res;
    std::cout << json.dump() << std::endl;
    return ResultCommon::generateResultJson(res);
}

std::string CodeBlockService::codeBlockDeprecated(const int32_t &uId, const std::string &blockId, const std::string &deprecated,
    const std::string &deprecatedReason)
{
    const auto db = DBCodeBlockCommon::getInstance();
    const auto [fst, snd] = db->codeBlockDeprecated(uId, std::stoi(blockId), std::stoi(deprecated), deprecatedReason);
    return ResultCommon::generateResultJson(fst ? SUCCESS : ResultDataCode::INSERT_FAIL, snd);
}

std::string CodeBlockService::modifyVisibility(const int32_t &uId, const std::string &blockId,
    const std::string &visibility)
{
    const auto db = DBCodeBlockCommon::getInstance();
    const auto [fst, snd] = db->modifyVisibility(uId, std::stoi(blockId), std::stoi(visibility));
    return ResultCommon::generateResultJson(fst ? SUCCESS : ResultDataCode::INSERT_FAIL, snd);
}
