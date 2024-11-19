#include "Deluxe.h"
#include <iomanip>

Deluxe::Deluxe(int soDem, double phiDichVu, double phiPhucVu)
    : Phong(soDem, phiDichVu), phiPhucVu(phiPhucVu) {}

double Deluxe::TinhDoanhThu() const {
    return soDem * 750000 + phiDichVu + phiPhucVu;
}

void Deluxe::XuatThongTin() const {
    cout << "Phong Deluxe: ";
    Phong::XuatThongTin();
    cout << fixed << setprecision(2) << "Phi phuc vu: " << phiPhucVu << ", Doanh thu: " << TinhDoanhThu() << endl;
}
