//
// Created by Андрей Юрин on 15.03.2023.
//

#ifndef QUEUEHOSPITAL_PATIENTCOMMANDHANDLER_H
#define QUEUEHOSPITAL_PATIENTCOMMANDHANDLER_H

#include "../../../common/CommandHandler.h"

class PatientCommandHandler: public CommandHandler {
public:
    void ProcessCommands(PSocket *socket) override;
};


#endif //QUEUEHOSPITAL_PATIENTCOMMANDHANDLER_H
