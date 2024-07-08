// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

int main(){
    float GPA = 0.0f;
    int id;
    
    std::vector<Student> students = {Student(1, "George P. Burdell"),
                                    Student(2, "Nancy Rhodes")};

    std::vector<Course> courses = {Course(1, "Algebra", 5),
                                Course(2, "Physics", 4),
                                Course(3, "English", 3),
                                Course(4, "Economics", 4)};

    std::vector<Grade> grades = {Grade(1, 1, 'B'), Grade(1, 2, 'A'), Grade(1, 3, 'C'),
                                Grade(2, 1, 'A'), Grade(2, 2, 'A'), Grade(2, 4, 'B')};

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    // Calculate the GPA for the selected student.
    // Write your code here
    int i;
    double total_points;
    double total_credits;
    double grade_point = 0;
    double gpa = 0;
    for(i = 0; i< grades.size(); i++)
    {
        if(id == grades[i].get_student_id())
        {
            switch (grades[i].get_grade())
            {
            case 'A' : grade_point = 5.0;
                    break;
            case 'B' : grade_point = 4.0;
                    break;
            case 'C' : grade_point = 3.0;
                    break;
            case 'D' : grade_point = 2.0;
                    break;                        
            
            default: grade_point = 0;
                break;
            }
            

            for(int j = 0; j < courses.size(); j++)
            {
                if(grades[i].get_course_id() == courses[j].get_id())
                {
                    total_points += (grade_point*courses[j].get_credits());
                    total_credits += courses[j].get_credits();
                }
            }
        }
    }
    
    GPA = total_points/total_credits;
    std::string student_str;
    i = 0;
    while(i<students.size() && id != students[i].get_id())
        i++;
    student_str = students[i].get_name(); // Change this to the selected student's name
    
    std::cout << "The GPA for " << student_str << " is " << GPA << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
