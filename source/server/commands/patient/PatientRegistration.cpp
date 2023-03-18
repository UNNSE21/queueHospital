//
// Created by Андрей Юрин on 18.03.2023.
//

#include "../../../../include/server/commands/patient/PatientRegistration.h"


Patient* PatientRegistration::GetPatient(PSocket *socket, char* in_buffer) {
    p_socket_receive(socket, in_buffer, 250, nullptr);
    std::string fullName = std::string(in_buffer);
    p_socket_receive(socket, in_buffer, sizeof(uint16_t), nullptr);
    auto state = static_cast<Patient::State>(*((uint16_t *)in_buffer));
    return new Patient{fullName, state};
}

void PatientRegistration::TryAddPatientInRep(PSocket *socket, Patient *patient) {
    if(PatientRepository::getSharedObject()->addPatient(patient)) {
        p_socket_send(socket, "ok", 3, nullptr);
    }
    else{
        p_socket_send(socket, "no", 3, nullptr);
        delete patient;
    }
}

void PatientRegistration::Register(PSocket *socket, char* in_buffer) {
    auto patient = GetPatient(socket, in_buffer);
    TryAddPatientInRep(socket, patient);
}

