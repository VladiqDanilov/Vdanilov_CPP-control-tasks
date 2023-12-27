#pragma once

#include <iostream>
#include "PersonCollection.cpp"
#include "Student.h"
#include "Teacher.h"
#include "Colleague.h"

class UserInterface {
public:
    void run();

private:
    PersonCollection collection;

    void displayMenu() const;
    void processChoice(int choice);
    void addStudent();
    void addTeacher();
    void addColleague();
    void displayAllPeople() const;
    void saveToFile() const;
};
