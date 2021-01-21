#include <zmq.hpp>
#include <zmq_addon.hpp>

#include <thread>

int main ()
{
    zmq::context_t context;
    zmq::socket_t socket(context, zmq::socket_type::pub);
    socket.bind("tcp://*:5556");

    while (true)
    {

        zmq::message_t s_id_A("A");
        zmq::message_t dataA("Hello from A");

        //Broadcast to channel A
        socket.send(s_id_A, zmq::send_flags::sndmore);
        socket.send(dataA, zmq::send_flags::none);


        ////Broadcast to channel B
        zmq::message_t s_id_B("B");
        zmq::message_t dataB("Hello from B");

        socket.send(s_id_B, zmq::send_flags::sndmore);
        socket.send(dataB, zmq::send_flags::none);


        std::this_thread::sleep_for(std::chrono::seconds(3));

    }
    


    return 0;
}