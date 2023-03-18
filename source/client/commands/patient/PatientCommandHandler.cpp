//
// Created by Андрей Юрин on 14.03.2023.
//

#include <cstring>
#include "../../../../include/client/commands/patient/PatientCommandHandler.h"
#include "../../../../include/client/commands/common/Stopping.h"
#include "../../../../include/client/commands/patient/PatientRegistration.h"
#include "../../../../include/client/commands/patient/VipPatientRegistration.h"

void PatientCommandHandler::ProcessCommands(PSocket *socket) {
    std::cout << "auth as patient successful" << std::endl;
    char buf[500];
    std::string strs;
    while(strcmp(buf, "stop") != 0) {
        std::cin >> strs;
        if (strs == "reg") {
            p_socket_send(socket, "reg", 4, nullptr);
            PatientRegistration().Register(socket, buf);
        } else if (strs == "vipreg") {
            p_socket_send(socket, "vipreg", 7, nullptr);
            VipPatientRegistration().Register(socket, buf);
        } else if (strs == "s") {
            Stopping().Stop(socket, buf);
        }
    }
}
