#!/bin/sh

# thong tin sinh vien
ten_ban="Nguyen Trong Tat Thanh"
mssv="23521455"

# yeu cau nhap thong tin
for i in $(seq 1 5); do
    read -p "Nhap ten sinh vien: " ten_dang_nhap
    read -p "Nhap mssv: " mssv_dang_nhap

    # kiem tra thong tin
    if [ "$ten_dang_nhap" = "$ten_ban" ] && [ "$mssv_dang_nhap" = "$mssv" ]; then
        echo "Dang nhap thanh cong"
        exit 0
    else
        echo "Acess denied. Attempt $i/5"
    fi
done

echo "Da het so lan thu. Dang nhap that bai"