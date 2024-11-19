#ifndef NHANVIENVANPHONG_H
#define NHANVIENVANPHONG_H

#include "Nguoi.h"

class NhanVienVanPhong : public Nguoi {
private:
    int SoNgayLamViec;
    double TroCap;
    double LuongCoBan;

public:
    NhanVienVanPhong();
    ~NhanVienVanPhong();
    void Nhap() override;
    double TinhLuong() const;
    void Xuat() const override;
};

#endif // NHANVIENVANPHONG_H
