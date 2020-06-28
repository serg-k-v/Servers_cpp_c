#include "tcp_server/include/tcp_server.hpp"

int main(int argc, char const *argv[])
{
    try
    {
        boost::asio::io_service io_service;
        tcp_server server(io_service);

        io_service.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
