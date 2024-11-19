#ifndef KYSU_H
#define KYSU_H

#include "NhanVien.h"

// Lớp KySu kế thừa từ NhanVien
class KySu : public NhanVien {
private:
    int soGioLamThem; // Số giờ làm thêm của kỹ sư

public:
    // Constructor mặc định
    KySu();

    // Constructor tham số
    KySu(string maSo, string ten, double luongCoBan, int soGioLamThem);

    // Nhập thông tin cho kỹ sư
    void Nhap() override;

    // Xuất thông tin của kỹ sư
    void Xuat() const override;

    // Tính tiền thưởng của kỹ sư
    double TienThuong() const override;

    // Destructor
    ~KySu();
};

#endif
