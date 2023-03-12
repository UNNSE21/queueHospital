//
// Created by k17 on 12.03.2023.
//

#include "PatientDataConverter.h"

char *PatientDataConverter::Encode(const Patient &object) {
    size_t nameSize = object.getFullName().size();
    const char *nameData = object.getFullName().data();
    char *result = new char[nameSize + sizeof(Patient::State)];
    std::copy(nameData, nameData + nameSize, result);
    *((Patient::State *)result+nameSize) = object.getState();
    return result;
}

std::optional<Patient> PatientDataConverter::Decode(const char *obj, size_t size) {
    size_t enumSize = sizeof(Patient::State);
    if (size <= enumSize){
        return {};
    }
    return Patient(std::string(obj, size - enumSize), *(Patient::State *)(obj + size - enumSize));
}