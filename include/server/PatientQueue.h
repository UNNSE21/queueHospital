//
// Created by Андрей Юрин on 18.03.2023.
//

#ifndef QUEUEHOSPITAL_PATIENTQUEUE_H
#define QUEUEHOSPITAL_PATIENTQUEUE_H

#include "../common/common.h"
#include "Queue.h"

class PatientQueue : public Queue<Patient*>
{
private:
    void PushHelp(Patient *const &elem, node* &next, node* &prev);
    void PushCriticalPatient(Patient *const &item);
    void PushVipPatient(Patient *const &item, VipPatient *vip);
    void PushPatient(Patient *const &item);

public:
    explicit PatientQueue(size_t maxSize) : Queue<Patient *>(maxSize) {};
    void Push(Patient *const &item) override;
};


#endif //QUEUEHOSPITAL_PATIENTQUEUE_H
