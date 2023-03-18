//
// Created by Андрей Юрин on 18.03.2023.
//

#ifndef QUEUEHOSPITAL_VIPPATIENTREGISTRATION_H
#define QUEUEHOSPITAL_VIPPATIENTREGISTRATION_H


#include "PatientRegistration.h"

class VipPatientRegistration: public PatientRegistration{
public:
    void Register(PSocket *socket, char *in_buffer) override;
};


#endif //QUEUEHOSPITAL_VIPPATIENTREGISTRATION_H
