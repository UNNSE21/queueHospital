//
// Created by mikhail on 27.02.2023.
//

#ifndef QUEUEHOSPITAL_PATIENT_H
#define QUEUEHOSPITAL_PATIENT_H

#include <string>
using namespace std;

class Patient {
public:
    enum State {
        UNDEFINED = 0,
        PATIENT_NORMAL,
        PATIENT_WARNING,
        PATIENT_CRITICAL,
    };
protected:
    string _fullName;
    State _state;
public:
    Patient() = default;
    Patient(string  fullName, const State& state);
    virtual ~Patient() = default;
};


#endif //QUEUEHOSPITAL_PATIENT_H