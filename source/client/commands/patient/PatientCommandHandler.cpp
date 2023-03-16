//
// Created by Андрей Юрин on 14.03.2023.
//

#include <cstring>
#include "../../../../include/client/commands/patient/PatientCommandHandler.h"

void PatientCommandHandler::ProcessCommands(PSocket *socket) {
    std::cout << "auth as patient successful" << std::endl;
    char buf[500];
    std::string strs;
    while(strcmp(buf, "stop") != 0) {
        std::cin >> strs;
        if (strs == "reg") {
            p_socket_send(socket, "reg", 4, nullptr);
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
            p_socket_receive(socket, buf, 3, nullptr);
            if (strcmp("ok", buf) == 0) {
                std::cout << "Added successfully" << std::endl;
            } else {
                std::cout << "Cannot add :(" << std::endl;
            }
        } else if (strs == "vipreg") {

            p_socket_send(socket, "vipreg", 7, nullptr);
            std::cout << "Enter full name: ";
            std::string fullname;
            std::cin.ignore();
            std::getline(std::cin, fullname);
            std::cout << fullname.c_str() << std::endl;
            p_socket_send(socket, fullname.c_str(), fullname.length() + 1, nullptr);
            uint16_t stateNum = 0;
            do {
                std::cout << "Enter patient state (1 - 3, 3 - Critical): ";
                std::cin >> stateNum;
            } while (!(stateNum > 0 && stateNum <= 3));
            p_socket_send(socket, (char *) &stateNum, sizeof(stateNum), nullptr);

            uint32_t money = 0;
            std::cout << "Enter VIP patient balance: ";
            std::cin >> money;
            p_socket_send(socket, (char *) &money, sizeof(money), nullptr);
            p_socket_receive(socket, buf, 3, nullptr);
            if (strcmp("ok", buf) == 0) {
                std::cout << "Added successfully" << std::endl;
            } else {
                std::cout << "Cannot add :(" << std::endl;
            }
        } else if (strs == "s") {
            p_socket_send(socket, "stop", 5, nullptr);
            p_socket_receive(socket, buf, 5, nullptr);
        }
    }
}
