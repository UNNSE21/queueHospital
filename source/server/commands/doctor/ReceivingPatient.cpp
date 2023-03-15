//
// Created by Андрей Юрин on 15.03.2023.
//

#include "../../../../include/server/commands/doctor/ReceivingPatient.h"

void ReceivingPatient::get(PSocket *socket){
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