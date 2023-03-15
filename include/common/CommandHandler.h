//
// Created by Андрей Юрин on 14.03.2023.
//

#ifndef QUEUEHOSPITAL_COMMANDHANDLER_H
#define QUEUEHOSPITAL_COMMANDHANDLER_H

#include <iostream>
#include "plibsys.h"

class CommandHandler {
    virtual void ProcessCommands(PSocket* socket) = 0;
};


#endif //QUEUEHOSPITAL_COMMANDHANDLER_H
