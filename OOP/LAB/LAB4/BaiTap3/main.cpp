#include <iostream>
#include <vector>
#include "Bo.h"
#include "Cuu.h"
#include "De.h"
#include <ctime> // Để khởi tạo giá trị ngẫu nhiên

using namespace std;

int main() {
    srand(time(0)); // Khởi tạo seed cho giá trị ngẫu nhiên

    // Nhập số lượng gia súc ban đầu
    int soBo, soCuu, soDe;
    cout << "Nhap so luong Bo: ";
    cin >> soBo;
    cout << "Nhap so luong Cuu: ";
    cin >> soCuu;
    cout << "Nhap so luong De: ";
    cin >> soDe;

    // Khởi tạo đối tượng
    Bo bo(soBo);
    Cuu cuu(soCuu);
    De de(soDe);

    // Phần a: Tất cả gia súc đói, in tiếng kêu
    cout << "\nTieng keu cua tat ca gia suc:\n";
    for (int i = 0; i < bo.getSoLuong(); i++) cout << bo.TiengKeu() << " ";
    for (int i = 0; i < cuu.getSoLuong(); i++) cout << cuu.TiengKeu() << " ";
    for (int i = 0; i < de.getSoLuong(); i++) cout << de.TiengKeu() << " ";
    cout << endl;

    // Phần b: Tính lượng sữa và số con sinh ra
    int tongSua = 0, tongCon = 0;

    // Bo
    tongSua += bo.getSoLuong() * bo.ChoSua();
    tongCon += bo.getSoLuong() * bo.SinhCon();

    // Cuu
    tongSua += cuu.getSoLuong() * cuu.ChoSua();
    tongCon += cuu.getSoLuong() * cuu.SinhCon();

    // De
    tongSua += de.getSoLuong() * de.ChoSua();
    tongCon += de.getSoLuong() * de.SinhCon();

    cout << "\nTong so con sinh ra: " << tongCon << endl;
    cout << "Tong luong sua thu duoc: " << tongSua << " lit" << endl;

    return 0;
}
