#include <bits/stdc++.h>

using namespace std;

// Chuyển đổi chuỗi hex thành float
float hexSangFloat(const string &hex) {
    unsigned int giaTriInt;
    stringstream ss;
    ss << std::hex << hex;  // Đọc giá trị hex
    ss >> giaTriInt;  // Lưu nó dưới dạng số nguyên
    float giaTriFloat;
    memcpy(&giaTriFloat, &giaTriInt, sizeof(giaTriFloat));  // Sao chép byte sang float
    return giaTriFloat;
}

// Chuyển đổi float thành chuỗi hex không có tiền tố 0x
string floatSangHex(float giaTri) {
    unsigned int giaTriInt;
    memcpy(&giaTriInt, &giaTri, sizeof(giaTri));  // Sao chép byte sang số nguyên
    stringstream ss;
    ss << std::hex << std::setfill('0') << std::setw(8) << giaTriInt; // Định dạng hex không có 0x
    return ss.str();
}

// Nhân và cộng hợp nhất tùy chỉnh: (a * b) + c
float nhanCongHopNhat(float a, float b, float c) {
    return a * b + c;
}

// NAND bitwise
unsigned int nandBitwise(unsigned int a, unsigned int b) {
    return ~(a & b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<string> ketQua;

    for (int t = 0; t < T; ++t) {
        string c0;
        cin >> c0;  // Giá trị ban đầu C[0]

        int L;
        cin >> L;
        vector<vector<string>> bangTraCuu(L);

        for (int i = 0; i < L; ++i) {
            int kichThuoc;
            cin >> kichThuoc;
            bangTraCuu[i].resize(kichThuoc);
            for (int j = 0; j < kichThuoc; ++j) {
                cin >> bangTraCuu[i][j];
            }
        }

        int Q;
        cin >> Q;
        vector<string> giaTri;
        giaTri.push_back(c0);  // Lưu C[0]

        for (int i = 0; i < Q; ++i) {
            string lenh;
            cin >> lenh;

            if (lenh == "C") {
                string h;
                cin >> h;
                giaTri.push_back(h);
            } else if (lenh == "L") {
                int idx, j, b;
                cin >> idx >> j >> b;
                // Tính toán mặt nạ từ C[0]
                unsigned int matNa = (stoul(giaTri[0], nullptr, 16) >> j) & ((1 << b) - 1);
                giaTri.push_back(bangTraCuu[idx][matNa]);
            } else if (lenh == "N") {
                int idx1, idx2;
                cin >> idx1 >> idx2;
                unsigned int giaTriA = stoul(giaTri[idx1], nullptr, 16);
                unsigned int giaTriB = stoul(giaTri[idx2], nullptr, 16);
                unsigned int ketQuaNand = nandBitwise(giaTriA, giaTriB);
                float ketQuaTamThoi = *reinterpret_cast<float*>(&ketQuaNand);
                giaTri.push_back(floatSangHex(ketQuaTamThoi));
            } else if (lenh == "F") {
                int idx1, idx2, idx3;
                cin >> idx1 >> idx2 >> idx3;
                float giaTriA = hexSangFloat(giaTri[idx1]);
                float giaTriB = hexSangFloat(giaTri[idx2]);
                float giaTriC = hexSangFloat(giaTri[idx3]);
                float ketQuaFMA = nhanCongHopNhat(giaTriA, giaTriB, giaTriC);  // Sử dụng hàm đã đổi tên
                giaTri.push_back(floatSangHex(ketQuaFMA));
            }
        }

        ketQua.push_back(giaTri.back());
    }

    for (const auto &ketQuaCuoi : ketQua) {
        cout << ketQuaCuoi << '\n';  // Xuất mà không có tiền tố 0x
    }

    return 0;
}