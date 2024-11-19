#include "QuanLy.h"
#include <iomanip>
#include <limits>

// Constructor mặc định
QuanLy::QuanLy() : NhanVien(), tyLeThuong(0.0) {}

// Constructor tham số
QuanLy::QuanLy(string maSo, string ten, double luongCoBan, double tyLeThuong)
    : NhanVien(maSo, ten, luongCoBan), tyLeThuong(tyLeThuong) {}

// Hàm nhập thông tin cho quản lý
void QuanLy::Nhap() {
    cout << "\nNhap thong tin Quan Ly:" << endl;
    NhanVien::Nhap(); // Gọi nhập thông tin cơ bản
    cout << "Nhap ty le thuong (vi du: 0.1 = 10%): ";
    cin >> tyLeThuong;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Hàm xuất thông tin của quản lý
void QuanLy::Xuat() const {
    cout << "\nThong tin Quan Ly:\n";
    cout << "Ma so: " << maSo << endl;
    cout << "Ten: " << ten << endl;
    cout << "Luong co ban: " << luongCoBan << endl;
    cout << "Ty le thuong: " << tyLeThuong << endl;
    cout << "Tien thuong: " << fixed << setprecision(2) << TienThuong() << endl; // Định dạng 2 chữ số thập phân
}

// Hàm tính tiền thưởng của quản lý
double QuanLy::TienThuong() const {
    return luongCoBan * tyLeThuong;
}

// Destructor
QuanLy::~QuanLy() {
    // Không có tài nguyên động, không cần xử lý đặc biệt
}
