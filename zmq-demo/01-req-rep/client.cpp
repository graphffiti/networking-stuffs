
////Based on https://github.com/booksbyus/zguide/tree/master/examples/C%2B%2B
//
//  Hello World client in C++
//  Connects REQ socket to tcp://localhost:5555
//  Sends "Hello" to server, expects "World" back
//
#include <string>
#include <iostream>

#include <zmq.hpp>
#include <zmq_addon.hpp>



int main ()
{
    //  Prepare our context and socket
    zmq::context_t context;
    zmq::socket_t socket (context, zmq::socket_type::req);
 

    std::cout << "Connecting to hello world server..." << std::endl;
    socket.connect ("tcp://localhost:5555");

    //  Do 10 requests, waiting each time for a response
    for (int request_nbr = 0; request_nbr != 10; request_nbr++) {

        zmq::message_t request("Hi Server!");
        std::cout << "Sending message to server "  << "..." << std::endl;
        socket.send (request, zmq::send_flags::none);

        //  Get the reply.
        zmq::message_t reply;
        auto res = socket.recv (reply);
        std::cout << "Message recieved: "  << reply.to_string_view() << std::endl;
    }
    return 0;
}

