#ifndef TCP_SERVER_HPP
#define TCP_SERVER_HPP

#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

#include "tcp_conn.hpp"

using boost::asio::ip::tcp;

class tcp_server
{
private:
    tcp::acceptor acceptor_;

    void start_accept();
    void handle_accept(tcp_connection::tcp_conn_ptr new_conn,
        const boost::system::error_code& error);

public:
    tcp_server(boost::asio::io_service& io_service)
        : acceptor_(io_service, tcp::endpoint(tcp::v4(),13)) { start_accept(); }

};

#endif