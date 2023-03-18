//
// Created by Андрей Юрин on 18.03.2023.
//

#include "../../include/server/PatientQueue.h"

void PatientQueue::PushHelp(Patient *const &elem, Queue<Patient *>::node *&next, Queue<Patient *>::node *&prev) {
    node* newNode = new node {elem, next, prev};
    if (prev != nullptr)
        prev->next = newNode;
    else
        head = newNode;
    prev = newNode;
    queueSize++;
}

void PatientQueue::PushCriticalPatient(Patient* const &item) {
    node * newNode = new node {item, head, nullptr};
    if (head != nullptr)
        head->prev = newNode;
    head = newNode;
    queueSize++;
}

void PatientQueue::PushVipPatient(Patient *const &item, VipPatient *vip) {
    auto cur = head;
    VipPatient *curVip;
    while(cur != nullptr){
        curVip = dynamic_cast<VipPatient *>(cur->elem);
        bool isCriticalPatient = cur->elem->getState() == Patient::State::PATIENT_CRITICAL;
        if(!isCriticalPatient && (curVip  == nullptr || curVip->getMoney() < vip->getMoney())){
            PushHelp(item, cur, cur->prev);
            break;
        }
        cur = cur->next;
    }
    if(cur == nullptr){
        Queue::Push(item);
    }
}

void PatientQueue::PushPatient(Patient *const &item) {
    auto cur = head;
    while(cur != nullptr)
    {
        bool isVipPatient = dynamic_cast<VipPatient *>(cur->elem) != nullptr;
        if(!isVipPatient && static_cast<uint16_t>(cur->elem->getState()) < static_cast<uint16_t>(item->getState())){
            PushHelp(item, cur, cur->prev);
            break;
        }
        cur = cur->next;
    }
    if(cur == nullptr){
        Queue::Push(item);
    }
}

void PatientQueue::Push(Patient *const &item) {
    if(isFull()){
        throw std::out_of_range("Queue is full");
    }

    if(item->getState() == Patient::State::PATIENT_CRITICAL){
        PushCriticalPatient(item);
        return;
    }
    auto vip = dynamic_cast<VipPatient *> (item);

    if(vip != nullptr){
        PushVipPatient(item, vip);
    }
    else{
        PushPatient(item);
    }
}



