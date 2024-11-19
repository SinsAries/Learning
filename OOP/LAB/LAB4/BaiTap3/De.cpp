#include "De.h"

De::De(int soLuong) : GiaSuc(soLuong) {}

string De::TiengKeu() const {
    return "Meee";
}

int De::SinhCon() const {
    return rand() % 11; // Số con sinh ra từ 0-10
}

int De::ChoSua() const {
    return rand() % 11; // Lượng sữa từ 0-10 lít
}
