#!/bin/sh

read -p "Nhap diem dua tren diem: " diem

if [ $diem -ge 900 ]; then
    echo "A+"
elif [ $diem -ge 800 ]; then
    echo "A"
elif [ $diem -ge 700 ]; then
    echo "B+"
elif [ $diem -ge 600 ]; then
    echo "B"
elif [ $diem -ge 500 ]; then
    echo "C"
else
    echo "D/F"
fi