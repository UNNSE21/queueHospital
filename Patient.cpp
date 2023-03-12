//
// Created by mikhail on 27.02.2023.
//

#include "Patient.h"

#include <utility>

Patient::Patient(string fullName, const Patient::State &state) : _fullName(std::move(fullName)), _state(state) {}
