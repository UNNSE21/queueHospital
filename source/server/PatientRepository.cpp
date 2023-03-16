//
// Created by mikhail on 27.02.2023.
//

#include "../../include/server/PatientRepository.h"

std::optional<Patient> PatientRepository::getPatient() noexcept {
    if(_patients.isEmpty())
    {
        return {};
    }
    auto patientPtr = _patients.Pop();
    auto patient = *patientPtr;
    delete patientPtr;
    return patient;
}

bool PatientRepository::addPatient(Patient *patient) {
    if(_patients.isFull())
        return false;
    _patients.Push(patient);
    return true;
}

PatientRepository::PatientRepository(): _patients(10) {
}

PatientRepository *PatientRepository::getSharedObject() {
    static PatientRepository repo;
    return &repo;
}

PatientRepository::~PatientRepository() {
    while(!_patients.isEmpty())
    {
        delete _patients.Pop();
    }
}
