#include "../include/tcp_server.hpp"

void
tcp_server::start_accept()
{
    tcp_connection::tcp_conn_ptr 
        new_connection = tcp_connection::create(acceptor_.get_io_service());
    acceptor_.async_accept(new_connection->socket(),
        boost::bind(&tcp_server::handle_accept, this, new_connection,
            boost::asio::placeholders::error));
}

void
tcp_server::handle_accept(tcp_connection::tcp_conn_ptr new_conn,
    const boost::system::error_code& error)
{
    if (!error)
        new_conn->start();
    
    start_accept();
}
