#include <bits/stdc++.h>

using namespace std;

class Student {
private:
    string studentID;
    string fullName;
    string gender;
    float mathScore;
    float physicsScore;
    float chemistryScore;

public:
    void Input() {
        cout << "Nhap ma hoc sinh: ";
        getline(cin, studentID);
        cout << "Nhap ho ten: ";
        getline(cin, fullName);
        cout << "Nhap gioi tinh: ";
        getline(cin, gender);
        cout << "Nhap diem Toan: ";
        cin >> mathScore;
        cout << "Nhap diem Ly: ";
        cin >> physicsScore;
        cout << "Nhap diem Hoa: ";
        cin >> chemistryScore;
    }

    float CalculateAverageScore() const {
        return (mathScore + physicsScore + chemistryScore) / 3.0;
    }

    void Output() const {
        cout << "Ma hoc sinh: " << studentID << endl;
        cout << "Ho ten: " << fullName << endl;
        cout << "Gioi tinh: " << gender << endl;
        cout << "Diem Toan: " << mathScore << endl;
        cout << "Diem Ly: " << physicsScore << endl;
        cout << "Diem Hoa: " << chemistryScore << endl;
        cout << "Diem trung binh: " << CalculateAverageScore() << endl;
    }
};

int main() {
    Student student;
    student.Input();
    student.Output();

    return 0;
}
