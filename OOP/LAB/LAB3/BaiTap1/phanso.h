#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>

using namespace std;

class PhanSo
{
private:
    int iTu;
    int iMau;

public:
    // Constructor
    PhanSo();
    PhanSo(int iTu, int iMau);

    // operator
    PhanSo operator+(const PhanSo& other);
    PhanSo operator-(const PhanSo& other);
    PhanSo operator*(const PhanSo& other);
    PhanSo operator/(const PhanSo& other);

    bool operator==(const PhanSo& other);
    bool operator!=(const PhanSo& other);
    bool operator>=(const PhanSo& other);
    bool operator<=(const PhanSo& other);
    bool operator>(const PhanSo& other);
    bool operator<(const PhanSo& other);

    // in và nhập
    friend ostream& operator<<(ostream& os, const PhanSo& ps);
    friend istream& operator>>(istream& is, PhanSo& ps);
private:
    void RutGon();
};

#endif