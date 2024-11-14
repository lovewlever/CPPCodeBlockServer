cmake_minimum_required(VERSION 3.29)

set(CMAKE_TOOLCHAIN_FILE E:/SDK/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake)

project(CPPCodeBlockServer)

set(CMAKE_CXX_STANDARD 23)
include_directories(header/)
find_package(Drogon CONFIG REQUIRED) #1.9.7
find_package(unofficial-mysql-connector-cpp CONFIG REQUIRED) # 8.0.32#2
find_package(Protobuf CONFIG REQUIRED) # 4.25.1#1
find_package(jwt-cpp CONFIG REQUIRED) # 0.7.0#1
find_package(nlohmann_json CONFIG REQUIRED) # 3.11.3#1

add_executable(CPPCodeBlockServer main.cpp
        header/controller/UnionController.h
        src/UnionController.cpp
        header/controller/AccountController.h
        src/AccountController.cpp
        header/service/AccountService.h
        src/AccountService.cpp
        header/common/database/DBCommon.h
        src/DBCommon.cpp

        header/common/protobuf/UserInfo.pb.cc
        header/common/protobuf/UserInfo.pb.h
        header/common/TokenCommon.h
        header/common/ResultCommon.h
        header/controller/LinksController.h
        src/LinksController.cpp
        header/service/LinksService.h
        header/common/database/DBLinksCommon.h
        header/common/StringCommon.h
        src/LinksService.cpp
        header/controller/ClassifyAndLabelController.h
        src/ClassifyAndLabelController.cpp
        header/service/ClassifyAndLabelService.h
        src/ClassifyAndLabelService.cpp
        header/common/database/DBClassifyLabelCommon.h
        header/controller/CodeBlockController.h
        src/CodeBlockController.cpp
        header/service/CodeBlockService.h
        src/CodeBlockService.cpp
        header/common/database/DBCodeBlockCommon.h
)

target_link_libraries(CPPCodeBlockServer PRIVATE Drogon::Drogon)
target_link_libraries(CPPCodeBlockServer PRIVATE unofficial::mysql-connector-cpp::connector)
target_link_libraries(CPPCodeBlockServer PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)
target_link_libraries(CPPCodeBlockServer PRIVATE jwt-cpp::jwt-cpp)
target_link_libraries(CPPCodeBlockServer PRIVATE nlohmann_json::nlohmann_json)
