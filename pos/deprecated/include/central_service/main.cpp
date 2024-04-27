#include <iostream>
#include <vector>

#include "pos/include/common.h"
#include "pos/include/log.h"

#include "websocketpp/config/asio_no_tls.hpp"
#include "websocketpp/server.hpp"

int main(){
    server cs_server;

    try {
        // Set logging settings
        cs_server.set_access_channels(websocketpp::log::alevel::all);
        cs_server.clear_access_channels(websocketpp::log::alevel::frame_payload);

        // Initialize Asio
        cs_server.init_asio();

        // Register our message handler
        cs_server.set_message_handler(bind(&on_message,&cs_server,::_1,::_2));

        // Listen on port 9002
        cs_server.listen(9002);

        // Start the server accept loop
        cs_server.start_accept();

        // Start the ASIO io_service run loop
        cs_server.run();
    } catch (websocketpp::exception const & e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "other exception" << std::endl;
    }
}
