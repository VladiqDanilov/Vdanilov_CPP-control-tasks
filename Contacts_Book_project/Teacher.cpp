// Teacher.cpp
#include "Teacher.h"

Teacher::Teacher(const std::string& name, const std::string& phone, const std::string& subject)
    : Person(name, phone), subject(subject) {}

std::string Teacher::getProfession() const {
    return "Teacher";
}

void Teacher::displayInfo() const {
    Person::displayInfo();
    std::cout << ", Subject: " << subject;
}
