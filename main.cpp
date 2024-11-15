#include <drogon/HttpAppFramework.h>

#include "common/filter/CorsMiddleware.h"

int main()
{
    std::cout << "start server 127.0.0.1:8001" << std::endl;
    drogon::app()
            .addListener("127.0.0.1", 8001)
            .setThreadNum(8)
            .run();
    return 0;
}
