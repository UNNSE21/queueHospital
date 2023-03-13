//
// Created by k17 on 12.03.2023.
//

#include <cstring>
#include "../ServerConnectionHandler.h"

int ServerConnectionHandler::handleConnection() {
    int authDigit = 0;
    p_socket_receive(_socket, (pchar *) &authDigit, sizeof(authDigit), nullptr);
    if(authDigit == 1)
    {
        std::cout << "Auth as a patient" << std::endl;
        p_socket_send(_socket, "auth1", 6, nullptr);
        char in_buffer[50];
        while(p_socket_receive(_socket, in_buffer, 50, nullptr) > 0 && strcmp(in_buffer, "stop") != 0) {
            std::cout<< in_buffer << std::endl;
            //if(strcmp(in_buffer, "")){}
        }
        std::cout<< in_buffer << std::endl;
        p_socket_send(_socket, "stop", 5, nullptr);
        p_socket_shutdown(_socket, TRUE, TRUE, nullptr);
    }
    else if(authDigit == 2)
    {
        std::cout << "Auth as doctor" << std::endl;
        p_socket_send(_socket, "auth2", 6, nullptr);
        std::cout << p_socket_get_blocking(_socket) << std::endl;
        char in_buffer[50];
        while(p_socket_receive(_socket, in_buffer, 50, nullptr) > 0 && strcmp(in_buffer, "stop") != 0) {
            if(strcmp(in_buffer, "get") == 0)
            {
                std::cout<< "get" << std::endl;
                PatientDataConverter conv;
                auto p = PatientRepository::getSharedObject()->getPatient();
                if(p.has_value())
                {
                    auto c = conv.Encode(p.value());
                    p_socket_send(_socket, c.first, c.second, nullptr);
                }
                else {
                    uint32_t msgSize = 0;
                    p_socket_send(_socket, (char *)(&msgSize), sizeof(msgSize), nullptr);
                }

            }
            else {
                p_socket_send(_socket, "ok", 3, nullptr);
            }
        }
        std::cout<< in_buffer << std::endl;
        p_socket_send(_socket, "stop", 5, nullptr);
        p_socket_shutdown(_socket, TRUE, TRUE, nullptr);
    }
    else {
        std::cout << "Failed auth" << std::endl;
        p_socket_send(_socket, "fail", 6, nullptr);
        p_socket_shutdown(_socket, TRUE, TRUE, nullptr);
        return -1;
    }
    return 0;
}
