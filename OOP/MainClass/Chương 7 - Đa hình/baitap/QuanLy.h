#ifndef QUANLY_H
#define QUANLY_H

#include "Nguoi.h"

class QuanLy : public Nguoi {
private:
    double HeSoChucVu;
    double Thuong;
    double LuongCoBan;

public:
    QuanLy();
    ~QuanLy();
    void Nhap() override;
    double TinhLuong() const;
    void Xuat() const override;
};

#endif // QUANLY_H
