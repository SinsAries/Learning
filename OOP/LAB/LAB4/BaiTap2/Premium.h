#ifndef PREMIUM_H
#define PREMIUM_H

#include "Phong.h"

class Premium : public Phong {
public:
    Premium(int soDem, double phiDichVu);
    double TinhDoanhThu() const override;
    void XuatThongTin() const override;
};

#endif
