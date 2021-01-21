//Based on https://github.com/booksbyus/zguide/tree/master/examples/C%2B%2B
//
//  Hello World server in C++
//  Binds REP socket to tcp://*:5555
//  Expects "Hello" from client, replies with "World"
//
#include <string>
#include <iostream>
#include <thread>

#include <zmq.hpp>



int main () {
    //  Prepare our context and socket
    zmq::context_t context;
    zmq::socket_t socket (context, zmq::socket_type::rep);
    socket.bind ("tcp://*:5555");

    while (true) {
        zmq::message_t request;

        //  Wait for next request from client
        auto res = socket.recv (request);
        std::cout << "Message recieved: " << request.to_string_view() << std::endl;

        //  Do some cool stuffs
    	std::this_thread::sleep_for(std::chrono::milliseconds(500));

        zmq::message_t reply("Hi, Client!");
        socket.send (reply, zmq::send_flags::none);
    }
    return 0;
}
