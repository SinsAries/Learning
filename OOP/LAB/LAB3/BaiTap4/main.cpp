#include <iostream>
#include "ngaythangnam.h"

int main() {
    NgayThangNam d1(2023, 11, 4);
    NgayThangNam d2(2023, 1, 1);

    // Test cộng và trừ ngày
    NgayThangNam d3 = d1 + 10;
    NgayThangNam d4 = d1 - 15;

    std::cout << "Ngày d1: " << d1 << std::endl;
    std::cout << "Ngày d2: " << d2 << std::endl;
    std::cout << "Ngày d1 + 10 ngày: " << d3 << std::endl;
    std::cout << "Ngày d1 - 15 ngày: " << d4 << std::endl;

    // So sánh ngày
    std::cout << "d1 == d2: " << (d1 == d2 ? "Đúng" : "Sai") << std::endl;
    std::cout << "d1 > d2: " << (d1 > d2 ? "Đúng" : "Sai") << std::endl;

    // Nhập ngày
    NgayThangNam d5;
    std::cout << "Nhập ngày d5:" << std::endl;
    std::cin >> d5;
    std::cout << "Ngày d5: " << d5 << std::endl;

    return 0;
}
