//
// Created by Андрей Юрин on 13.03.2023.
//

#include "../../include/server/PatientAuthorization.h"

void PatientAuthorization::Authorize(PSocket *socket) {
    std::cout << "Auth as a patient" << std::endl;
    p_socket_send(socket, "auth1", 6, nullptr);
    char in_buffer[50];
    while(p_socket_receive(socket, in_buffer, 50, nullptr) > 0 && strcmp(in_buffer, "stop") != 0) {
        std::cout<< in_buffer << std::endl;
        //if(strcmp(in_buffer, "")){}
    }
    std::cout<< in_buffer << std::endl;
    p_socket_send(socket, "stop", 5, nullptr);
    p_socket_shutdown(socket, TRUE, TRUE, nullptr);
}