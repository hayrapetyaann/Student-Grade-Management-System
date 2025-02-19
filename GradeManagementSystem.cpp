#include "GradeManagementSystem.h"
#include <iostream>
#include <fstream>

void GradeManagementSystem::addStudent(int studentId, const std::string& studentName) {
    Student s;
    s.setStudentInfo(studentId, studentName);
    students.push_back(s);
}

void GradeManagementSystem::viewStudents() const {
    for (const auto& s : students) {
        std::cout << "ID: " << s.getId() << " Name: " << s.getName() << "\n";
        for (const auto& grade : s.getGrades()) {
            std::cout << grade.first << ": " << grade.second << "\n";
        }
        std::cout << "Average: " << s.getAverage() << "\n";
    }
}

void GradeManagementSystem::assignGrade(int studentId, const std::string& subject, double grade) {
    for (auto& s : students) {
        if (s.getId() == studentId) {
            s.addGrade(subject, grade);
            break;
        }
    }
}

void GradeManagementSystem::updateGrade(int studentId, const std::string& subject, double grade) {
    for (auto& s : students) {
        if (s.getId() == studentId) {
            s.updateGrade(subject, grade);
            break;
        }
    }
}

void GradeManagementSystem::deleteGrade(int studentId, const std::string& subject) {
    for (auto& s : students) {
        if (s.getId() == studentId) {
            s.deleteGrade(subject);
            break;
        }
    }
}

void GradeManagementSystem::saveDataToFile() const {
    std::ofstream outFile("students_data.txt");
    for (const auto& s : students) {
        outFile << s.getId() << "," << s.getName() << "\n";
        for (const auto& grade : s.getGrades()) {
            outFile << grade.first << ":" << grade.second << "\n";
        }
        outFile << "Average:" << s.getAverage() << "\n";
    }
}

void GradeManagementSystem::loadDataFromFile() {
    std::ifstream inFile("students_data.txt");
    if (inFile) {
        int studentId;
        std::string studentName, subject;
        double grade;
        while (inFile >> studentId) {
            inFile.ignore();
            std::getline(inFile, studentName);
            addStudent(studentId, studentName);
            while (inFile.peek() != 'A') {
                inFile >> subject;
                inFile.ignore();
                inFile >> grade;
                assignGrade(studentId, subject, grade);
                inFile.ignore();
            }
        }
    }
}

