//
// Created by Андрей Юрин on 18.03.2023.
//

#include "../../../../include/server/commands/patient/VipPatientRegistration.h"

void VipPatientRegistration::Register(PSocket *socket, char *in_buffer) {
    auto patient = GetPatient(socket, in_buffer);
    p_socket_receive(socket, in_buffer, sizeof(uint32_t), nullptr);
    auto money = static_cast<uint32_t>(*((uint32_t *) in_buffer));
    auto vipPatient = new VipPatient{patient->getFullName(), patient->getState(), money};
    delete patient;
    TryAddPatientInRep(socket, vipPatient);
}
