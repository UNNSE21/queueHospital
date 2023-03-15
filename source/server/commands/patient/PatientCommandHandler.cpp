//
// Created by Андрей Юрин on 15.03.2023.
//

#include <cstring>
#include "../../../../include/server/commands/patient/PatientCommandHandler.h"

void PatientCommandHandler::ProcessCommands(PSocket *socket){
    char in_buffer[50];

    while(p_socket_receive(socket, in_buffer, 50, nullptr) > 0 && strcmp(in_buffer, "stop") != 0) {
        std::cout<< in_buffer << std::endl;
        //if(strcmp(in_buffer, "")){}
    }

    std::cout<< in_buffer << std::endl;
}