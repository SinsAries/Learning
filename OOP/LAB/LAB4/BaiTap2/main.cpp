#include <iostream>
#include <vector>
#include <typeinfo>
#include <iomanip>
#include "Deluxe.h"
#include "Premium.h"
#include "Business.h"

using namespace std;

int main() {
    // Khởi tạo 5 phòng
    Deluxe a(5, 200000, 100000);   // Deluxe: 5 đêm, phí dịch vụ: 200k, phí phục vụ: 100k
    Deluxe b(3, 150000, 50000);   // Deluxe: 3 đêm, phí dịch vụ: 150k, phí phục vụ: 50k
    Premium c(4, 100000);         // Premium: 4 đêm, phí dịch vụ: 100k
    Premium d(2, 50000);          // Premium: 2 đêm, phí dịch vụ: 50k
    Business e(6, 0);             // Business: 6 đêm, không phí dịch vụ

    // Lưu các phòng vào một danh sách
    vector<Phong*> danhSachPhong = {&a, &b, &c, &d, &e};

    // Xuất thông tin và tìm loại phòng có doanh thu cao nhất
    double doanhThuMax = 0;
    string loaiPhongMax;
    for (auto phong : danhSachPhong) {
        phong->XuatThongTin();
        double doanhThu = phong->TinhDoanhThu();
        if (doanhThu > doanhThuMax) {
            doanhThuMax = doanhThu;

            // Xác định loại phòng
            if (dynamic_cast<Deluxe*>(phong)) {
                loaiPhongMax = "Deluxe";
            } else if (dynamic_cast<Premium*>(phong)) {
                loaiPhongMax = "Premium";
            } else if (dynamic_cast<Business*>(phong)) {
                loaiPhongMax = "Business";
            }
        }
    }

    // Hiển thị loại phòng có doanh thu cao nhất
    cout << fixed << setprecision(2) << "\nLoai phong co doanh thu cao nhat: " << loaiPhongMax
         << " voi doanh thu: " << doanhThuMax << endl;

    return 0;
}
