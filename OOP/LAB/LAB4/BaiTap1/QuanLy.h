#ifndef QUANLY_H
#define QUANLY_H

#include "NhanVien.h"

// Lớp QuanLy kế thừa từ NhanVien
class QuanLy : public NhanVien {
private:
    double tyLeThuong; // Tỷ lệ thưởng của quản lý

public:
    // Constructor mặc định
    QuanLy();

    // Constructor tham số
    QuanLy(string maSo, string ten, double luongCoBan, double tyLeThuong);

    // Nhập thông tin cho quản lý
    void Nhap() override;

    // Xuất thông tin của quản lý
    void Xuat() const override;

    // Tính tiền thưởng của quản lý
    double TienThuong() const override;

    // Destructor
    ~QuanLy();
};

#endif