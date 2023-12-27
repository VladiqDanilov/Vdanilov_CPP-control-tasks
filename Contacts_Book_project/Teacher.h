#pragma once

#include "Person.h"

class Teacher : public Person {
public:
    Teacher(const std::string& name, const std::string& phone, const std::string& subject);

    std::string getProfession() const override;

    void displayInfo() const override;

private:
    std::string subject;
};

