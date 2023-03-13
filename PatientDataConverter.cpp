//
// Created by k17 on 12.03.2023.
//

#include "PatientDataConverter.h"

std::pair<char *, uint32_t> PatientDataConverter::Encode(const Patient &object) {
    size_t nameSize = object.getFullName().size();
    const char *nameData = object.getFullName().data();
    uint32_t msgSize = nameSize + sizeof(Patient::State);
    char *result = new char[msgSize + sizeof(msgSize)];
    std::copy(nameData, nameData + nameSize, result + sizeof(msgSize));
    *((uint32_t *)result ) = msgSize;
    *((Patient::State *)result+nameSize) = object.getState();
    return {result, msgSize + sizeof(msgSize)};
}

std::optional<Patient> PatientDataConverter::Decode(const char *obj, size_t size) {
    size_t enumSize = sizeof(Patient::State);
    uint32_t realSize = *((uint32_t *) obj);
    obj+= sizeof(realSize);
    if (realSize <= enumSize){
        return {};
    }
    return Patient(std::string(obj, realSize - enumSize), *(Patient::State *)(obj + realSize - enumSize));
}