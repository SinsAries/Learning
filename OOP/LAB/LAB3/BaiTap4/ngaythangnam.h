#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H

#include <iostream>

using namespace std;

class NgayThangNam
{
private:
    int iNgay;
    int iThang;
    int iNam;

    bool NamNhuan(int nam) const;
    int SoNgayTrongThang(int thang, int nam) const;

public:
    // Constructor
    NgayThangNam();
    NgayThangNam(int iNam, int iThang, int iNgay);

    // Methods
    int TinhNgay() const;
    void TinhLaiNgay(int tongSoNgay);

    // Operators
    NgayThangNam operator+(int ngay);
    NgayThangNam operator-(int ngay);
    int operator-(const NgayThangNam& other);

    NgayThangNam& operator++();    // Prefix increment
    NgayThangNam operator++(int);  // Postfix increment
    NgayThangNam& operator--();    // Prefix decrement
    NgayThangNam operator--(int);  // Postfix decrement

    bool operator==(const NgayThangNam& other) const;
    bool operator!=(const NgayThangNam& other) const;
    bool operator>=(const NgayThangNam& other) const;
    bool operator<=(const NgayThangNam& other) const;
    bool operator>(const NgayThangNam& other) const;
    bool operator<(const NgayThangNam& other) const;

    // Input and output operators
    friend ostream& operator<<(ostream& os, const NgayThangNam& date);
    friend istream& operator>>(istream& is, NgayThangNam& date);
};

#endif
