//
// Created by k17 on 18.02.2023.
//

#ifndef QUEUEHOSPITAL_QUEUE_H
#define QUEUEHOSPITAL_QUEUE_H

#include <cstddef>
#include <cstdint>
#include <stdexcept>

template<class T>
class Queue {
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
    explicit Queue(size_t maxSize = 100);
    virtual void Push(const T& item);
    virtual T Pop();
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] bool isFull() const;
    void clear();
};

template<class T>
void Queue<T>::Push(const T &item) {
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
T Queue<T>::Pop() {
    if(isEmpty())
        throw std::out_of_range("Queue is empty");
    T elem = std::move(head->elem);
    node* headCopy = head;
    head = head->next;
    delete headCopy;
    queueSize--;
    if(isEmpty())
        tail = nullptr;
    return elem;
}

template<class T>
bool Queue<T>::isEmpty() const {
    return queueSize == 0;
}

template<class T>
bool Queue<T>::isFull() const {
    return queueSize == maxSize;
}

template<class T>
void Queue<T>::clear() {
    if(isEmpty())
        return;
    head->clearChild();
    delete head;
    head = nullptr;
    tail = nullptr;
    queueSize = 0;
}

template<class T>
Queue<T>::Queue(size_t maxSize) : maxSize(maxSize), queueSize(0) {
    head = nullptr;
    tail = nullptr;
}

#endif //QUEUEHOSPITAL_QUEUE_H
