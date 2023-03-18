//
// Created by Андрей Юрин on 18.03.2023.
//

#ifndef QUEUEHOSPITAL_PATIENTREGISTRATION_H
#define QUEUEHOSPITAL_PATIENTREGISTRATION_H

#include <iostream>
#include "plibsys.h"

class PatientRegistration {
protected:
    void RegisterBasInfo(PSocket* socket, char* buf);
    void PrintStatus(char* buf);
public:
    virtual void Register(PSocket* socket, char* buf);
};


#endif //QUEUEHOSPITAL_PATIENTREGISTRATION_H
