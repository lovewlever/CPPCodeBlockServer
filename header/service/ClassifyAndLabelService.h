//
// Created by catog on 2024/11/13.
//

#ifndef CLASSIFYANDLABELSERVICE_H
#define CLASSIFYANDLABELSERVICE_H
#include <string>
#include <utility>

class ClassifyAndLabelService
{
public:
    [[nodiscard]] std::string queryClassifyList(int32_t isContainLabel) const;

    [[nodiscard]] std::string queryLabelListByClassifyId(int32_t uId, int32_t classifyId) const;

    [[nodiscard]] std::string addAClassify(int32_t uId, const std::string &className) const;

    [[nodiscard]] std::string addALabel(int32_t uId, int32_t classId, const std::string &labelName) const;
};
#endif //CLASSIFYANDLABELSERVICE_H
