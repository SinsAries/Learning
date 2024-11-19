#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>
using namespace std;

// Lớp cơ sở NhanVien
class NhanVien {
protected:
    string maSo;
    string ten;
    double luongCoBan;

public:
    NhanVien(); // Constructor mặc định
    NhanVien(string maSo, string ten, double luongCoBan); // Constructor tham số

    virtual void Nhap();      // Hàm nhập thông tin
    virtual void Xuat() const; // Hàm xuất thông tin
    virtual double TienThuong() const = 0; // Hàm tính tiền thưởng (pure virtual)

    virtual ~NhanVien(); // Destructor
};

#endif
