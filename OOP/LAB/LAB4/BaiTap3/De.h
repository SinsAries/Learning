#ifndef DE_H
#define DE_H

#include "GiaSuc.h"

class De : public GiaSuc {
public:
    De(int soLuong);
    string TiengKeu() const override;
    int SinhCon() const override;
    int ChoSua() const override;
};

#endif
