#include "Student.h"
#include <iostream>

Student::Student() : id(0), name(""), average(0.0) {}

void Student::setStudentInfo(int studentId, const std::string& studentName) {
    id = studentId;
    name = studentName;
}

void Student::addGrade(const std::string& subject, double grade) {
    grades[subject] = grade;
    calculateAverage();
}

void Student::updateGrade(const std::string& subject, double grade) {
    if (grades.find(subject) != grades.end()) {
        grades[subject] = grade;
        calculateAverage();
    }
}

void Student::deleteGrade(const std::string& subject) {
    if (grades.find(subject) != grades.end()) {
        grades.erase(subject);
        calculateAverage();
    }
}

void Student::calculateAverage() {
    double sum = 0;
    for (const auto& grade : grades) {
        sum += grade.second;
    }
    average = (grades.size() > 0) ? sum / grades.size() : 0;
}

int Student::getId() const {
    return id;
}

std::string Student::getName() const {
    return name;
}

std::map<std::string, double> Student::getGrades() const {
    return grades;
}

double Student::getAverage() const {
    return average;
}

