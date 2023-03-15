//
// Created by k17 on 12.03.2023.
//

#include "../../include/common/PatientDataConverter.h"
std::pair<char *, uint32_t> PatientDataConverter::Encode(const Patient &object) {
    uint32_t nameSize = object.getFullName().size();
    const char *nameData = object.getFullName().data();
    auto stateNum = static_cast<uint16_t>(object.getState());
    auto stateNumSize = sizeof(uint16_t);
    uint32_t msgSize = nameSize + stateNumSize;
    char *result = new char[msgSize + sizeof(msgSize)];
    std::copy(nameData, nameData + nameSize, result + sizeof(msgSize));
    *((uint32_t *)result ) = msgSize;
    *((uint16_t *)(result + sizeof(msgSize) + nameSize)) = stateNum;
    return {result, msgSize + sizeof(msgSize)};
}

std::optional<Patient> PatientDataConverter::Decode(const char *obj, size_t size) {
    size_t stateNumSize = sizeof(uint16_t);
    uint32_t realSize = *((uint32_t *) obj);
    obj+= sizeof(realSize);
    if (realSize <= stateNumSize){
        return {};
    }
    return Patient(std::string(obj, realSize - stateNumSize),
                   static_cast<const Patient::State>(*(uint16_t *) (obj + realSize - stateNumSize)));
}