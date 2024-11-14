//
// Created by catog on 2024/11/13.
//

#ifndef LINKSSERVICE_H
#define LINKSSERVICE_H

#include <string>

class LinksService
{
public:
    LinksService() = default;
    ~LinksService() = default;
    std::string queryLinkList(int32_t uId);

    std::string addLink(int32_t uId, const std::string &name, const std::string &link);
    std::string deleteLinkById(int32_t uId, int32_t linkId);
    std::string modifyLink(int32_t uId, int32_t linkId, const std::string &name, const std::string &link);
};

#endif //LINKSSERVICE_H
