#include "GradeMap.h"
#include <iostream>


void GradeMap::addGrade(const std::string& name, int grade) {
    gradeMap[name] = grade;
}

void GradeMap::displayGrades() const {
    for (const auto& entry : gradeMap) {
        std::cout << "Student: " << entry.first << ", Grade: " << entry.second << std::endl;
    }
}