//
// Created by Андрей Юрин on 18.03.2023.
//

#ifndef QUEUEHOSPITAL_PATIENTREGISTRATION_H
#define QUEUEHOSPITAL_PATIENTREGISTRATION_H

#include <string>
#include "plibsys.h"
#include "../../../../include/server/PatientRepository.h"

class PatientRegistration {
protected:
    Patient* GetPatient(PSocket *socket, char* in_buffer);
    void TryAddPatientInRep(PSocket *socket, Patient *patient);

public:
    virtual void Register(PSocket *socket, char* in_buffer);
};


#endif //QUEUEHOSPITAL_PATIENTREGISTRATION_H
