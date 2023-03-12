//
// Created by k17 on 25.02.2023.
//

#ifndef QUEUEHOSPITAL_SERVERCONNECTIONMANAGER_H
#define QUEUEHOSPITAL_SERVERCONNECTIONMANAGER_H
#include <plibsys.h>
#include "PatientRepository.h"

#define MAX_SERVER_THREAD_COUNT 6
class ServerConnectionManager {
private:
    PSocket *_socket;
    PSocketAddress *address;

    PUThread *threads[MAX_SERVER_THREAD_COUNT];

public:
    virtual ~ServerConnectionManager();
    void Listen();
    ServerConnectionManager();
private:
    static ppointer ConnectionThread(ppointer arg);
};


#endif //QUEUEHOSPITAL_SERVERCONNECTIONMANAGER_H
