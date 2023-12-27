#pragma once

#include <iostream>
#include <string>

class Person {
public:
    Person(const std::string& name, const std::string& phone);

    virtual std::string getProfession() const = 0;

    virtual void displayInfo() const;

    std::string getName() const;

    std::string getPhone() const;

protected:
    void setName(const std::string& newName);

    void setPhone(const std::string& newPhone);

private:
    std::string name;
    std::string phone;
};
