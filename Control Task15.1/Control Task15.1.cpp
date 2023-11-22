#include <iostream>
#include <map>
#include <string>
#include "GradeMap.h"


int main() {
    GradeMap gradeMap;

    gradeMap.addGrade("Pol", 5);
    gradeMap.addGrade("Alice", 3);
    gradeMap.addGrade("Bob", 4);

    gradeMap.displayGrades();

    return 0;
}