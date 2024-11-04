#include "thoigian.h"

// Default constructor
ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

// Constructor with parameters
ThoiGian::ThoiGian(int gio, int phut, int giay) : iGio(gio), iPhut(phut), iGiay(giay) {}

// Method to calculate total seconds
int ThoiGian::TinhGiay() const {
    return iGio * 3600 + iPhut * 60 + iGiay;
}

// Method to recalculate hours, minutes, and seconds from total seconds
void ThoiGian::TinhLaiGio(int giayTong) {
    iGio = giayTong / 3600;
    giayTong %= 3600;
    iPhut = giayTong / 60;
    iGiay = giayTong % 60;
}

// Operator overloading
ThoiGian ThoiGian::operator+(int giay) {
    ThoiGian res = *this;
    res.TinhLaiGio(this->TinhGiay() + giay);
    return res;
}

ThoiGian ThoiGian::operator-(int giay) {
    ThoiGian res = *this;
    res.TinhLaiGio(this->TinhGiay() - giay);
    return res;
}

ThoiGian ThoiGian::operator+(const ThoiGian& other) {
    return ThoiGian(0, 0, this->TinhGiay() + other.TinhGiay());
}

ThoiGian ThoiGian::operator-(const ThoiGian& other) {
    return ThoiGian(0, 0, this->TinhGiay() - other.TinhGiay());
}

// Prefix increment
ThoiGian& ThoiGian::operator++() {
    *this = *this + 1;
    return *this;
}

// Postfix increment
ThoiGian ThoiGian::operator++(int) {
    ThoiGian temp = *this;
    ++(*this);
    return temp;
}

// Prefix decrement
ThoiGian& ThoiGian::operator--() {
    *this = *this - 1;
    return *this;
}

// Postfix decrement
ThoiGian ThoiGian::operator--(int) {
    ThoiGian temp = *this;
    --(*this);
    return temp;
}

// Comparison operators
bool ThoiGian::operator==(const ThoiGian& other) const {
    return this->TinhGiay() == other.TinhGiay();
}

bool ThoiGian::operator!=(const ThoiGian& other) const {
    return !(*this == other);
}

bool ThoiGian::operator>=(const ThoiGian& other) const {
    return this->TinhGiay() >= other.TinhGiay();
}

bool ThoiGian::operator<=(const ThoiGian& other) const {
    return this->TinhGiay() <= other.TinhGiay();
}

bool ThoiGian::operator>(const ThoiGian& other) const {
    return this->TinhGiay() > other.TinhGiay();
}

bool ThoiGian::operator<(const ThoiGian& other) const {
    return this->TinhGiay() < other.TinhGiay();
}

// Input and output operators
ostream& operator<<(ostream& os, const ThoiGian& tg) {
    os << tg.iGio << " giờ, " << tg.iPhut << " phút, " << tg.iGiay << " giây";
    return os;
}

istream& operator>>(istream& is, ThoiGian& tg) {
    cout << "Nhập giờ: ";
    is >> tg.iGio;
    cout << "Nhập phút: ";
    is >> tg.iPhut;
    cout << "Nhập giây: ";
    is >> tg.iGiay;
    return is;
}
