//
// Created by Андрей Юрин on 13.03.2023.
//

#ifndef QUEUEHOSPITAL_PATIENTAUTHORIZATION_H
#define QUEUEHOSPITAL_PATIENTAUTHORIZATION_H

#include <iostream>
#include "plibsys.h"
#include "Authorization.h"

class PatientAuthorization : public Authorization{
public:
    void Authorize(PSocket* socket) override;
};

#endif //QUEUEHOSPITAL_PATIENTAUTHORIZATION_H
