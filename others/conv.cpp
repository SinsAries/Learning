#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class sanPham {
private:
    string ma, ten, ngaySX, moTa;
    double gia;

public:
    sanPham() {}
    sanPham(const string& ma, const string& ten, double gia, const string& ngaySX, const string& moTa)
        : ma(ma), ten(ten), gia(gia), ngaySX(ngaySX), moTa(moTa) {}

    void luuVaoFile(ofstream &file) const 
    {
        unsigned int size;

        // Save ma san pham
        size = ma.length();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        file.write(ma.c_str(), size);

        // Save ten san pham
        size = ten.length();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        file.write(ten.c_str(), size);

        // Save gia
        file.write(reinterpret_cast<const char*>(&gia), sizeof(gia));

        // Save ngay san xuat
        size = ngaySX.length();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        file.write(ngaySX.c_str(), size);

        // Save mo ta
        size = moTa.length();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        file.write(moTa.c_str(), size);
    }
};

void convertCSVtoDAT(const string& csvFilePath, const string& datFilePath) {
    ifstream csvFile(csvFilePath);
    ofstream datFile(datFilePath, ios::binary | ios::trunc);

    if (!csvFile.is_open()) {
        cout << "Could not open CSV file: " << csvFilePath << endl;
        return;
    }
    if (!datFile.is_open()) {
        cout << "Could not open .dat file for writing: " << datFilePath << endl;
        return;
    }

    string line;
    getline(csvFile, line); // Skip the header line

    vector<sanPham> products;

    while (getline(csvFile, line)) {
        stringstream ss(line);
        string ma, ten, giaStr, ngaySX, moTa;
        double gia;

        // Read each field from the CSV
        getline(ss, ma, ',');
        getline(ss, ten, ',');
        getline(ss, giaStr, ',');
        gia = stod(giaStr); // Convert price to double
        getline(ss, ngaySX, ',');
        getline(ss, moTa, ',');

        // Create a sanPham object
        sanPham sp(ma, ten, gia, ngaySX, moTa);
        products.push_back(sp);
    }

    // Write the number of products to the .dat file
    unsigned int size = products.size();
    datFile.write(reinterpret_cast<const char*>(&size), sizeof(size));

    // Write each product to the .dat file
    for (const auto& product : products) {
        product.luuVaoFile(datFile);
    }

    cout << "Successfully converted CSV to .dat file with " << size << " products." << endl;

    csvFile.close();
    datFile.close();
}

int main() {
    string csvFilePath = "Danh_sach_san_pham_no_accents.csv";
    string datFilePath = "sanpham.dat";
    
    convertCSVtoDAT(csvFilePath, datFilePath);

    return 0;
}
