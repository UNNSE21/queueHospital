//
// Created by Андрей Юрин on 18.03.2023.
//

#include "../../../../include/client/commands/patient/PatientRegistration.h"

void PatientRegistration::RegisterBasInfo(PSocket* socket, char* buf) {
    std::cout << "Enter full name: ";
    std::string fullname;
    std::cin.ignore();
    std::getline(std::cin, fullname);
    p_socket_send(socket, fullname.c_str(), fullname.length() + 1, nullptr);
    uint16_t stateNum = 0;
    do {
        std::cout << "Enter patient state (1 - 3, 3 - Critical): ";
        std::cin >> stateNum;
    } while (!(stateNum > 0 && stateNum <= 3));
    p_socket_send(socket, (char *) &stateNum, sizeof(uint16_t), nullptr);

}

void PatientRegistration::PrintStatus(char *buf) {
    if (strcmp("ok", buf) == 0) {
        std::cout << "Added successfully" << std::endl;
    } else {
        std::cout << "Cannot add :(" << std::endl;
    }
}

void PatientRegistration::Register(PSocket* socket, char* buf) {
    RegisterBasInfo(socket, buf);
    p_socket_receive(socket, buf, 3, nullptr);
    PrintStatus(buf);
}




