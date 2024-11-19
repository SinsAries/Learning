#include <iostream>
#include "QuanLy.h"
#include "KySu.h"

using namespace std;

int main() {
    QuanLy quanLy;
    KySu kySu;

    cout << "\n==== Nhap Thong Tin ====\n";
    quanLy.Nhap();
    kySu.Nhap();

    cout << "\n===== Thong Tin Nhan Vien =====\n";
    quanLy.Xuat();
    kySu.Xuat();

    return 0;
}
