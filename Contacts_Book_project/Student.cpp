#include "Student.h"

Student::Student(const std::string& name, const std::string& phone, int studentId)
    : Person(name, phone), studentId(studentId) {}

std::string Student::getProfession() const {
    return "Student";
}

void Student::displayInfo() const {
    Person::displayInfo();
    std::cout << ", Student ID: " << studentId;
}
