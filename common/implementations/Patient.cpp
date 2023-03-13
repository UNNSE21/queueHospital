//
// Created by mikhail on 27.02.2023.
//

#include "../Patient.h"

#include <utility>

Patient::Patient(string fullName, const Patient::State &state) : _fullName(std::move(fullName)), _state(state) {}

const string &Patient::getFullName() const {
    return _fullName;
}

Patient::State Patient::getState() const {
    return _state;
}
