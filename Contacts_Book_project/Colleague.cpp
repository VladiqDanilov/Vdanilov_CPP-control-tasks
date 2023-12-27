#include "Colleague.h"

Colleague::Colleague(const std::string& name, const std::string& phone, const std::string& department)
    : Person(name, phone), department(department) {}

std::string Colleague::getProfession() const {
    return "Colleague";
}

void Colleague::displayInfo() const {
    Person::displayInfo();
    std::cout << ", Department: " << department;
}

std::string Colleague::getDepartment() const {
    return department;
}

void Colleague::setDepartment(const std::string& newDepartment) {
    department = newDepartment;
}
