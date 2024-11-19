#include "NhanVienSanXuat.h"
#include <iomanip>

// Constructor
NhanVienSanXuat::NhanVienSanXuat() : Nguoi(), SoSanPham(0), LuongCoBan(0) {}

// Destructor
NhanVienSanXuat::~NhanVienSanXuat() {}

// Method for input
void NhanVienSanXuat::Nhap() {
    Nguoi::Nhap();
    std::cout << "Nhap luong co ban: ";
    std::cin >> LuongCoBan;
    std::cout << "Nhap so san pham: ";
    std::cin >> SoSanPham;
}

// Method to calculate salary
double NhanVienSanXuat::TinhLuong() const {
    return LuongCoBan + SoSanPham * 2000;
}

// Method to output information
void NhanVienSanXuat::Xuat() const {
    Nguoi::Xuat();
    std::cout << std::fixed << std::setprecision(0);  // Set fixed format with no decimal places
    std::cout << "Nhan vien san xuat, Luong: " << TinhLuong() << std::endl;
}
