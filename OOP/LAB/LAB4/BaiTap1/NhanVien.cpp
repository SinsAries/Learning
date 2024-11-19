#include "NhanVien.h"
#include <limits>

// Constructor mặc định
NhanVien::NhanVien() : maSo(""), ten(""), luongCoBan(0.0) {}

// Constructor tham số
NhanVien::NhanVien(string maSo, string ten, double luongCoBan)
    : maSo(maSo), ten(ten), luongCoBan(luongCoBan) {}

// Hàm nhập thông tin nhân viên
void NhanVien::Nhap() {
    cout << "Nhap ma so nhan vien: ";
    cin >> maSo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap ten nhan vien: ";
    getline(cin, ten);

    cout << "Nhap luong co ban: ";
    cin >> luongCoBan;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


// Hàm xuất thông tin nhân viên
void NhanVien::Xuat() const {
    cout << "Ma so: " << maSo << endl;
    cout << "Ten: " << ten << endl;
    cout << "Luong co ban: " << luongCoBan << endl;
}

// Destructor
NhanVien::~NhanVien() {
    // Không cần xử lý gì đặc biệt, vì không sử dụng bộ nhớ động
}
