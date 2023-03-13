//
// Created by k17 on 12.03.2023.
//

#ifndef QUEUEHOSPITAL_PATIENTDATACONVERTER_H
#define QUEUEHOSPITAL_PATIENTDATACONVERTER_H


#include "Patient.h"
#include "DataConverter.h"

class PatientDataConverter : public DataConverter<Patient>{
public:
    pair<char *, uint32_t> Encode(const Patient &object) override;
    optional<Patient> Decode(const char *obj, size_t size) override;
};


#endif //QUEUEHOSPITAL_PATIENTDATACONVERTER_H
