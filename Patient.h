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
private:
    string _fullName;
    State _state;
public:
    Patient() = default;
    Patient(const string& _fullName, const State& _state);
    virtual ~Patient() = 0;
};


#endif //QUEUEHOSPITAL_PATIENT_H
