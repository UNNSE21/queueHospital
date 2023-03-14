//
// Created by Андрей Юрин on 14.03.2023.
//

#ifndef QUEUEHOSPITAL_RECEIVINGPATIENT_H
#define QUEUEHOSPITAL_RECEIVINGPATIENT_H


#include <iostream>
#include <optional>
#include "plibsys.h"
#include "../../../common/Patient.h"

class ReceivingPatient {
public:
    optional<Patient>  get(PSocket *socket);
};


#endif //QUEUEHOSPITAL_RECEIVINGPATIENT_H
