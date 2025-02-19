#ifndef GRADEMANAGEMENTSYSTEM_H
#define GRADEMANAGEMENTSYSTEM_H

#include <vector>
#include <string>
#include "Student.h"

class GradeManagementSystem {
private:
    std::vector<Student> students;

public:
    void addStudent(int studentId, const std::string& studentName);
    void viewStudents() const;
    void assignGrade(int studentId, const std::string& subject, double grade);
    void updateGrade(int studentId, const std::string& subject, double grade);
    void deleteGrade(int studentId, const std::string& subject);
    void saveDataToFile() const;
    void loadDataFromFile();
};

#endif
