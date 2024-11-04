#include "sophuc.h"

// Default constructor
SoPhuc::SoPhuc() : dThuc(0), dAo(0) {}

// Constructor with parameters
SoPhuc::SoPhuc(double thuc, double ao) : dThuc(thuc), dAo(ao) {}

// Operator overloading for addition
SoPhuc SoPhuc::operator+(const SoPhuc& other) {
    return SoPhuc(this->dThuc + other.dThuc, this->dAo + other.dAo);
}

// Operator overloading for subtraction
SoPhuc SoPhuc::operator-(const SoPhuc& other) {
    return SoPhuc(this->dThuc - other.dThuc, this->dAo - other.dAo);
}

// Operator overloading for multiplication
SoPhuc SoPhuc::operator*(const SoPhuc& other) {
    double thuc = this->dThuc * other.dThuc - this->dAo * other.dAo;
    double ao = this->dThuc * other.dAo + this->dAo * other.dThuc;
    return SoPhuc(thuc, ao);
}

// Operator overloading for division
SoPhuc SoPhuc::operator/(const SoPhuc& other) {
    double denominator = other.dThuc * other.dThuc + other.dAo * other.dAo;
    double thuc = (this->dThuc * other.dThuc + this->dAo * other.dAo) / denominator;
    double ao = (this->dAo * other.dThuc - this->dThuc * other.dAo) / denominator;
    return SoPhuc(thuc, ao);
}

// Comparison operators
bool SoPhuc::operator==(const SoPhuc& other) {
    return (this->dThuc == other.dThuc && this->dAo == other.dAo);
}

bool SoPhuc::operator!=(const SoPhuc& other) {
    return !(*this == other);
}

// Output operator overloading
ostream& operator<<(ostream& os, const SoPhuc& sp) {
    os << sp.dThuc << " + " << sp.dAo << "i";
    return os;
}

// Input operator overloading
istream& operator>>(istream& is, SoPhuc& sp) {
    cout << "Nhap phan thuc: ";
    is >> sp.dThuc;
    cout << "Nhap phan ao: ";
    is >> sp.dAo;
    return is;
}
