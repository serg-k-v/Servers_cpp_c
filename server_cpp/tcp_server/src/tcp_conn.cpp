#include "../include/tcp_conn.hpp"

std::string
make_daytime_string()
{
    std::time_t now = std::time(0);

    return std::ctime(&now);
}

void
tcp_connection::start()
{
    boost::asio::async_write(socket_, boost::asio::buffer(m_message),
        boost::bind(&tcp_connection::handle_write, shared_from_this(),
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

tcp_connection::tcp_conn_ptr
tcp_connection::create(boost::asio::io_service& io_service)
{
    return tcp_conn_ptr(new tcp_connection(io_service));
}