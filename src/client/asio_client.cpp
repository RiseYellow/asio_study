#include <iostream>
#include <memory>

#include "boost/asio.hpp"

int main(int argc, char **argv)
{
    std::cout << "hello asio client" << std::endl;

    boost::asio::io_context client;

    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 4944);

    std::shared_ptr<boost::asio::ip::tcp::socket> client_socket(new boost::asio::ip::tcp::socket(client));

    try
    {
        /* code */
        client_socket->connect(endpoint);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
    

    client_socket->send(boost::asio::buffer("RiseYellow"));

    char data[256];
    client_socket->receive(boost::asio::buffer(data));
    std::cout << "get server reply data : " << data << std::endl;


    client_socket->send(boost::asio::buffer("RiseYellow2"));

    client_socket->receive(boost::asio::buffer(data));
    std::cout << "get server reply data : " << data << std::endl;

    client_socket->close();
    return 0;
}
