//
// Created by mikhail on 27.02.2023.
//

#include "PatientRepository.h"

std::optional<Patient> PatientRepository::getPatient() noexcept {
    if(_patients.isEmpty())
    {
        return {};
    }
    return _patients.Pop();
}

bool PatientRepository::addPatient(Patient patient) {
    if(_patients.isFull())
        return false;
    _patients.Push(patient);
    return true;
}
