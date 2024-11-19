#include "GiaSuc.h"

GiaSuc::GiaSuc(int soLuong) : soLuong(soLuong) {}

void GiaSuc::XuatThongTin() const {
    cout << "So luong: " << soLuong << endl;
}

int GiaSuc::getSoLuong() const {
    return soLuong;
}

GiaSuc::~GiaSuc() {}
