#ifndef GIASUC_H
#define GIASUC_H

#include <iostream>
#include <string>
#include <cstdlib> // Để sử dụng hàm rand()
using namespace std;

// Lớp cơ sở GiaSuc
class GiaSuc {
protected:
    int soLuong;

public:
    GiaSuc(int soLuong);
    virtual string TiengKeu() const = 0; // Hàm ảo thuần túy
    virtual int SinhCon() const = 0;    // Hàm ảo để tính số con sinh ra
    virtual int ChoSua() const = 0;     // Hàm ảo để tính lượng sữa
    virtual void XuatThongTin() const;  // Xuất thông tin chung
    int getSoLuong() const;             // Lấy số lượng gia súc
    virtual ~GiaSuc();
};

#endif
