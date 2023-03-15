//
// Created by Андрей Юрин on 13.03.2023.
//

#include "../../../../include/server/commands/patient/PatientAuthorization.h"
#include "../../../../include/server/commands/patient/PatientCommandHandler.h"


void PatientAuthorization::Authorize(PSocket *socket) {
    std::cout << "Auth as a patient" << std::endl;
    p_socket_send(socket, "auth1", 6, nullptr);
    PatientCommandHandler().ProcessCommands(socket);

    p_socket_send(socket, "stop", 5, nullptr);
    p_socket_shutdown(socket, TRUE, TRUE, nullptr);
}