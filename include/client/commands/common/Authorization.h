//
// Created by Андрей Юрин on 14.03.2023.
//

#ifndef QUEUEHOSPITAL_AUTHORIZATION_H
#define QUEUEHOSPITAL_AUTHORIZATION_H

#include <iostream>
#include "plibsys.h"

class Authorization {
public:
    char* authorize(PSocket *socket, char* authResult );
};


#endif //QUEUEHOSPITAL_AUTHORIZATION_H
