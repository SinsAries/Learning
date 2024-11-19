#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <cstring>
#include <iostream>

class NhanVien {
protected:
    char *maNhanVien;
    char *hoTen;
    int tuoi;
    char *soDienThoai;
    char *email;
    float luongCoBan;

public:
    NhanVien();
    NhanVien(const char *maNV, const char *ten, int age, const char *sdt, const char *mail, float luong);
    NhanVien(const NhanVien &nv); // Constructor sao chép
    virtual ~NhanVien(); // Destructor ảo

    virtual void nhapThongTin();
    virtual void xuatThongTin() const;
    virtual float tinhLuong() const = 0; // Phương thức ảo tính lương

    const char* getMaNhanVien() const { return maNhanVien; }
    float getLuongCoBan() const { return luongCoBan; }
};

class LapTrinhVien : public NhanVien {
private:
    int soGioOvertime;

public:
    LapTrinhVien();
    LapTrinhVien(const char *maNV, const char *ten, int age, const char *sdt, const char *mail, float luong, int gioOT);
    LapTrinhVien(const LapTrinhVien &ltv);
    ~LapTrinhVien();

    void nhapThongTin();
    void xuatThongTin() const;
    float tinhLuong() const;
};

class KiemChungVien : public NhanVien {
private:
    int soLoiPhatHien;

public:
    KiemChungVien();
    KiemChungVien(const char *maNV, const char *ten, int age, const char *sdt, const char *mail, float luong, int soLoi);
    KiemChungVien(const KiemChungVien &ktv);
    ~KiemChungVien();

    void nhapThongTin();
    void xuatThongTin() const;
    float tinhLuong() const;
};

#endif
