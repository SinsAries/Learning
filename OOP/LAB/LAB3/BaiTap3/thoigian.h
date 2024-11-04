#ifndef THOIGIAN_H
#define THOIGIAN_H

#include <iostream>

using namespace std;

class ThoiGian
{
private:
    int iGio;
    int iPhut;
    int iGiay;

public:
    // Constructor
    ThoiGian();
    ThoiGian(int iGio, int iPhut, int iGiay);

    // Methods
    int TinhGiay() const;
    void TinhLaiGio(int giayTong);

    // Operators
    ThoiGian operator+(int giay);
    ThoiGian operator-(int giay);
    ThoiGian operator+(const ThoiGian& other);
    ThoiGian operator-(const ThoiGian& other);

    ThoiGian& operator++();    // Prefix increment
    ThoiGian operator++(int);  // Postfix increment
    ThoiGian& operator--();    // Prefix decrement
    ThoiGian operator--(int);  // Postfix decrement

    bool operator==(const ThoiGian& other) const;
    bool operator!=(const ThoiGian& other) const;
    bool operator>=(const ThoiGian& other) const;
    bool operator<=(const ThoiGian& other) const;
    bool operator>(const ThoiGian& other) const;
    bool operator<(const ThoiGian& other) const;

    // Input and output operators
    friend ostream& operator<<(ostream& os, const ThoiGian& tg);
    friend istream& operator>>(istream& is, ThoiGian& tg);
};

#endif
