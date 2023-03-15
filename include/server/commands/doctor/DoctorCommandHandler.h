//
// Created by Андрей Юрин on 15.03.2023.
//

#ifndef QUEUEHOSPITAL_DOCTORCOMMANDHANDLER_H
#define QUEUEHOSPITAL_DOCTORCOMMANDHANDLER_H

#include "../../../common/CommandHandler.h"
#include "../../../../include/common/PatientDataConverter.h"
#include "../../../../include/server/PatientRepository.h"

class DoctorCommandHandler: public CommandHandler{
public:
    void ProcessCommands(PSocket* socket) override;
};


#endif //QUEUEHOSPITAL_DOCTORCOMMANDHANDLER_H
