//
// Created by Андрей Юрин on 15.03.2023.
//

#ifndef QUEUEHOSPITAL_RECEIVINGPATIENT_H
#define QUEUEHOSPITAL_RECEIVINGPATIENT_H

#include <iostream>
#include "plibsys.h"
#include "../../../common/PatientDataConverter.h"
#include "../../PatientRepository.h"


class ReceivingPatient {
public:
    void get(PSocket* socket);
};


#endif //QUEUEHOSPITAL_RECEIVINGPATIENT_H
