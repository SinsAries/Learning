#include "Nguoi.h"
#include <cstring>
#include <iomanip>

// Default Constructor
Nguoi::Nguoi() : HoTen(nullptr), NamSinh(0) {}

// Parameterized Constructor
Nguoi::Nguoi(const char *ht, int ns) : NamSinh(ns) {
    HoTen = strdup(ht);
}

// Destructor
Nguoi::~Nguoi() {
    delete[] HoTen;
}

// Method for input
void Nguoi::Nhap() {
    char buffer[100];
    std::cout << "Nhap ho ten: ";
    std::cin.ignore();
    std::cin.getline(buffer, 100);
    HoTen = strdup(buffer);
    std::cout << "Nhap nam sinh: ";
    std::cin >> NamSinh;
}

// Method to output information
void Nguoi::Xuat() const {
    std::cout << "Nguoi, ho ten: " << HoTen << " sinh " << NamSinh << std::endl;
}

// Getter method for HoTen
const char* Nguoi::getHoTen() const {
    return HoTen;
}
