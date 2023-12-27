// PersonCollection.h
#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Person.h"

class PersonCollection {
public:
    void addPerson(Person* person) {
        people.push_back(person);
    }

    void displayAll() const {
        for (const auto& person : people) {
            person->displayInfo();
            std::cout << ", Profession: " << person->getProfession() << std::endl;
        }
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& person : people) {
                file << person->getProfession() << " - ";
                file << "Name: " << person->getName() << ", Phone: " << person->getPhone();
                file << std::endl;
            }
            file.close();
            std::cout << "Data saved to " << filename << std::endl;
        }
        else {
            std::cerr << "Error opening file: " << filename << std::endl;
        }
    }

    // Деструктор для освобождения памяти
    ~PersonCollection() {
        for (auto person : people) {
            delete person;
        }
    }

private:
    std::vector<Person*> people;
};
