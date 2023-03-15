//
// Created by k17 on 12.03.2023.
//

#include <stdlib.h>
#include "../../include/client/ClientConnectionHandler.h"
#include "../../include/client/commands/common/Authorization.h"
#include "../../include/client/commands/doctor/DoctorCommandHandler.h"
#include "../../include/client/commands/patient/PatientCommandHandler.h"

int ClientConnectionHandler::handleConnection() {
    if(!p_socket_is_connected(_socket))
        return -1;

    std::string authResult = Authorization().authorize(_socket);

    if(authResult == "auth1")
    {
        PatientCommandHandler().ProcessCommands(_socket);
        return 0;
    }
    else if (authResult == "auth2")
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
