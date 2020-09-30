//STD Libs
#include <thread>
#include <chrono>
#include <iostream>

//Third-party Libs
#include <zmq.hpp>
//#include "/usr/include/zmq.hpp"
#include <boost/version.hpp>


int main()
{
    zmq::context_t ctx;
    zmq::socket_t socket(ctx, zmq::socket_type::stream);
    
    socket.bind("tcp://*:5555");
    //sock.send(zmq::str_buffer("Hello, world"), zmq::send_flags::dontwait);
    std::cout << "ZMQ_VERSION: "<< ZMQ_VERSION << std::endl;
    
    while (true) {
        zmq::message_t request;
        //zmq::recv_result_t request;

        //  Wait for next request from client
        auto res = socket.recv (request, zmq::recv_flags::none);

        std::cout << "Received Hello" << std::endl;

        //  Do some 'work'
    	std::this_thread::sleep_for(std::chrono::seconds(1));

        //  Send reply back to client
        //zmq::message_t reply (5);
        // (reply.data (), "World", 5);
        //.send (reply);
    
    }
    
    
    return 0;
    
}