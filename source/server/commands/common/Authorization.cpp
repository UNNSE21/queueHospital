//
// Created by Андрей Юрин on 13.03.2023.
//

#include "../../../../include/server/commands/common/Authorization.h"

void Authorization::Authorize(PSocket* socket) {
    std::cout << "Failed auth" << std::endl;
    p_socket_send(socket, "fail", 6, nullptr);
    p_socket_shutdown(socket, TRUE, TRUE, nullptr);
}
