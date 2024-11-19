#ifndef CUU_H
#define CUU_H

#include "GiaSuc.h"

class Cuu : public GiaSuc {
public:
    Cuu(int soLuong);
    string TiengKeu() const override;
    int SinhCon() const override;
    int ChoSua() const override;
};

#endif
