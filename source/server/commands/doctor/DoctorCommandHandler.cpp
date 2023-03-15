//
// Created by Андрей Юрин on 15.03.2023.
//

#include "../../../../include/server/commands/doctor/DoctorCommandHandler.h"
#include "../../../../include/server/commands/doctor/ReceivingPatient.h"


void DoctorCommandHandler::ProcessCommands(PSocket* socket) {
    char in_buffer[50];
    while(p_socket_receive(socket, in_buffer, 50, nullptr) > 0 && strcmp(in_buffer, "stop") != 0) {
        if(strcmp(in_buffer, "get") == 0){
            ReceivingPatient().get(socket);
        }
        else {
            p_socket_send(socket, "ok", 3, nullptr);
        }
    }
    std::cout<< in_buffer << std::endl;
}