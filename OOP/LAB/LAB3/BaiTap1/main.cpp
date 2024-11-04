#include <iostream>
#include "phanso.h"

int main() {
    // Khởi tạo hai phân số
    PhanSo ps1(3, 4);  // Phân số 3/4
    PhanSo ps2(2, 5);  // Phân số 2/5

    // Thử nghiệm các toán tử tính toán
    PhanSo sum = ps1 + ps2;
    PhanSo diff = ps1 - ps2;
    PhanSo product = ps1 * ps2;
    PhanSo quotient = ps1 / ps2;

    std::cout << "Phân số 1: " << ps1 << std::endl;
    std::cout << "Phân số 2: " << ps2 << std::endl;

    std::cout << "Tổng: " << sum << std::endl;
    std::cout << "Hiệu: " << diff << std::endl;
    std::cout << "Tích: " << product << std::endl;
    std::cout << "Thương: " << quotient << std::endl;

    // Thử nghiệm các toán tử so sánh
    std::cout << "Phân số 1 == Phân số 2: " << (ps1 == ps2) << std::endl;
    std::cout << "Phân số 1 != Phân số 2? " << (ps1 != ps2 ? "Đúng" : "Sai") << std::endl;
    std::cout << "Phân số 1 > Phân số 2? " << (ps1 > ps2 ? "Đúng" : "Sai") << std::endl;
    std::cout << "Phân số 1 < Phân số 2? " << (ps1 < ps2 ? "Đúng" : "Sai") << std::endl;
    std::cout << "Phân số 1 >= Phân số 2? " << (ps1 >= ps2 ? "Đúng" : "Sai") << std::endl;
    std::cout << "Phân số 1 <= Phân số 2? " << (ps1 <= ps2 ? "Đúng" : "Sai") << std::endl;

    // Nhập dữ liệu cho một phân số mới
    PhanSo ps3;
    std::cout << "Nhập phân số thứ 3:" << std::endl;
    std::cin >> ps3;

    // In ra phân số vừa nhập
    std::cout << "Phân số vừa nhập là: " << ps3 << std::endl;

    return 0;
}