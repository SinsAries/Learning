#!/bin/bash

read -p "Nhập ID sinh viên: " id

while IFS=";" read -r StudentID Name Grade; do
    if [[ "$StudentID" == "$id" ]]; then
        Grade=$(echo "$Grade" | tr -d '[:space:]')
        echo "Tên: $Name"
        echo "Điểm gốc : $Grade"
        if [ $Grade -ge 900 ]; then
            echo "Điểm chữ: A+"
        elif [ $Grade -ge 800 ]; then
            echo "Điểm chữ: A"
        elif [ $Grade -ge 700 ]; then
            echo "Điểm chữ: B+"
        elif [ $Grade -ge 600 ]; then
            echo "Điểm chữ: B"
        elif [ $Grade -ge 500 ]; then
            echo "Điểm chữ: C"
        else
            echo "D/F"
        fi
        exit 0
    fi
done < gradebook.csv

echo "Không tìm thấy sinh viên với ID $id"
