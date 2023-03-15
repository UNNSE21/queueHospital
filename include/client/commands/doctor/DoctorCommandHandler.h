//
// Created by Андрей Юрин on 14.03.2023.
//

#ifndef QUEUEHOSPITAL_DOCTORCOMMANDHANDLER_H
#define QUEUEHOSPITAL_DOCTORCOMMANDHANDLER_H


#include "../../../common/CommandHandler.h"

class DoctorCommandHandler: public CommandHandler{
public:
    void ProcessCommands(PSocket* socket) override;
};


#endif //QUEUEHOSPITAL_DOCTORCOMMANDHANDLER_H
