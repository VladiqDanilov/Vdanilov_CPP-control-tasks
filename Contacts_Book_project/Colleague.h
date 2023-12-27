// Colleague.h
#pragma once

#include "Person.h"

class Colleague : public Person {
public:
    Colleague(const std::string& name, const std::string& phone, const std::string& department);

    std::string getProfession() const override;

    void displayInfo() const override;

    std::string getDepartment() const;

    void setDepartment(const std::string& newDepartment);

private:
    std::string department;
};


