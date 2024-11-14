//
// Created by catog on 2024/11/14.
//

#ifndef CODEBLOCKSERVICE_H
#define CODEBLOCKSERVICE_H
#include <string>
#include <sstream>
#include <string>
#include <vector>

class CodeBlockService
{
public:
    std::string addCodeBlock(const int32_t &uId, const std::string &title, const std::string &labelIds,
                             const std::string &description, const std::string &content);

    std::string modifyCodeBlockById(const int32_t &uId, const std::string &title, const std::string &id,
                                    const std::string &description, const std::string &content);

    std::string searchCodeBlock(const std::string &kw,
                                const std::string &labelId,
                                const std::string &classId,
                                const int32_t &userId,
                                const std::string &matchDesc,
                                const std::string &matchContent);

    //std::string searchCodeBlock();
};
#endif //CODEBLOCKSERVICE_H
