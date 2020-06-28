#ifndef TCP_CONN_HPP
#define TCP_CONN_HPP

#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string make_daytime_string();

class tcp_connection : public boost::enable_shared_from_this<tcp_connection>
{
private:
    tcp::socket socket_;
    std::string m_message;

    tcp_connection(boost::asio::io_service& io_service) : socket_(io_service) {}
    void  handle_write(const boost::system::error_code& error, 
        size_t bytes_transferred){}
    
public:

    typedef  boost::shared_ptr<tcp_connection> tcp_conn_ptr;

    static tcp_conn_ptr create(boost::asio::io_service& io_service);
    tcp::socket& socket() { return socket_; }
    void start();

};

#endif 