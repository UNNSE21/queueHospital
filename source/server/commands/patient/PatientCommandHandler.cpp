//
// Created by Андрей Юрин on 15.03.2023.
//

#include <cstring>
#include "../../../../include/server/commands/patient/PatientCommandHandler.h"
#include "../../../../include/common/Patient.h"
#include "../../../../include/server/PatientRepository.h"

void PatientCommandHandler::ProcessCommands(PSocket *socket){
    char in_buffer[250];

    while(p_socket_receive(socket, in_buffer, 50, nullptr) > 0 && strcmp(in_buffer, "stop") != 0) {
        std::cout<< in_buffer << std::endl;
        if(strcmp("reg", in_buffer) == 0)
        {
            p_socket_receive(socket, in_buffer, 250, nullptr);
            std::string fullName = std::string(in_buffer);
            p_socket_receive(socket, in_buffer, sizeof(uint16_t), nullptr);
            auto state = static_cast<Patient::State>(*((uint16_t *)in_buffer));
            auto patient = new Patient{fullName, state};
            if(PatientRepository::getSharedObject()->addPatient(patient))
            {
                p_socket_send(socket, "ok", 3, nullptr);
            }
            else
            {
                p_socket_send(socket, "no", 3, nullptr);
            }
        }
        else if(strcmp("vipreg", in_buffer) == 0)
        {
            p_socket_receive(socket, in_buffer, 250, nullptr);
            std::string fullName = std::string(in_buffer);
            p_socket_receive(socket, in_buffer, sizeof(uint16_t), nullptr);
            auto state = static_cast<Patient::State>(*((uint16_t *)in_buffer));
            p_socket_receive(socket, in_buffer, sizeof(uint32_t), nullptr);
            auto money = static_cast<uint32_t>(*((uint32_t *) in_buffer));
            auto patient = new VipPatient{fullName, state, money};
            if(PatientRepository::getSharedObject()->addPatient(patient))
            {
                p_socket_send(socket, "ok", 3, nullptr);
            }
            else
            {
                p_socket_send(socket, "no", 3, nullptr);
            }
        }
    }

    std::cout<< in_buffer << std::endl;
}