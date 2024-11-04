#include <iostream>
#include "thoigian.h"

int main() {
    ThoiGian tg1(1, 30, 45);   // 1 giờ, 30 phút, 45 giây
    ThoiGian tg2(0, 45, 30);   // 0 giờ, 45 phút, 30 giây

    // Test cộng và trừ thời gian với giây
    ThoiGian tg3 = tg1 + 3600;
    ThoiGian tg4 = tg1 - 600;

    // Hiển thị kết quả
    std::cout << "Thời gian tg1: " << tg1 << std::endl;
    std::cout << "Thời gian tg2: " << tg2 << std::endl;
    std::cout << "Thời gian tg1 + 3600 giây: " << tg3 << std::endl;
    std::cout << "Thời gian tg1 - 600 giây: " << tg4 << std::endl;

    // Test so sánh
    std::cout << "tg1 == tg2: " << (tg1 == tg2 ? "Đúng" : "Sai") << std::endl;
    std::cout << "tg1 > tg2: " << (tg1 > tg2 ? "Đúng" : "Sai") << std::endl;

    // Test toán tử nhập xuất
    ThoiGian tg5;
    std::cout << "Nhập thời gian tg5:" << std::endl;
    std::cin >> tg5;
    std::cout << "Thời gian tg5: " << tg5 << std::endl;

    return 0;
}
