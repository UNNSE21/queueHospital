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
private:
    struct node {
        T elem;
        node* next;
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
    void Push(const T& item);
    T Pop();
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] bool isFull() const;
    void clear();
};

template<class T>
void queue<T>::Push(const T &item) {
    if(isFull())
        throw std::out_of_range("Queue is full");
    tail->next = new node(item, nullptr);
    tail = tail->next;
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
    queueSize = 0;
}

template<class T>
queue<T>::queue(size_t maxSize) : maxSize(maxSize), queueSize(0) {
}


#endif //QUEUEHOSPITAL_QUEUE_H
