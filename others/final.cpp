#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class sanPham 
{
private:
    string ma, ten, ngaySX, moTa;
    double gia;

public:
    void nhapThongTin() 
    {
        cout << "\nHay nhap ma san pham: ";
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
        cout << "\nMa: " << ma << "\nTen: " << ten  << "\nGia: " << gia 
             << "\nNgay san xuat: "<< ngaySX << "\nMo ta: " << moTa << endl;
    }

    bool operator<(const sanPham &sp) const
    {
        return gia < sp.gia;
    }

    string getMa() const { return ma; }
    string getTen() const { return ten; }
    double getGia() const { return gia; }

    void setTen(const string &newTen) { ten = newTen; }
    void setGia(double newGia) { gia = newGia; }

    void luuVaoFile(ofstream &file) const 
    {
        unsigned int size = ma.length();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        file.write(ma.c_str(), size);

        size = ten.length();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        file.write(ten.c_str(), size);

        file.write(reinterpret_cast<const char*>(&gia), sizeof(gia));

        size = ngaySX.length();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        file.write(ngaySX.c_str(), size);

        size = moTa.length();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        file.write(moTa.c_str(), size);
    }

    void docTuFile(ifstream &file) 
    {
        unsigned int size;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        ma.resize(size);
        file.read(&ma[0], size);

        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        ten.resize(size);
        file.read(&ten[0], size);

        file.read(reinterpret_cast<char*>(&gia), sizeof(gia));

        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        ngaySX.resize(size);
        file.read(&ngaySX[0], size);

        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        moTa.resize(size);
        file.read(&moTa[0], size);
    }
};

class quanLySP {
private:
    vector<sanPham> danhSach;
    string tenFile = "sanpham.dat";

public:
    quanLySP() 
    {
        docFile();
    }

    ~quanLySP() 
    {
        luuFile();
    }

    void luuFile() 
    {
        ofstream file(tenFile.c_str(), ios::binary | ios::trunc);
        if (!file.is_open()) {
            cout << "Error: cannot open file " << tenFile << " for writing!" << endl;
            return;
        }
        
        unsigned int size = danhSach.size();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        
        for (const auto &sp : danhSach) {
            sp.luuVaoFile(file);
        }
        cout << "Da luu " << danhSach.size() << " san pham vao file " << tenFile << endl;
        file.close();
    }

    void docFile() {
        ifstream file(tenFile.c_str(), ios::binary);
        if (!file.is_open()) {
            cout << "Khong tim thay file " << tenFile << ". Tao danh sach moi." << endl;
            return;
        }
        
        unsigned int size;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        
        danhSach.clear();
        for (unsigned int i = 0; i < size; i++) {
            sanPham sp;
            sp.docTuFile(file);
            danhSach.push_back(sp);
        }
        cout << "Da doc " << danhSach.size() << " san pham tu file " << tenFile << endl;
        file.close();
    }

    void themSanPham() {
        sanPham sp;
        sp.nhapThongTin();
        danhSach.push_back(sp);
        cout << "San pham da duoc them!" << endl;
    }

    void inTatCaSanPham() const
    {
        cout << "\n       Danh Sach Ne: "<<endl;
        for (const auto &sp : danhSach) {
            sp.inThongTinSP();
        }
    }

    void sapXepTheoGia() 
    {
        sort(danhSach.begin(), danhSach.end());
        cout << "\nDanh sach san pham da duoc sap xep!" << endl;
    }

    void hienThiTop10SanPham() 
    { 
        sort(danhSach.begin(), danhSach.end());
        cout << "\nTOP 10 san pham co gia nho nhat:\n";
        for (unsigned int i = 0; i < 10 && i < danhSach.size(); ++i) {
            cout << i + 1 << ". " << danhSach[i].getTen() << " - Gia: " << danhSach[i].getGia() << endl;
        }
    }

    // New function to update product by its code
    void capNhatThongTin(const string &ma) {
        for (auto &sp : danhSach) {
            if (sp.getMa() == ma) {
                string newTen;
                double newGia;
                cout << "Nhap ten moi cho san pham: ";
                cin.ignore();
                getline(cin, newTen);
                cout << "Nhap gia moi cho san pham: ";
                cin >> newGia;

                sp.setTen(newTen);
                sp.setGia(newGia);

                cout << "Thong tin san pham da duoc cap nhat!" << endl;
                sp.inThongTinSP();
                luuFile(); // Save the updated data to file
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
        cout << "\n  --CHON EM DI-- \n";
        cout << " 1. Nhap san pham\n";
        cout << " 2. In danh sach san pham\n";
        cout << " 3. Sap xep san pham tang dan theo gia\n";
        cout << " 4. Cap nhat thong tin ten va gia theo ma san pham\n";
        cout << " 5. Hien thi top 10 san pham co gia thap nhat\n";
        cout << " 0. Thoat\n";
        cout << "\n--> Chon: ";
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
                quanLy.hienThiTop10SanPham();
                break;
            case 0:
                cout << "\nChuc mung ban da dang xuat khoi chuong trinh!\n";
                break;
            default:
                cout << "\nchon vay la hong duoc roi...CHON LAI DIIII !!!" << endl;
        }
    } while (chon != 0);

    return 0;
}
