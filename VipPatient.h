//
// Created by mikhail on 27.02.2023.
//

#ifndef QUEUEHOSPITAL_VIPPATIENT_H
#define QUEUEHOSPITAL_VIPPATIENT_H
#include "Patient.h"

class VipPatient : public Patient {
private:
    uint32_t money;
public:
    VipPatient() = default;
};


#endif //QUEUEHOSPITAL_VIPPATIENT_H
