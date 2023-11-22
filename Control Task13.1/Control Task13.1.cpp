#include <iostream>
#include "human.h"
#include "student.h"
#include "teacher.h"
#include <string>

int main()
{
    setlocale(LC_ALL, "ru");
    human cheL1{ "DuHast", "Ivan", "Vyacheslavovich" };
    std::string Res1 = cheL1.get_full_name();
    std::cout << Res1 << std::endl;
    std::cout << std::string(5, '\n') << std::endl;

    student Stu1("Megan", "Oliver", "", { 5, 4, 4, 3, 5, 5, 4, 5, 5 });
    std::string ResPromech = Stu1.get_full_name();
    std::cout << ResPromech << std::endl;
    float Res2 = Stu1.get_average_score();
    std::cout << "Средний балл: " << Res2 << std::endl;
    std::cout << std::string(5, '\n') << std::endl;

    unsigned int teacher_work_time = 40;
    teacher* tch = new teacher("Сергеев", "Дмитрий", "Сергеевич",
        teacher_work_time);
    std::cout << tch->get_full_name() << std::endl;
    std::cout << "Количество часов: " << tch->get_work_time() <<
        std::endl;
    /*
     указатели на объекты производных классов
     */
    human* h1 = new student("Philips", "Trevor", "", { 3, 3, 4, 5, 3, 4, 4, 5, 4 });
    human* h2 = new teacher("Snowden", "Edward", "Joseph", 35);



    h1->printer();
    h2->printer();
    //вызов виртуальной функции через эти указатели вызывает соответствующие версии функции в производных классах.

    std::cout << "\n" << h1->get_full_name() << std::endl;
    std::cout << "\n" << h2->get_full_name() << std::endl;
}
