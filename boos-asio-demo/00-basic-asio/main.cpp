#include <iostream>
#include <string>
#include <boost/asio.hpp>


namespace net = boost::asio;
using tcp = net::ip::tcp;

template <typename T>
std::string type_name();

int main()
{
    net::io_context context;

    net::steady_timer st(context,std::chrono::seconds(5));

    st.async_wait([&](const boost::system::error_code& ec){
        std::cout << "Hello" <<std::endl;
    });
std::cout << "world" <<std::endl;
    context.run();

    
    //std::this_thread::sleep_for(std::chrono::seconds(8));

}