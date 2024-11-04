#include "phanso.h"

// default constructor
PhanSo::PhanSo() : iTu(0), iMau(1) {}

// constructor with parameters
PhanSo::PhanSo(int tu, int mau) : iTu(tu), iMau(mau) {
    if (iMau == 0) {
        cout << "Mau so phai khac 0" << endl;
        this->iMau = 1;
    }
    this->RutGon();
}

// method
void PhanSo::RutGon() {
    int a = abs(this->iTu);
    int b = abs(this->iMau);
    while (a * b != 0) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    int gcd = a + b;
    this->iTu /= gcd;
    this->iMau /= gcd;
}

// operator
PhanSo PhanSo::operator+(const PhanSo& other) {
    PhanSo res;
    res.iTu = this->iTu * other.iMau + other.iTu * this->iMau;
    res.iMau = this->iMau * other.iMau;
    res.RutGon();
    return res;
}

PhanSo PhanSo::operator-(const PhanSo& other) {
    PhanSo res;
    res.iTu = this->iTu * other.iMau - other.iTu * this->iMau;
    res.iMau = this->iMau * other.iMau;
    res.RutGon();
    return res;
}

PhanSo PhanSo::operator*(const PhanSo& other) {
    PhanSo res;
    res.iTu = this->iTu * other.iTu;
    res.iMau = this->iMau * other.iMau;
    res.RutGon();
    return res;
}

PhanSo PhanSo::operator/(const PhanSo& other) {
    PhanSo res;
    res.iTu = this->iTu * other.iMau;
    res.iMau = this->iMau * other.iTu;
    res.RutGon();
    return res;
}

bool PhanSo::operator==(const PhanSo& other) {
    return (this->iTu == other.iTu && this->iMau == other.iMau);
}

bool PhanSo::operator!=(const PhanSo& other) {
    return !(*this == other);
}

bool PhanSo::operator>=(const PhanSo& other) {
    return (this->iTu * other.iMau >= other.iTu * this->iMau);
}

bool PhanSo::operator<=(const PhanSo& other) {
    return (this->iTu * other.iMau <= other.iTu * this->iMau);
}

bool PhanSo::operator>(const PhanSo& other) {
    return (this->iTu * other.iMau > other.iTu * this->iMau);
}

bool PhanSo::operator<(const PhanSo& other) {
    return (this->iTu * other.iMau < other.iTu * this->iMau);
}

// in và nhập
ostream& operator<<(ostream& out, const PhanSo& ps) {
    out << ps.iTu << "/" << ps.iMau;
    return out;
}

istream& operator>>(istream& in, PhanSo& ps) {
    ps.iMau = 0;
    while (ps.iMau == 0) {
        cout << "Nhap tu so: ";
        in >> ps.iTu;
        cout << "Nhap mau so: ";
        in >> ps.iMau;
        if (ps.iMau == 0) {
            cout << "Mau so phai khac 0" << endl;
        }
    }
    ps.RutGon();
    return in;
}


