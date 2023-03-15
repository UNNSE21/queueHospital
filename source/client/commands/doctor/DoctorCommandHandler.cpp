//
// Created by Андрей Юрин on 14.03.2023.
//

#include <cstring>
#include "../../../../include/client/commands/doctor/DoctorCommandHandler.h"
#include "../../../../include/client/commands/doctor/ReceivingPatient.h"

void DoctorCommandHandler::ProcessCommands(PSocket* socket) {
    std::cout << "auth as doctor successful" << std::endl;
    int x;
    char buf[500];
    std::string strs;
    while(strcmp(buf, "stop") != 0) {
        std::cin >> strs;
        if(strs == "get"){
            auto patient = ReceivingPatient().get(socket);
            if(patient.has_value()){
                std::cout << "Name: " << patient.value().getFullName() << "\nState: " << static_cast <int> (patient.value().getState()) << std::endl;
            }
            else {
                std::cout << "No patients\n";
            }
        }
    }
}
