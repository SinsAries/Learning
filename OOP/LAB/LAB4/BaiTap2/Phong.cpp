#include "Phong.h"
#include <iomanip>

Phong::Phong(int soDem, double phiDichVu)
    : soDem(soDem), phiDichVu(phiDichVu) {}

void Phong::XuatThongTin() const {
    cout << fixed << setprecision(2) << "So dem: " << soDem << ", Phi dich vu: " << phiDichVu << endl;
}

Phong::~Phong() {}
