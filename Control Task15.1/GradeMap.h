#pragma once

#include <map>
#include <string>

class GradeMap
{
public:
    void addGrade(const std::string& name, int grade);
    void displayGrades() const;

private:
    std::map<std::string, int> gradeMap;
};

