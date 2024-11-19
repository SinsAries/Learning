#include "Business.h"
#include <iomanip>

Business::Business(int soDem, double phiDichVu)
    : Phong(soDem, phiDichVu) {}

double Business::TinhDoanhThu() const {
    return soDem * 300000;
}

void Business::XuatThongTin() const {
    cout << "Phong Business: ";
    Phong::XuatThongTin();
    cout << fixed << setprecision(2) << "Doanh thu: " << TinhDoanhThu() << endl;
}
