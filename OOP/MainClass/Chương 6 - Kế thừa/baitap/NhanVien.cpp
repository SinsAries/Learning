#include "NhanVien.h"
#include <iostream>
#include <iomanip> // For formatting

// Constructor và Destructor của NhanVien
NhanVien::NhanVien() : maNhanVien(nullptr), hoTen(nullptr), tuoi(0), soDienThoai(nullptr), email(nullptr), luongCoBan(0.0) {}

NhanVien::NhanVien(const char *maNV, const char *ten, int age, const char *sdt, const char *mail, float luong)
    : tuoi(age), luongCoBan(luong) {
    maNhanVien = strdup(maNV);
    hoTen = strdup(ten);
    soDienThoai = strdup(sdt);
    email = strdup(mail);
}

NhanVien::NhanVien(const NhanVien &nv) : tuoi(nv.tuoi), luongCoBan(nv.luongCoBan) {
    maNhanVien = strdup(nv.maNhanVien);
    hoTen = strdup(nv.hoTen);
    soDienThoai = strdup(nv.soDienThoai);
    email = strdup(nv.email);
}

NhanVien::~NhanVien() {
    delete[] maNhanVien;
    delete[] hoTen;
    delete[] soDienThoai;
    delete[] email;
}

void NhanVien::nhapThongTin() {
    char buffer[100];

    std::cout << "Nhap ma nhan vien: ";
    std::cin >> buffer;
    maNhanVien = strdup(buffer);

    std::cout << "Nhap ho ten: ";
    std::cin.ignore();
    std::cin.getline(buffer, 100);
    hoTen = strdup(buffer);

    std::cout << "Nhap tuoi: ";
    std::cin >> tuoi;

    std::cout << "Nhap so dien thoai: ";
    std::cin >> buffer;
    soDienThoai = strdup(buffer);

    std::cout << "Nhap email: ";
    std::cin >> buffer;
    email = strdup(buffer);

    std::cout << "Nhap luong co ban: ";
    std::cin >> luongCoBan;
}

void NhanVien::xuatThongTin() const {
    std::cout << "Ma nhan vien: " << maNhanVien
              << "\nHo ten: " << hoTen
              << "\nTuoi: " << tuoi
              << "\nSo dien thoai: " << soDienThoai
              << "\nEmail: " << email
              << "\nLuong co ban: " << std::fixed << std::setprecision(0) << luongCoBan << std::endl;
}

// Lớp LapTrinhVien
LapTrinhVien::LapTrinhVien() : NhanVien(), soGioOvertime(0) {}

LapTrinhVien::LapTrinhVien(const char *maNV, const char *ten, int age, const char *sdt, const char *mail, float luong, int gioOT)
    : NhanVien(maNV, ten, age, sdt, mail, luong), soGioOvertime(gioOT) {}

LapTrinhVien::LapTrinhVien(const LapTrinhVien &ltv) : NhanVien(ltv), soGioOvertime(ltv.soGioOvertime) {}

LapTrinhVien::~LapTrinhVien() {}

void LapTrinhVien::nhapThongTin() {
    NhanVien::nhapThongTin();
    std::cout << "Nhap so gio overtime: ";
    std::cin >> soGioOvertime;
}

void LapTrinhVien::xuatThongTin() const {
    NhanVien::xuatThongTin();
    std::cout << "So gio overtime: " << soGioOvertime
              << "\nLuong thuc linh: " << std::fixed << std::setprecision(0) << tinhLuong() << std::endl;
}

float LapTrinhVien::tinhLuong() const {
    return luongCoBan + soGioOvertime * 200000;
}

// Lớp KiemChungVien
KiemChungVien::KiemChungVien() : NhanVien(), soLoiPhatHien(0) {}

KiemChungVien::KiemChungVien(const char *maNV, const char *ten, int age, const char *sdt, const char *mail, float luong, int soLoi)
    : NhanVien(maNV, ten, age, sdt, mail, luong), soLoiPhatHien(soLoi) {}

KiemChungVien::KiemChungVien(const KiemChungVien &ktv) : NhanVien(ktv), soLoiPhatHien(ktv.soLoiPhatHien) {}

KiemChungVien::~KiemChungVien() {}

void KiemChungVien::nhapThongTin() {
    NhanVien::nhapThongTin();
    std::cout << "Nhap so loi phat hien: ";
    std::cin >> soLoiPhatHien;
}

void KiemChungVien::xuatThongTin() const {
    NhanVien::xuatThongTin();
    std::cout << "So loi phat hien: " << soLoiPhatHien
              << "\nLuong thuc linh: " << std::fixed << std::setprecision(0) << tinhLuong() << std::endl;
}

float KiemChungVien::tinhLuong() const {
    return luongCoBan + soLoiPhatHien * 50000;
}
