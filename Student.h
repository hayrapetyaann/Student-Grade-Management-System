#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <map>

class Student {
private:
    int id;
    std::string name;
    std::map<std::string, double> grades;
    double average;

public:
    Student();
    void setStudentInfo(int studentId, const std::string& studentName);
    void addGrade(const std::string& subject, double grade);
    void updateGrade(const std::string& subject, double grade);
    void deleteGrade(const std::string& subject);
    void calculateAverage();
    int getId() const;
    std::string getName() const;
    std::map<std::string, double> getGrades() const;
    double getAverage() const;
};

#endif
