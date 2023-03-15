//
// Created by k17 on 12.03.2023.
//

#include <cstring>
#include "../../include/server/ServerConnectionHandler.h"
#include "../../include/server/PatientAuthorization.h"
#include "../../include/server/DoctorAuthorization.h"


int ServerConnectionHandler::handleConnection() {
    int authDigit = 0;
    p_socket_receive(_socket, (pchar *) &authDigit, sizeof(authDigit), nullptr);

    switch (authDigit) {
        case 1:
            PatientAuthorization().Authorize(_socket);
            break;
        case 2:
            DoctorAuthorization().Authorize(_socket);
            break;
        default:
            Authorization().Authorize(_socket);
            return -1;
    }

    return 0;
}
