#include "Person.h"

Person::Person(const std::string& name, const std::string& phone)
    : name(name), phone(phone) {}

std::string Person::getName() const {
    return name;
}

std::string Person::getPhone() const {
    return phone;
}

void Person::setName(const std::string& newName) {
    name = newName;
}

void Person::setPhone(const std::string& newPhone) {
    phone = newPhone;
}

void Person::displayInfo() const {
    std::cout << "Name: " << getName() << ", Phone: " << getPhone();
}
