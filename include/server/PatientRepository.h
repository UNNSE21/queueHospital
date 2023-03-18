//
// Created by mikhail on 27.02.2023.
//

#ifndef QUEUEHOSPITAL_PATIENTREPOSITORY_H
#define QUEUEHOSPITAL_PATIENTREPOSITORY_H


#include <optional>
#include "../common/common.h"
#include "PatientQueue.h"

class PatientRepository {
private:
    PatientQueue _patients;
public:
    std::optional<Patient> getPatient() noexcept;
    bool addPatient(Patient *patient);
    static PatientRepository *getSharedObject();
    ~PatientRepository();
private:
    PatientRepository();
};


#endif //QUEUEHOSPITAL_PATIENTREPOSITORY_H
