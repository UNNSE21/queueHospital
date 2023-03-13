//
// Created by Андрей Юрин on 13.03.2023.
//

#include "../../include/server/DoctorAuthorization.h"


void DoctorAuthorization::Authorize(PSocket *socket) {
    std::cout << "Auth as doctor" << std::endl;
    p_socket_send(socket, "auth2", 6, nullptr);
    std::cout << p_socket_get_blocking(socket) << std::endl;
    char in_buffer[50];
    while(p_socket_receive(socket, in_buffer, 50, nullptr) > 0 && strcmp(in_buffer, "stop") != 0) {
        if(strcmp(in_buffer, "get") == 0)
        {
            std::cout<< "get" << std::endl;
            PatientDataConverter conv;
            auto p = PatientRepository::getSharedObject()->getPatient();
            if(p.has_value())
            {
                auto c = conv.Encode(p.value());
                p_socket_send(socket, c.first, c.second, nullptr);
            }
            else {
                uint32_t msgSize = 0;
                p_socket_send(socket, (char *)(&msgSize), sizeof(msgSize), nullptr);
            }

        }
        else {
            p_socket_send(socket, "ok", 3, nullptr);
        }
    }
    std::cout<< in_buffer << std::endl;
    p_socket_send(socket, "stop", 5, nullptr);
    p_socket_shutdown(socket, TRUE, TRUE, nullptr);

}
