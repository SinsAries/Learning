#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include "Nguoi.h"
#include "NhanVienVanPhong.h"
#include "NhanVienSanXuat.h"
#include "QuanLy.h"

// Function to input employee information from the keyboard
void NhapThongTinNhanVien(std::vector<Nguoi*> &ds) {
    int choice;
    std::cout << "Nhap loai nhan vien (1: Van phong, 2: San xuat, 3: Quan ly): ";
    std::cin >> choice;
    
    Nguoi* nv = nullptr;
    if (choice == 1) {
        nv = new NhanVienVanPhong();
    } else if (choice == 2) {
        nv = new NhanVienSanXuat();
    } else if (choice == 3) {
        nv = new QuanLy();
    }

    if (nv) {
        nv->Nhap();
        ds.push_back(nv);
    } else {
        std::cout << "Loai nhan vien khong hop le." << std::endl;
    }
}

// Function to display information of all employees
void XuatThongTinNhanVien(const std::vector<Nguoi*> &ds) {
    for (const auto &nv : ds) {
        nv->Xuat();
    }
}

// Function to calculate total salary of the company
double TinhTongLuongCongTy(const std::vector<Nguoi*> &ds) {
    double tongLuong = 0;
    for (const auto &nv : ds) {
        // Use dynamic casting to determine type and call the correct salary calculation
        if (auto vp = dynamic_cast<NhanVienVanPhong*>(nv)) {
            tongLuong += vp->TinhLuong();
        } else if (auto sx = dynamic_cast<NhanVienSanXuat*>(nv)) {
            tongLuong += sx->TinhLuong();
        } else if (auto ql = dynamic_cast<QuanLy*>(nv)) {
            tongLuong += ql->TinhLuong();
        }
    }
    return tongLuong;
}

// Function to search for an employee by name
void TimKiemNhanVien(const std::vector<Nguoi*> &ds, const char* ten) {
    bool found = false;
    for (const auto &nv : ds) {
        if (strstr(nv->getHoTen(), ten)) {  // Check if the name contains the search term
            nv->Xuat();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Khong tim thay nhan vien voi ten: " << ten << std::endl;
    }
}

int main() {
    std::vector<Nguoi*> danhSachNhanVien;

    // Nhập thông tin nhân viên
    int soLuong;
    std::cout << "Nhap so luong nhan vien: ";
    std::cin >> soLuong;
    for (int i = 0; i < soLuong; i++) {
        NhapThongTinNhanVien(danhSachNhanVien);
    }

    // Xuất thông tin nhân viên
    std::cout << "\nThong tin nhan vien:\n";
    XuatThongTinNhanVien(danhSachNhanVien);

    // Tính tổng lương của công ty
    double tongLuong = TinhTongLuongCongTy(danhSachNhanVien);
    std::cout << "\nTong luong cong ty: " << std::fixed << std::setprecision(0) << tongLuong << std::endl;

    // Tìm kiếm nhân viên theo tên
    char tenTimKiem[100];
    std::cout << "\nNhap ten nhan vien can tim: ";
    std::cin.ignore();
    std::cin.getline(tenTimKiem, 100);
    std::cout << "\nKet qua tim kiem:\n";
    TimKiemNhanVien(danhSachNhanVien, tenTimKiem);

    // Giải phóng bộ nhớ
    for (auto &nv : danhSachNhanVien) {
        delete nv;
    }

    return 0;
}
