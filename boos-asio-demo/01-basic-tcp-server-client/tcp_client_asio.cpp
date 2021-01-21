#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;
using std::string;

int main()
{

    boost::asio::io_service io_service;
    //socket creation
    tcp::socket socket(io_service);
    //connection
    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 5555));

    // request/message from client
    const string msg = "Hello from Client!\n";

    boost::system::error_code error;
    int y = 0;
    while (true)
    {
        std::string x;
        std::cin >> x;
        boost::asio::write(socket, boost::asio::buffer(msg), error);
        if (!error)
        {
            cout << "Client sent hello message!" << endl;
        }
        else
        {
            cout << "send failed: " << error.message() << endl;
        }

        // getting response from server
        boost::asio::streambuf receive_buffer;
        boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
        if (error && error != boost::asio::error::eof)
        {
            cout << "receive failed: " << error.message() << endl;
        }
        else
        {
            const char *data = boost::asio::buffer_cast<const char *>(receive_buffer.data());
            cout << data << endl;
        }
        cout << "end: " << endl;
    }
    return 0;
}
