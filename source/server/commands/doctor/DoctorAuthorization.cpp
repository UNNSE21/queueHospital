//
// Created by Андрей Юрин on 13.03.2023.
//

#include "../../../../include/server/commands/doctor/DoctorAuthorization.h"
#include "../../../../include/server/commands/doctor/DoctorCommandHandler.h"


void DoctorAuthorization::Authorize(PSocket *socket) {
    std::cout << "Auth as doctor" << std::endl;
    p_socket_send(socket, "auth2", 6, nullptr);
    std::cout << p_socket_get_blocking(socket) << std::endl;
    DoctorCommandHandler().ProcessCommands(socket);

    p_socket_send(socket, "stop", 5, nullptr);
    p_socket_shutdown(socket, TRUE, TRUE, nullptr);

}
