//
// Created by k17 on 12.03.2023.
//

#ifndef QUEUEHOSPITAL_DATACONVERTER_H
#define QUEUEHOSPITAL_DATACONVERTER_H

#include <optional>
#include <utility>
#include <cstdint>

template<class T>
class DataConverter {
public:
    virtual std::pair<char *, uint32_t> Encode (const T& object) = 0;
    virtual std::optional<T> Decode(const char *obj, size_t size) = 0;
};


#endif //QUEUEHOSPITAL_DATACONVERTER_H
