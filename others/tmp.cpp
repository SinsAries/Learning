#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class sanPham 
{
private:
    string ma;
    string ten;
    double gia;
    string ngaySX;
    string moTa;

public:
    void nhapThongTin() 
	{
        cout << "Hay nhap ma san pham: ";
        cin >> ma;
        cin.ignore();
        cout << "Hay nhap ten san pham: ";
        getline(cin, ten);
        cout << "Hay nhap gia san pham: ";
        cin >> gia;
        cin.ignore();
        cout << "Hay nhap ngay san xuat: ";
        getline(cin, ngaySX);
        cout << "Vui long them mo ta san pham: ";
        getline(cin, moTa);
    }

    void inThongTinSP() const
	{
        cout << "Ma: " << ma << "\nTen: " << ten  << "\nGia: " << gia << "\nNgay san xuat: "<< ngaySX << "\nMo ta: " << moTa << endl;
    }

    bool operator<(const sanPham &sp)
    {
        return gia < sp.gia;
    }
    
    string getMa() const { return ma; }
    double getGia() const { return gia; }
    void setTen(const string &newTen) { ten = newTen; }
    void setGia(double newGia) { gia = newGia; }
};

class quanLySP
{
private:
    vector<sanPham> danhSach;

public:
    void themSanPham() 
	{
        sanPham sp;
        sp.nhapThongTin();
        danhSach.push_back(sp);
        cout << "San pham da duoc them!" << endl;
    }

    void inTatCaSanPham() const
	{
        for (size_t i = 0; i < danhSach.size(); i++) {
            danhSach[i].inThongTinSP();
        }
    }

    // Hàm partition
    int partition(int low, int high) 
	{
        double pivot = danhSach[high].getGia();
        int i = low - 1;

        for (int j = low; j < high; j++) 
		{
            if (danhSach[j].getGia() < pivot) 
			{
                i++;
                swap(danhSach[i], danhSach[j]);
            }
        }
        swap(danhSach[i + 1], danhSach[high]);
        return i + 1;
    }

    // Hàm quicksort đệ quy
    void quickSort(int low, int high) 
	{
        if (low < high) 
		{
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    // Hàm gọi quickSort để sắp xếp theo giá tăng dần
    void sapXepTheoGia() 
	{
        quickSort(0, danhSach.size() - 1);
        cout << "Danh sach san pham da duoc sap xep!" << endl;
    }
    
    void capNhatThongTin(const string &ma)
    {
        for (size_t i = 0; i < danhSach.size(); i++) 
        {
            if (danhSach[i].getMa() == ma) 
            {
                string newTen;
                double newGia;
                cout << "Nhap ten moi cho san pham: ";
                cin.ignore();
                getline(cin, newTen);
                cout << "Nhap gia moi cho san pham: ";
                cin >> newGia;
                danhSach[i].setTen(newTen);
                danhSach[i].setGia(newGia);
                cout << "Thong tin san pham da duoc cap nhat!" << endl;
                return;
            }
        }

        cout << "San pham khong ton tai." << endl;
    }
};

int main() 
{
    int chon;
    quanLySP quanLy;
    do {
        cout << "\n CHON EM DI\n";
        cout << "1. Them san pham\n";
        cout << "2. In danh sach san pham\n";
        cout << "3. Sap xep san pham theo gia tang dan\n";
        cout << "4. Cap nhat thong tin ten va gia cua 1 san pham theo ma\n";
        cout << "5. Hien thi top 10 san pham co gia nho nhat\n";
        cout << "6. Luu san pham vao file\n";
        cout << "0. Thoat\n";
        cout << "Xin moi quy khach chon a, hihi: ";
        cin >> chon;

        switch (chon) 
		{
            case 1:
                quanLy.themSanPham();
                break;
            case 2:
                quanLy.inTatCaSanPham();
                break;
            case 3:
                quanLy.sapXepTheoGia();
                break;
            case 4: 
			{
                string ma;
                cout << "Ban hay nhap ma san pham can cap nhat: ";
                cin >> ma; 
                quanLy.capNhatThongTin(ma);
                break;
            }
            case 5:
                // quanLy.hienThiTop10SanPham();
                break;
            case 6:
                // quanLy.luuSanPhamVaoFile();
                break;
            case 0:
                cout << "Chuc mung ban da dang xuat khoi chuong trinh!";
                break;
            default:
                cout << "chon vay la hong duoc roi..." << endl;
        }
    } while (chon != 0);
    return 0;
}
