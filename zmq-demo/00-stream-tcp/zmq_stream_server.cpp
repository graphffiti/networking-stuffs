
//STD Libs
#include <thread>
#include <chrono>
#include <iostream>

//Third-party Libs
#include <zmq.hpp>
#include <zmq_addon.hpp>
//#include "/usr/include/zmq.hpp"
#include <boost/version.hpp>


int main()
{
    zmq::context_t ctx;
    zmq::socket_t socket(ctx, zmq::socket_type::stream);
    
    socket.bind("tcp://*:5555");
    //sock.send(zmq::str_buffer("Hello, world"), zmq::send_flags::dontwait);
    std::cout << "ZMQ_VERSION: "<< ZMQ_VERSION << std::endl;
    std::string i = "asdasd";
    zmq::message_t request(i);
    
    
    std::vector<zmq::message_t> mp;
        auto res = zmq::recv_multipart(socket, std::back_inserter(mp));
        std::cout << "Connect:  ";
        for (const zmq::message_t& m : mp)
        {
            std::cout    << m.to_string_view();
        }
        std::cout <<"\n\n";
    
    while (true) {
        
        
        
        //zmq::recv_result_t request;

        //  Wait for next request from client
        //zmq::message_t request;
        //auto res = socket.recv (request, zmq::recv_flags::none);
        
        //zmq::multipart_t mp;
        std::cout << "LorA" << std::endl;
        std::vector<zmq::message_t> mp;
        auto res = zmq::recv_multipart(socket, std::back_inserter(mp));

        std::cout << "Received Hello: " << *res  << std::endl;
       
        
        std::cout << "Message:  ";
        for (const zmq::message_t& m : mp)
        {
            std::cout    << m.to_string_view();
        }
        
        
        std::vector<zmq::message_t> msgs;
        msgs.push_back(zmq::message_t(mp[0].to_string()));
        msgs.push_back(zmq::message_t("LORWIN B DELOS SANTOS\n"));
        //msgs.push_back(zmq::message_t(mp[0].to_string()));
        msgs.push_back(zmq::message_t());
        
        
        
        
        
    
        std::cout << std::endl;
        std::cout << "SENBDING" << std::endl;
       
        
        try {
            auto resp = send_multipart(socket, msgs, zmq::send_flags::none);
           //resp = socket.send(mp[0], zmq::send_flags::sndmore );
            //resp = socket.send(zmq::message_t(), zmq::send_flags::none );
        }
        catch (zmq::error_t e)
        {
          std::cout << e.what() << std::endl;   
        }
        //auto resp = socket.send(mp[0], zmq::send_flags::sndmore );
         
         //resp = socket.send(zmq::str_buffer("TESTLANG BOIN\n"), zmq::send_flags::sndmore );
        //resp = socket.send(mp[0], zmq::send_flags::sndmore );
        //resp = socket.send(zmq::message_t(), zmq::send_flags::none );
        //resp = socket.send(zmq::message_t(), zmq::send_flags::none );
         //resp = socket.send(zmq::message_t(), zmq::send_flags::none );
        // resp = socket.send(zmq::str_buffer("TESTLANG BOIN\n"), zmq::send_flags::sndmore );
         //resp = socket.send(mp[0], zmq::send_flags::sndmore );
         //resp = socket.send(zmq::message_t(), zmq::send_flags::none );
         //resp = socket.send(zmq::message_t(), zmq::send_flags::none );
        
        std::cout << "Lor" << std::endl;
        //  Do some 'work'
    	//std::this_thread::sleep_for(std::chrono::seconds(1));

        //  Send reply back to client
        //zmq::message_t reply (5);
        // (reply.data (), "World", 5);
        //.send (reply);
    
    }
    
    
    return 0;
}    
