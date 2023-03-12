//
// Created by k17 on 12.03.2023.
//

#ifndef QUEUEHOSPITAL_CONNECTIONHANDLER_H
#define QUEUEHOSPITAL_CONNECTIONHANDLER_H
#include "common.h"

class ConnectionHandler {
public:
    virtual int handle() = 0;
    explicit ConnectionHandler(PSocket *socket) : _socket(socket) {}
private:
    PSocket *_socket;
};


#endif //QUEUEHOSPITAL_CONNECTIONHANDLER_H
