//
// Created by k17 on 12.03.2023.
//

#include <cstring>
#include <stdlib.h>
#include "../../include/client/ClientConnectionHandler.h"
#include "../../include/client/commands/common/Authorization.h"
#include "../../include/client/commands/doctor/DoctorCommandHandler.h"
#include "../../include/client/commands/patient/PatientCommandHandler.h"

int ClientConnectionHandler::handleConnection() {
    if(!p_socket_is_connected(_socket))
        return -1;
    char *authResult;
    authResult = Authorization().authorize(_socket, authResult);

    if(strcmp(authResult, "auth1") == 0)
    {
        PatientCommandHandler().ProcessCommands(_socket);
        return 0;
    }
    else if(strcmp(authResult, "auth2") == 0)
    {
        DoctorCommandHandler().ProcessCommands(_socket);
        return 0;
    }
    else
    {
        std::cout << "could not authorise. Exiting..." << std::endl;
        return -2;
    }
}

ClientConnectionHandler::ClientConnectionHandler(PSocket *socket) : ConnectionHandler(socket) {}
