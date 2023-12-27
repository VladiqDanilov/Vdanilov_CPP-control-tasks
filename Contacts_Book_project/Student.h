#pragma once

#include "Person.h"

class Student : public Person {
public:
    Student(const std::string& name, const std::string& phone, int studentId);

    std::string getProfession() const override;

    void displayInfo() const override;

private:
    int studentId;
};
