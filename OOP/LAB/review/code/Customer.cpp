#include "Customer.h"
#include <iostream>

Customer::Customer(std::string name, std::string idCard, int months, bool usingPT, int numsOfClasses)
    : name(name), idCard(idCard), months(months), usingPT(usingPT), numsOfClasses(numsOfClasses), totalSpent(0)  {}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getIdCard() const {
    return idCard;
}

int Customer::getTotalSpent() const {
    return totalSpent;
}

void Customer::printInfo() const {
    std::cout << "Tên: " << name << "\n";
    std::cout << "Số CMND: " << idCard << "\n";
    std::cout << "Tổng tiền chi tiêu: " << totalSpent << " nghìn VND\n";
}

void Customer::addSpent(int amount) {
    totalSpent += amount;
}