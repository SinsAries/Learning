#include "Premium.h"
#include <iomanip>

Premium::Premium(int soDem, double phiDichVu)
    : Phong(soDem, phiDichVu) {}

double Premium::TinhDoanhThu() const {
    return soDem * 500000 + phiDichVu;
}

void Premium::XuatThongTin() const {
    cout << "Phong Premium: ";
    Phong::XuatThongTin();
    cout << fixed << setprecision(2) << "Doanh thu: " << TinhDoanhThu() << endl;
}
