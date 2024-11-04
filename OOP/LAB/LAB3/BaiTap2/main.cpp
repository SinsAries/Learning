#include <iostream>
#include "sophuc.h"

int main() {
    // Khởi tạo hai số phức
    SoPhuc sp1(3, 4);  // Số phức 3 + 4i
    SoPhuc sp2(1, 2);  // Số phức 1 + 2i

    // Thử nghiệm các toán tử tính toán
    SoPhuc sum = sp1 + sp2;
    SoPhuc diff = sp1 - sp2;
    SoPhuc product = sp1 * sp2;
    SoPhuc quotient = sp1 / sp2;

    std::cout << "Số phức 1: " << sp1 << std::endl;
    std::cout << "Số phức 2: " << sp2 << std::endl;

    std::cout << "Tổng: " << sum << std::endl;
    std::cout << "Hiệu: " << diff << std::endl;
    std::cout << "Tích: " << product << std::endl;
    std::cout << "Thương: " << quotient << std::endl;

    // Thử nghiệm các toán tử so sánh
    std::cout << "Số phức 1 == Số phức 2: " << (sp1 == sp2 ? "Đúng" : "Sai") << std::endl;
    std::cout << "Số phức 1 != Số phức 2: " << (sp1 != sp2 ? "Đúng" : "Sai") << std::endl;

    // Nhập dữ liệu cho một số phức mới
    SoPhuc sp3;
    std::cout << "Nhập số phức thứ 3:" << std::endl;
    std::cin >> sp3;

    // In ra số phức vừa nhập
    std::cout << "Số phức vừa nhập là: " << sp3 << std::endl;

    return 0;
}
