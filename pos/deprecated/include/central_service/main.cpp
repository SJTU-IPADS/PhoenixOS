/*
 * Copyright 2024 The PhoenixOS Authors. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
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
