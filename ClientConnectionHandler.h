//
// Created by k17 on 12.03.2023.
//

#ifndef QUEUEHOSPITAL_CLIENTCONNECTIONHANDLER_H
#define QUEUEHOSPITAL_CLIENTCONNECTIONHANDLER_H

#include "common.h"

class ClientConnectionHandler : public ConnectionHandler {
public:
    ClientConnectionHandler(PSocket *socket);

    int handleConnection() override;
};


#endif //QUEUEHOSPITAL_CLIENTCONNECTIONHANDLER_H
