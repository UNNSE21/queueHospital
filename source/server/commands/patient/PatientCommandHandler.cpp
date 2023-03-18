//
// Created by Андрей Юрин on 15.03.2023.
//

#include <cstring>
#include "../../../../include/server/commands/patient/PatientCommandHandler.h"
#include "../../../../include/common/Patient.h"
#include "../../../../include/server/commands/patient/PatientRegistration.h"
#include "../../../../include/server/commands/patient/VipPatientRegistration.h"

void PatientCommandHandler::ProcessCommands(PSocket *socket){
    char in_buffer[250];

    while(p_socket_receive(socket, in_buffer, 50, nullptr) > 0 && strcmp(in_buffer, "stop") != 0) {
        std::cout<< in_buffer << std::endl;
        if(strcmp("reg", in_buffer) == 0){
            PatientRegistration().Register(socket, in_buffer);
        }
        else if(strcmp("vipreg", in_buffer) == 0){
            VipPatientRegistration().Register(socket, in_buffer);
        }
    }

    std::cout<< in_buffer << std::endl;
}

