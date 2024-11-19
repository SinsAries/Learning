#ifndef NHANVIENSANXUAT_H
#define NHANVIENSANXUAT_H

#include "Nguoi.h"

class NhanVienSanXuat : public Nguoi {
private:
    int SoSanPham;
    double LuongCoBan;

public:
    NhanVienSanXuat();
    ~NhanVienSanXuat();
    void Nhap() override;
    double TinhLuong() const;
    void Xuat() const override;
};

#endif // NHANVIENSANXUAT_H
