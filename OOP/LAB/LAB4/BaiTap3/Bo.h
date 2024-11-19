#ifndef BO_H
#define BO_H

#include "GiaSuc.h"

class Bo : public GiaSuc {
public:
    Bo(int soLuong);
    string TiengKeu() const override;
    int SinhCon() const override;
    int ChoSua() const override;
};

#endif
