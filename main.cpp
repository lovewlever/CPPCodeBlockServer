#include <drogon/HttpAppFramework.h>

int main()
{
    std::cout << "start server 0.0.0.0:8001" << std::endl;
    drogon::app()
            .addListener("0.0.0.0", 8001)
            .setThreadNum(8)
            .run();
    return 0;
}
