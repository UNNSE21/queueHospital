//
// Created by Андрей Юрин on 14.03.2023.
//

#include "../../../../include/client/commands/doctor/ReceivingPatient.h"
#include "../../../../include/common/PatientDataConverter.h"

void ReceivingPatient::TryGet(PSocket *socket) {
    PatientDataConverter conv;
    char buf[500];
    p_socket_send(socket, "get", 4, nullptr);
    p_socket_receive(socket, buf, 500, nullptr);
    auto patient = conv.Decode(buf, 500);
    if (patient.has_value()) {
        std::cout << "Name: " << patient.value().getFullName() << "\nState: "
                  << static_cast <int> (patient.value().getState()) << std::endl;
    } else {
        std::cout << "No patients\n";
    }
}
