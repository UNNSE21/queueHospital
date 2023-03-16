//
// Created by k17 on 18.02.2023.
//

#ifndef QUEUEHOSPITAL_QUEUE_H
#define QUEUEHOSPITAL_QUEUE_H

#include <cstddef>
#include <cstdint>
#include <stdexcept>

template<class T>
class queue {
protected:
    struct node {
        T elem;
        node* next;
        node* prev;
        void clearChild()
        {
            if(next)
            {
                next->clearChild();
                delete next;
                next = nullptr;
            }
        }
    };
    size_t queueSize;
    size_t maxSize;
    node* head;
    node* tail;
public:
    explicit queue(size_t maxSize = 100);
    virtual void Push(const T& item);
    virtual T Pop();
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] bool isFull() const;
    void clear();
};

template<class T>
void queue<T>::Push(const T &item) {
    if(isFull())
        throw std::out_of_range("Queue is full");
    if(tail == nullptr)
    {
        tail = new node {item, nullptr, nullptr};
        head = tail;
    }
    else {
        tail->next =  new node {item, nullptr, tail};
        tail = tail->next;
    }
    queueSize++;
}

template<class T>
T queue<T>::Pop() {
    if(isEmpty())
        throw std::out_of_range("Queue is empty");
    T elem = std::move(head->elem);
    node* headCopy = head;
    head = head->next;
    delete headCopy;
    queueSize--;
    return elem;
}

template<class T>
bool queue<T>::isEmpty() const {
    return queueSize == 0;
}

template<class T>
bool queue<T>::isFull() const {
    return queueSize == maxSize;
}

template<class T>
void queue<T>::clear() {
    if(isEmpty())
        return;
    head->clearChild();
    delete head;
    head = nullptr;
    tail = nullptr;
    queueSize = 0;
}

template<class T>
queue<T>::queue(size_t maxSize) : maxSize(maxSize), queueSize(0) {
    head = nullptr;
    tail = nullptr;
}


class patientQueue : public queue<Patient *>
{
public:

    explicit patientQueue(size_t maxSize) : queue<Patient *>(maxSize) {}

    void Push(Patient *const &item) override {
        if(isFull())
        {
            throw std::out_of_range("Queue is full");
        }
        std::cout << item->getFullName() << std::endl;
        if(item->getState() == Patient::State::PATIENT_CRITICAL)
        {
            node * newNode = new node {item, head, nullptr};
            if (head != nullptr)
                head->prev = newNode;
            head = newNode;
            queueSize++;
            return;
        }
        auto vip = dynamic_cast<VipPatient *> (item);
        std::cout << vip << std::endl;
        if(vip != nullptr)
        {
            auto cur = head;
            VipPatient *curVip;
            while(cur != nullptr)
            {
                curVip = dynamic_cast<VipPatient *>(cur->elem);
                if(cur->elem->getState() != Patient::State::PATIENT_CRITICAL && (curVip  == nullptr || curVip->getMoney() < vip->getMoney()))
                {
                    node *newNode = new node {item, cur, cur->prev};
                    if (cur->prev != nullptr)
                        cur->prev->next = newNode;
                    else
                        head = newNode;
                    cur->prev = newNode;
                    queueSize++;
                    break;
                }
                cur = cur->next;
            }
            if(cur == nullptr)
            {
                queue::Push(item);
            }
        }
        else
        {
            auto cur = head;
            VipPatient *curVip;
            while(cur != nullptr)
            {
                if(dynamic_cast<VipPatient *>(cur->elem) == nullptr
                && static_cast<uint16_t>(cur->elem->getState()) < static_cast<uint16_t>(item->getState()))
                {
                    node *newNode = new node {item, cur, cur->prev};
                    if (cur->prev != nullptr)
                        cur->prev->next = newNode;
                    else
                        head = newNode;
                    cur->prev = newNode;
                    queueSize++;
                    break;
                }
                cur = cur->next;
            }
            if(cur == nullptr)
            {
                queue::Push(item);
            }
        }
    }

};

#endif //QUEUEHOSPITAL_QUEUE_H
