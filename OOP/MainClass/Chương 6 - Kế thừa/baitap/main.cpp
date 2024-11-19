#include "NhanVien.h"
#include <iostream>
#include <vector>
#include <memory>
#include <iomanip> // Thư viện để định dạng số

// Hàm tính lương trung bình của công ty
float tinhLuongTrungBinh(const std::vector<std::unique_ptr<NhanVien>>& danhSach) {
    float tongLuong = 0;
    for (const auto& nv : danhSach) {
        tongLuong += nv->tinhLuong();
    }
    return danhSach.empty() ? 0 : tongLuong / danhSach.size();
}

int main() {
    std::vector<std::unique_ptr<NhanVien>> danhSachNhanVien;
    int loai, soNhanVien;

    // Nhập số lượng nhân viên
    std::cout << "Nhap so luong nhan vien: ";
    std::cin >> soNhanVien;

    // Nhập thông tin cho từng nhân viên
    for (int i = 0; i < soNhanVien; ++i) {
        std::cout << "\nNhap thong tin cho nhan vien thu " << i + 1 << ":\n";
        std::cout << "Chon loai nhan vien (1 - Lap trinh vien, 2 - Kiem chung vien): ";
        std::cin >> loai;

        if (loai == 1) {
            auto ltv = std::make_unique<LapTrinhVien>();
            ltv->nhapThongTin();
            danhSachNhanVien.push_back(std::move(ltv));
        } else if (loai == 2) {
            auto ktv = std::make_unique<KiemChungVien>();
            ktv->nhapThongTin();
            danhSachNhanVien.push_back(std::move(ktv));
        } else {
            std::cout << "Loai nhan vien khong hop le!\n";
        }
    }

    // Xuất danh sách nhân viên
    std::cout << "\nDanh sach nhan vien:\n";
    for (const auto& nv : danhSachNhanVien) {
        nv->xuatThongTin();
        std::cout << "-------------------------" << std::endl;
    }

    // Tính và hiển thị lương trung bình
    float luongTrungBinh = tinhLuongTrungBinh(danhSachNhanVien);
    std::cout << "Luong trung binh cua cong ty: " << std::fixed << std::setprecision(0) << luongTrungBinh << std::endl;

    // Liệt kê nhân viên có lương thấp hơn mức lương trung bình
    std::cout << "\nDanh sach nhan vien co luong thap hon muc luong trung binh:\n";
    for (const auto& nv : danhSachNhanVien) {
        if (nv->tinhLuong() < luongTrungBinh) {
            nv->xuatThongTin();
            std::cout << "-------------------------" << std::endl;
        }
    }

    return 0;
}
