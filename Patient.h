//
// Created by mikhail on 27.02.2023.
//

#ifndef QUEUEHOSPITAL_PATIENT_H
#define QUEUEHOSPITAL_PATIENT_H

#include <string>
using namespace std;

class Patient {
public:
    enum class State : uint16_t {
        UNDEFINED = 0,
        PATIENT_NORMAL,
        PATIENT_WARNING,
        PATIENT_CRITICAL,
    };
protected:
    string _fullName;
public:
    const string &getFullName() const;

    State getState() const;

protected:
    State _state;
public:
    Patient() = default;
    Patient(string  fullName, const State& state);
    virtual ~Patient() = default;
};


#endif //QUEUEHOSPITAL_PATIENT_H
