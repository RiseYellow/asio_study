#include <iostream>

#include "boost/asio.hpp"
#include "boost/thread.hpp"
void client_session(const std::shared_ptr<boost::asio::ip::tcp::socket>& server_socker)
{
    while (true) {
        char data[512];
        try
        {
            /* code */
            size_t len = server_socker->read_some(boost::asio::buffer(data));
            std::cout << "server get data : " << data << std::endl;
            if ( len > 0)
                boost::asio::write(*server_socker, boost::asio::buffer("ok", 2));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            std::cerr << "end thread" << std::endl;
            return;
        }
    }
    std::cerr << "end thread" << std::endl;
}
int main(int argc, char **argv)
{
    std::cout << "hello asio server" << std::endl;


    boost::asio::io_context server;

    typedef std::shared_ptr<boost::asio::ip::tcp::socket> asio_server_socket;

    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 4944);

    boost::asio::ip::tcp::acceptor acceptor(server, endpoint);

    while (true)
    {
        /* code */
        asio_server_socket server_socker(new boost::asio::ip::tcp::socket(server));
        try
        {
            /* code */
            acceptor.accept(*server_socker);
        }
        catch(const std::exception& e)
        {
            std::cerr << "accept error" << std::endl;
            std::cerr << e.what() << '\n';
        }
        // std::thread( std::bind(client_session, server_socker));
        boost::thread( boost::bind(client_session, server_socker));
    }
    
    return 0;
}

