//
// Created by Андрей Юрин on 14.03.2023.
//

#include <cstring>
#include "../../../../include/client/commands/doctor/DoctorCommandHandler.h"
#include "../../../../include/client/commands/doctor/ReceivingPatient.h"
#include "../../../../include/client/commands/common/Stopping.h"

void DoctorCommandHandler::ProcessCommands(PSocket* socket) {
    std::cout << "auth as doctor successful" << std::endl;
    char buf[500];
    std::string strs;
    while(strcmp(buf, "stop") != 0) {
        std::cin >> strs;
        if (strs == "get") {
            ReceivingPatient().TryGet(socket);
        }
        else if(strs == "s")
        {
            Stopping().Stop(socket, buf);
        }
    }
}
