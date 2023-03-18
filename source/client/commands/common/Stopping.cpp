//
// Created by Андрей Юрин on 18.03.2023.
//

#include "../../../../include/client/commands/common/Stopping.h"

void Stopping::Stop(PSocket *socket, char* buf) {
    p_socket_send(socket, "stop", 5, nullptr);
    p_socket_receive(socket, buf, 5, nullptr);
}
