//
// Created by mikhail on 27.02.2023.
//

#ifndef QUEUEHOSPITAL_PATIENTREPOSITORY_H
#define QUEUEHOSPITAL_PATIENTREPOSITORY_H


#include <optional>
#include "common.h"
#include "queue.h"
class PatientRepository {
private:
    queue<Patient> _patients;
public:
    std::optional<Patient> getPatient() noexcept;
    bool addPatient(Patient patient);
};


#endif //QUEUEHOSPITAL_PATIENTREPOSITORY_H
