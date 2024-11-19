#ifndef DELUXE_H
#define DELUXE_H

#include "Phong.h"

class Deluxe : public Phong {
private:
    double phiPhucVu;

public:
    Deluxe(int soDem, double phiDichVu, double phiPhucVu);
    double TinhDoanhThu() const override;
    void XuatThongTin() const override;
};

#endif
