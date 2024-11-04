#include "ngaythangnam.h"

// Default constructor
NgayThangNam::NgayThangNam() : iNgay(1), iThang(1), iNam(0) {}

// Constructor with parameters
NgayThangNam::NgayThangNam(int nam, int thang, int ngay) : iNgay(ngay), iThang(thang), iNam(nam) {}

// Kiểm tra năm nhuận
bool NgayThangNam::NamNhuan(int nam) const {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

// Số ngày trong tháng
int NgayThangNam::SoNgayTrongThang(int thang, int nam) const {
    switch (thang) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return NamNhuan(nam) ? 29 : 28;
        default: return 31;
    }
}

// Tính tổng số ngày từ năm 0 đến ngày hiện tại
int NgayThangNam::TinhNgay() const {
    int tongSoNgay = iNgay;
    for (int y = 0; y < iNam; ++y) {
        tongSoNgay += NamNhuan(y) ? 366 : 365;
    }
    for (int m = 1; m < iThang; ++m) {
        tongSoNgay += SoNgayTrongThang(m, iNam);
    }
    return tongSoNgay;
}

// Cập nhật ngày, tháng, năm từ tổng số ngày
void NgayThangNam::TinhLaiNgay(int tongSoNgay) {
    iNam = 0;
    while (tongSoNgay >= (NamNhuan(iNam) ? 366 : 365)) {
        tongSoNgay -= (NamNhuan(iNam) ? 366 : 365);
        iNam++;
    }
    iThang = 1;
    while (tongSoNgay > SoNgayTrongThang(iThang, iNam)) {
        tongSoNgay -= SoNgayTrongThang(iThang, iNam);
        iThang++;
    }
    iNgay = tongSoNgay;
}

// Operator overloading
NgayThangNam NgayThangNam::operator+(int ngay) {
    NgayThangNam res = *this;
    res.TinhLaiNgay(this->TinhNgay() + ngay);
    return res;
}

NgayThangNam NgayThangNam::operator-(int ngay) {
    NgayThangNam res = *this;
    res.TinhLaiNgay(this->TinhNgay() - ngay);
    return res;
}

int NgayThangNam::operator-(const NgayThangNam& other) {
    return this->TinhNgay() - other.TinhNgay();
}

// Prefix increment
NgayThangNam& NgayThangNam::operator++() {
    *this = *this + 1;
    return *this;
}

// Postfix increment
NgayThangNam NgayThangNam::operator++(int) {
    NgayThangNam temp = *this;
    ++(*this);
    return temp;
}

// Prefix decrement
NgayThangNam& NgayThangNam::operator--() {
    *this = *this - 1;
    return *this;
}

// Postfix decrement
NgayThangNam NgayThangNam::operator--(int) {
    NgayThangNam temp = *this;
    --(*this);
    return temp;
}

// Comparison operators
bool NgayThangNam::operator==(const NgayThangNam& other) const {
    return this->TinhNgay() == other.TinhNgay();
}

bool NgayThangNam::operator!=(const NgayThangNam& other) const {
    return !(*this == other);
}

bool NgayThangNam::operator>=(const NgayThangNam& other) const {
    return this->TinhNgay() >= other.TinhNgay();
}

bool NgayThangNam::operator<=(const NgayThangNam& other) const {
    return this->TinhNgay() <= other.TinhNgay();
}

bool NgayThangNam::operator>(const NgayThangNam& other) const {
    return this->TinhNgay() > other.TinhNgay();
}

bool NgayThangNam::operator<(const NgayThangNam& other) const {
    return this->TinhNgay() < other.TinhNgay();
}

// Input and output operators
ostream& operator<<(ostream& os, const NgayThangNam& date) {
    os << date.iNgay << "/" << date.iThang << "/" << date.iNam;
    return os;
}

istream& operator>>(istream& is, NgayThangNam& date) {
    cout << "Nhập ngày: ";
    is >> date.iNgay;
    cout << "Nhập tháng: ";
    is >> date.iThang;
    cout << "Nhập năm: ";
    is >> date.iNam;
    return is;
}
