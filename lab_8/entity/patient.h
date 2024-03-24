//
// Created by david on 28.11.2023.
//

#ifndef LAB_8_PATIENT_H
#define LAB_8_PATIENT_H


#include <string>
#include <utility>

class Patient {
    std::string name;
    std::string lastName;
    int operationCount;
    int status;
    int illnessCount;

public:
    Patient(std::string name,
            std::string lastName,
            int operationCount,
            int status,
            int illnessCount) : name(std::move(name)), lastName(std::move(lastName)), operationCount(operationCount), status(status),
                                illnessCount(illnessCount) {}
};


#endif //LAB_8_PATIENT_H
