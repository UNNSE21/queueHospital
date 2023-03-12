//
// Created by k17 on 12.03.2023.
//

#include <cstring>
#include <stdlib.h>
#include "ClientConnectionHandler.h"

int ClientConnectionHandler::handleConnection() {
    if(!p_socket_is_connected(_socket))
        return -1;
    int authDigit = 1;
    std::cout << "Enter 1 to log in as a patient. Enter 2 to log in as a doctor: ";
    std::cin >> authDigit;
    p_socket_send(_socket, (pchar *) &authDigit, sizeof(authDigit), nullptr);
    char authResult[6];
    p_socket_receive(_socket, authResult, 6, nullptr);
    if(strcmp(authResult, "auth1") == 0)
    {
        std::cout << "auth as patient successful" << std::endl;
        return 0;
    }
    else if(strcmp(authResult, "auth2") == 0)
    {
        std::cout << "auth as doctor successful" << std::endl;
        int x;
        char buf[50];
        std::string strs;
        while(strcmp(buf, "stop") != 0) {
            std::cin >> strs;
            if(strs == "n"){
                std::cin >> x;
                p_uthread_sleep(x);
                auto a = std::to_string(x);
                p_socket_send(_socket, a.c_str(), a.length(), nullptr);
            }
            else if(strs == "s")
            {
                p_socket_send(_socket, "stop", 5, nullptr);
            }
            else
                continue;
            p_socket_receive(_socket, buf, 50, nullptr);
        }
        return 0;
    }
    else
    {
        std::cout << "could not authorise. Exiting..." << std::endl;
        return -2;
    }
}

ClientConnectionHandler::ClientConnectionHandler(PSocket *socket) : ConnectionHandler(socket) {}
