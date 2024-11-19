#include "Cuu.h"

Cuu::Cuu(int soLuong) : GiaSuc(soLuong) {}

string Cuu::TiengKeu() const {
    return "Bee";
}

int Cuu::SinhCon() const {
    return rand() % 6; // Số con sinh ra từ 0-5
}

int Cuu::ChoSua() const {
    return rand() % 6; // Lượng sữa từ 0-5 lít
}
