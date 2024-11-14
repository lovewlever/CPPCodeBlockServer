//
// Created by catog on 2024/11/13.
//
#include "service/LinksService.h"
#include "common/database/DBLinksCommon.h"
#include "common/ResultCommon.h"

std::string LinksService::queryLinkList(int32_t uId)
{
    const auto linksPtr = DBLinksCommon::getInstance()->queryLinkList(uId);
    return ResultCommon::generateResultJson(*linksPtr);
}

std::string LinksService::addLink(int32_t uId, const std::string &name, const std::string &link)
{
    if (name.empty() || link.empty())
    {
        return ResultCommon::generateResultJson(PARAMS_FAIL, "参数错误!!");
    }
    const auto dbPtr = DBLinksCommon::getInstance();
    if (dbPtr->isAlreadyExistsByLinkName(name))
    {
        return ResultCommon::generateResultJson(INSERT_FAIL, "该Link已存在!!");
    }

    if (const auto [fst, snd] = dbPtr->addALink(uId, name, link); fst)
    {
        return ResultCommon::generateResultJson(SUCCESS);
    } else
    {
        return ResultCommon::generateResultJson(INSERT_FAIL, snd);
    }
}

std::string LinksService::deleteLinkById(int32_t uId, int32_t linkId)
{
    const auto dbPtr = DBLinksCommon::getInstance();
    if (const auto [fst, snd] = dbPtr->deleteLinkById(uId, linkId); fst)
    {
        return ResultCommon::generateResultJson(SUCCESS);
    } else
    {
        return ResultCommon::generateResultJson(INSERT_FAIL, snd);
    }
}

std::string LinksService::modifyLink(int32_t uId, int32_t linkId, const std::string &name, const std::string &link)
{
    const auto dbPtr = DBLinksCommon::getInstance();
    if (const auto [fst, snd] = dbPtr->modifyLink(uId, linkId, name, link); fst)
    {
        return ResultCommon::generateResultJson(SUCCESS);
    } else
    {
        return ResultCommon::generateResultJson(INSERT_FAIL, snd);
    }

}
