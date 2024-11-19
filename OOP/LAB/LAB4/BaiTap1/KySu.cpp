#include "KySu.h"
#include <iomanip>
#include <limits>

// Constructor mặc định
KySu::KySu() : NhanVien(), soGioLamThem(0) {}

// Constructor tham số
KySu::KySu(string maSo, string ten, double luongCoBan, int soGioLamThem)
    : NhanVien(maSo, ten, luongCoBan), soGioLamThem(soGioLamThem) {}

// Hàm nhập thông tin cho kỹ sư
void KySu::Nhap() {
    cout << "\nNhap thong tin Ky Su:" << endl;
    NhanVien::Nhap(); // Gọi nhập thông tin cơ bản
    cout << "Nhap so gio lam them: ";
    cin >> soGioLamThem;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
// Hàm xuất thông tin của kỹ sư
void KySu::Xuat() const {
    cout << "\nThong tin Ky Su:\n";
    cout << "Ma so: " << maSo << endl;
    cout << "Ten: " << ten << endl;
    cout << "Luong co ban: " << luongCoBan << endl;
    cout << "So gio lam them: " << soGioLamThem << endl;
    cout << "Tien thuong: " << fixed << setprecision(2) << TienThuong() << endl; // Định dạng 2 chữ số thập phân
}

// Hàm tính tiền thưởng của kỹ sư
double KySu::TienThuong() const {
    const double tienThuongMoiGio = 100000; // Định mức 100,000 VNĐ mỗi giờ
    return soGioLamThem * tienThuongMoiGio;
}

// Destructor
KySu::~KySu() {
    // Không có tài nguyên động, không cần xử lý đặc biệt
}
