#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct SubjectGrade {
    string subjectName;
    double score;
};

class Student {
private:
    string name;
    vector<SubjectGrade> grades;

public:
    Student(string n) {
        name = n;
    }

    string getName() const { return name; }

    void addGrade(string subject, double score) {
        SubjectGrade sg = {subject, score};
        grades.push_back(sg);
    }

    double calculateAverage() const {
        if (grades.empty()) return 0.0;
        double sum = 0;
        for (size_t i = 0; i < grades.size(); i++) {
            sum += grades[i].score;
        }
        return sum / grades.size();
    }

    char calculateLetterGrade() const {
        double avg = calculateAverage();
        if (avg >= 90) return 'A';
        if (avg >= 80) return 'B';
        if (avg >= 70) return 'C';
        if (avg >= 60) return 'D';
        return 'F';
    }

    void displayReport() const {
        cout << "Student: " << name << "\n";
        for (size_t i = 0; i < grades.size(); i++) {
            cout << "  " << grades[i].subjectName << ": " << grades[i].score << "\n";
        }
        cout << "  Average: " << calculateAverage() << " | Grade: " << calculateLetterGrade() << "\n";
    }
};

class SchoolSystem {
private:
    vector<Student> students;

public:
    void addStudent() {
        string name;
        cout << "Enter student name: ";
        cin >> name;
        students.push_back(Student(name));
        cout << "Student \"" << name << "\" added.\n";
    }

    void recordGrade() {
        string name;
        cout << "Enter student name: ";
        cin >> name;

        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].getName() == name) {
                string subject;
                double score;
                cout << "Enter subject: ";
                cin >> subject;
                cout << "Enter grade: ";
                cin >> score;

                students[i].addGrade(subject, score);
                cout << "Grade recorded.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void displayAllReports() {
        if (students.empty()) {
            cout << "No students registered in the system.\n";
            return;
        }
        cout << "\n--- Class Performance Report ---\n";
        for (size_t i = 0; i < students.size(); i++) {
            students[i].displayReport();
            cout << "--------------------------------\n";
        }
    }
};

int main() {
    SchoolSystem system;
    int choice;

    while (true) {
        cout << "\n=== Student Grades System ===\n";
        cout << "1. Add Student\n";
        cout << "2. Record Grade\n";
        cout << "3. Display Report\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) system.addStudent();
        else if (choice == 2) system.recordGrade();
        else if (choice == 3) system.displayAllReports();
        else if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid option! Try again.\n";
        }
    }
    return 0;
}
