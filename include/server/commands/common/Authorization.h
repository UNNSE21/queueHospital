//
// Created by Андрей Юрин on 13.03.2023.
//

#ifndef QUEUEHOSPITAL_AUTHORIZATION_H
#define QUEUEHOSPITAL_AUTHORIZATION_H

#include <iostream>
#include "plibsys.h"

class Authorization {
public:
    virtual void Authorize(PSocket* socket);

};

#endif //QUEUEHOSPITAL_AUTHORIZATION_H
