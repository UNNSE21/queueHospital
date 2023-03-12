//
// Created by k17 on 12.03.2023.
//

#ifndef QUEUEHOSPITAL_SERVERCONNECTIONHANDLER_H
#define QUEUEHOSPITAL_SERVERCONNECTIONHANDLER_H

#include "common.h"
#include "PatientRepository.h"

class ServerConnectionHandler : ConnectionHandler {
public:
    int handleConnection() override;
private:
    PatientRepository * repo;
public:
    ServerConnectionHandler(PSocket *socket, PatientRepository *repo) : ConnectionHandler(socket), repo(repo) {}

};


#endif //QUEUEHOSPITAL_SERVERCONNECTIONHANDLER_H
