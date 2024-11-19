#include "NhanVienVanPhong.h"
#include <iomanip>

// Constructor
NhanVienVanPhong::NhanVienVanPhong() : Nguoi(), SoNgayLamViec(0), TroCap(0), LuongCoBan(0) {}

// Destructor
NhanVienVanPhong::~NhanVienVanPhong() {}

// Method for input
void NhanVienVanPhong::Nhap() {
    Nguoi::Nhap();
    std::cout << "Nhap luong co ban: ";
    std::cin >> LuongCoBan;
    std::cout << "Nhap so ngay lam viec: ";
    std::cin >> SoNgayLamViec;
    std::cout << "Nhap tro cap: ";
    std::cin >> TroCap;
}

// Method to calculate salary
double NhanVienVanPhong::TinhLuong() const {
    return LuongCoBan + SoNgayLamViec * 200000 + TroCap;
}

// Method to output information
void NhanVienVanPhong::Xuat() const {
    Nguoi::Xuat();
    std::cout << std::fixed << std::setprecision(0);  // Set fixed format with no decimal places
    std::cout << "Nhan vien van phong, Luong: " << TinhLuong() << std::endl;
}