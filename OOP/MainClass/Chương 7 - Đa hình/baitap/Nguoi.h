#ifndef NGUOI_H
#define NGUOI_H

#include <iostream>
#include <cstring>

class Nguoi {
protected:
    char *HoTen;
    int NamSinh;

public:
    Nguoi();
    Nguoi(const char *ht, int ns);
    virtual ~Nguoi();
    virtual void Nhap();
    virtual void Xuat() const;
    
    const char* getHoTen() const;
};

#endif // NGUOI_H
