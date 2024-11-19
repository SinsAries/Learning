#include "Bo.h"

Bo::Bo(int soLuong) : GiaSuc(soLuong) {}

string Bo::TiengKeu() const {
    return "Boo";
}

int Bo::SinhCon() const {
    return rand() % 21; // Số con sinh ra từ 0-20
}

int Bo::ChoSua() const {
    return rand() % 21; // Lượng sữa từ 0-20 lít
}
