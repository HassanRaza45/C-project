 #include <iostream>
#include <fstream>

using namespace std;

struct Student {
    int student_ID;
    string name;
    string email_address;
    string department;
    string phone_number;
};

void saveStudentDetails(const Student& student) {
    ofstream outputFile("student.txt", ios::app);

    if (!outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    outputFile << student.name << '\t' << student.student_ID << '\t' << student.email_address << '\t' << student.department << '\t' << student.phone_number << endl;

    outputFile.close();
}

int main() {
    char choice;

    do {
        Student student;

        cout << "Enter student details:" << endl;
        cout << "Name: ";
        cin.ignore(); // Clear the newline character from the buffer
        getline(cin, student.name);

        cout << "Student ID: ";
        cin >> student.student_ID;

        cout << "Email Address: ";
        cin >> student.email_address;

        cout << "Department: ";
        cin >> student.department;

        cout << "Phone Number: ";
        cin >> student.phone_number;

        saveStudentDetails(student);

        cout << "Record saved. ID: " << student.student_ID << ", Department: " << student.department << ", Phone Number: " << student.phone_number << endl;

        cout << "Do you want to enter another record? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}

