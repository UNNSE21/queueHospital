//
// Created by Андрей Юрин on 18.03.2023.
//

#include "../../../../include/client/commands/patient/VipPatientRegistration.h"

void VipPatientRegistration::Register(PSocket *socket, char *buf) {
    RegisterBasInfo(socket, buf);

    uint32_t money = 0;
    std::cout << "Enter VIP patient balance: ";
    std::cin >> money;
    p_socket_send(socket, (char *) &money, sizeof(money), nullptr);
    p_socket_receive(socket, buf, 3, nullptr);

    PrintStatus(buf);
}
