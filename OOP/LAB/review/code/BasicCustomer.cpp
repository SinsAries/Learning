#include "BasicCustomer.h"

BasicCustomer::BasicCustomer(std::string name, std::string idCard, int months, bool usingPT, int numsOfClasses)
    : Customer(name, idCard, months, usingPT, numsOfClasses) {}

int BasicCustomer::calculateSpent() {
    // Phí cơ bản cho Basic
    int basicFee = 500;
    int classFee = 100; // 100 VND mỗi lớp cho Basic
    int ptFee = 100; // 100 VND mỗi tháng hỗ trợ PT cho Basic

    return (basicFee + classFee * numsOfClasses + ptFee * usingPT) * months;
}
