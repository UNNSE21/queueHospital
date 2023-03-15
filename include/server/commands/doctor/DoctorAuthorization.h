//
// Created by Андрей Юрин on 13.03.2023.
//

#ifndef QUEUEHOSPITAL_DOCTORAUTHORIZATION_H
#define QUEUEHOSPITAL_DOCTORAUTHORIZATION_H

#include <iostream>
#include "plibsys.h"
#include "../common/Authorization.h"

class DoctorAuthorization : public Authorization{
public:
    void Authorize(PSocket* socket) override;
};


#endif //QUEUEHOSPITAL_DOCTORAUTHORIZATION_H
