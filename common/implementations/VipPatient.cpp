//
// Created by mikhail on 27.02.2023.
//

#include "../VipPatient.h"

VipPatient::VipPatient(const string &fullName, const Patient::State &state, uint32_t money) : Patient(fullName, state),
                                                                                              money(money) {}
