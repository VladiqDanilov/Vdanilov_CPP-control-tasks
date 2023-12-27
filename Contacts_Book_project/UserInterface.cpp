#include "UserInterface.h"

void UserInterface::run() {
    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        processChoice(choice);
    } while (choice != 0);
}

void UserInterface::displayMenu() const {
    std::cout << "\n==== Menu ====\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Add Teacher\n";
    std::cout << "3. Add Colleague\n";  
    std::cout << "4. Display All People\n";
    std::cout << "5. Save to File\n";
    std::cout << "0. Exit\n";
}

void UserInterface::processChoice(int choice) {
    switch (choice) {
    case 1:
        addStudent();
        break;
    case 2:
        addTeacher();
        break;
    case 3:
        addColleague();
        break;
    case 4:
        displayAllPeople();
        break;
    case 5:
        saveToFile(); 
        break;
    case 0:
        std::cout << "Exiting...\n";
        break;
    default:
        std::cerr << "Invalid choice. Try again.\n";
    }
}

void UserInterface::addStudent() {
    std::string name, phone;
    int studentId;

    std::cin.ignore();

    std::cout << "Enter student name: ";
    std::getline(std::cin, name);

    std::cout << "Enter student phone: ";
    std::getline(std::cin, phone);

    std::cout << "Enter student ID: ";
    std::cin >> studentId;

    collection.addPerson(new Student(name, phone, studentId));
    std::cout << "Student added successfully.\n";
}

void UserInterface::addTeacher() {
    std::string name, phone, subject;

    std::cin.ignore();

    std::cout << "Enter teacher name: ";
    std::getline(std::cin, name);

    std::cout << "Enter teacher phone: ";
    std::getline(std::cin, phone);

    std::cout << "Enter teacher subject: ";
    std::getline(std::cin, subject);

    collection.addPerson(new Teacher(name, phone, subject));
    std::cout << "Teacher added successfully.\n";
}

void UserInterface::addColleague() {
    std::string name, phone, department;
    std::cout << "Enter colleague name: ";
    std::cin >> name;
    std::cout << "Enter colleague phone: ";
    std::cin >> phone;
    std::cout << "Enter colleague department: ";
    std::cin >> department;

    collection.addPerson(new Colleague(name, phone, department));
    std::cout << "Colleague added successfully.\n";
}

void UserInterface::displayAllPeople() const {
    collection.displayAll();
}

void UserInterface::saveToFile() const {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    if (filename.size() >= 4 && filename.substr(filename.size() - 4) != ".txt") {
        filename += ".txt";
    }

    collection.saveToFile(filename);
}
