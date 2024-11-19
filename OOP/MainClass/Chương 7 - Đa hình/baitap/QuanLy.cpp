#include "QuanLy.h"
#include <iomanip>

// Constructor
QuanLy::QuanLy() : Nguoi(), HeSoChucVu(0), Thuong(0), LuongCoBan(0) {}

// Destructor
QuanLy::~QuanLy() {}

// Method for input
void QuanLy::Nhap() {
    Nguoi::Nhap();
    std::cout << "Nhap luong co ban: ";
    std::cin >> LuongCoBan;
    std::cout << "Nhap he so chuc vu: ";
    std::cin >> HeSoChucVu;
    std::cout << "Nhap thuong: ";
    std::cin >> Thuong;
}

// Method to calculate salary
double QuanLy::TinhLuong() const {
    return LuongCoBan * HeSoChucVu + Thuong;
}

// Method to output information
void QuanLy::Xuat() const {
    Nguoi::Xuat();
    std::cout << std::fixed << std::setprecision(0);  // Set fixed format with no decimal places
    std::cout << "Quan ly, Luong: " << TinhLuong() << std::endl;
}