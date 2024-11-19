#ifndef BUSINESS_H
#define BUSINESS_H

#include "Phong.h"

class Business : public Phong {
public:
    Business(int soDem, double phiDichVu);
    double TinhDoanhThu() const override;
    void XuatThongTin() const override;
};

#endif
