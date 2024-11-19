#ifndef PHONG_H
#define PHONG_H

#include <iostream>
using namespace std;

// Lớp cơ sở Phong
class Phong {
protected:
    int soDem;
    double phiDichVu;

public:
    Phong(int soDem, double phiDichVu);
    virtual double TinhDoanhThu() const = 0; // Hàm ảo thuần túy
    virtual void XuatThongTin() const;      // Hiển thị thông tin phòng
    virtual ~Phong();
};

#endif
