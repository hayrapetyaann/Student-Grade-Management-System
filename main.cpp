#include <iostream>
#include "GradeManagementSystem.h"

int main() {
    GradeManagementSystem system;
    system.loadDataFromFile();

    int choice;
    do {
        std::cout << "\nGrade Management System\n";
        std::cout << "1. Add Student\n2. View Students\n3. Assign Grade\n4. Update Grade\n5. Delete Grade\n6. Save Data\n7. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int studentId;
                std::string studentName;
                std::cout << "Enter student ID: ";
                std::cin >> studentId;
                std::cout << "Enter student name: ";
                std::cin.ignore();  // To consume any leftover newline character
                std::getline(std::cin, studentName);
                system.addStudent(studentId, studentName);
                break;
            }
            case 2:
                system.viewStudents();
                break;
            case 3: {
                int studentId;
                std::string subject;
                double grade;
                std::cout << "Enter student ID: ";
                std::cin >> studentId;
                std::cout << "Enter subject name: ";
                std::cin.ignore();
                std::getline(std::cin, subject);
                std::cout << "Enter grade: ";
                std::cin >> grade;
                system.assignGrade(studentId, subject, grade);
                break;
            }
            case 4: {
                int studentId;
                std::string subject;
                double grade;
                std::cout << "Enter student ID: ";
                std::cin >> studentId;
                std::cout << "Enter subject name: ";
                std::cin.ignore();
                std::getline(std::cin, subject);
                std::cout << "Enter new grade: ";
                std::cin >> grade;
                system.updateGrade(studentId, subject, grade);
                break;
            }
            case 5: {
                int studentId;
                std::string subject;
                std::cout << "Enter student ID: ";
                std::cin >> studentId;
                std::cout << "Enter subject name: ";
                std::cin.ignore();
                std::getline(std::cin, subject);
                system.deleteGrade(studentId, subject);
                break;
            }
            case 6:
                system.saveDataToFile();
                std::cout << "Data saved successfully.\n";
                break;
            case 7:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Try again.\n";
                break;
        }
    } while (choice != 7);

    return 0;
}
