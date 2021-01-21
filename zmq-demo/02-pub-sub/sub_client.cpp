#include <zmq.hpp>
#include <zmq_addon.hpp>

#include <iostream>

int main ()
{
    zmq::context_t context;
    zmq::socket_t socket(context, zmq::socket_type::sub);

    socket.connect("tcp://localhost:5556");
    socket.setsockopt(ZMQ_SUBSCRIBE, "B", 1);//if you want to subscribe to channel B, change to A if you want A


    while(true)
    {
        //Receive the first frame as the identity frame
        zmq::message_t env;
        auto rec = socket.recv(env);

        //Receive the data
        zmq::message_t data;
        rec = socket.recv(data);

        std::cout << env.to_string_view() << " : " << data.to_string_view() << std::endl;
    }



    return 0;
}