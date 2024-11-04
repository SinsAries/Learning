#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>

using namespace std;

class SoPhuc
{
private:
    double dThuc;
    double dAo;

public:
    // Constructor
    SoPhuc();
    SoPhuc(double dThuc, double dAo);

    // Operators
    SoPhuc operator+(const SoPhuc& other);
    SoPhuc operator-(const SoPhuc& other);
    SoPhuc operator*(const SoPhuc& other);
    SoPhuc operator/(const SoPhuc& other);

    bool operator==(const SoPhuc& other);
    bool operator!=(const SoPhuc& other);

    // Friend functions for input and output
    friend ostream& operator<<(ostream& os, const SoPhuc& sp);
    friend istream& operator>>(istream& is, SoPhuc& sp);
};

#endif
