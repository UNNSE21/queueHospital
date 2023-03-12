//
// Created by k17 on 12.03.2023.
//

#ifndef QUEUEHOSPITAL_SERVERCONNECTIONHANDLER_H
#define QUEUEHOSPITAL_SERVERCONNECTIONHANDLER_H

#include "common.h"
#include "PatientRepository.h"

class ServerConnectionHandler : public ConnectionHandler {
public:
    int handleConnection() override;
    explicit ServerConnectionHandler(PSocket *socket) : ConnectionHandler(socket) {}

};


#endif //QUEUEHOSPITAL_SERVERCONNECTIONHANDLER_H
