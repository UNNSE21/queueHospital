//
// Created by Андрей Юрин on 14.03.2023.
//

#include "../../../../include/client/commands/common/Authorization.h"

char* Authorization::authorize(PSocket *socket, char* authResult) {
    int authDigit = 1;
    std::cout << "Enter 1 to log in as a patient. Enter 2 to log in as a doctor: ";
    std::cin >> authDigit;
    p_socket_send(socket, (pchar *) &authDigit, sizeof(authDigit), nullptr);
    p_socket_receive(socket, authResult, 6, nullptr);
    return authResult;
}
