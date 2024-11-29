#include "PremiumCustomer.h"

PremiumCustomer::PremiumCustomer(std::string name, std::string idCard, int months, bool usingPT, int numsOfClasses)
    : Customer(name, idCard, months, usingPT, numsOfClasses) {}

int PremiumCustomer::calculateSpent() {
    // Phí cơ bản cho Premium
    int basicFee = 1000;
    int classFee = 0; // Miễn phí với Premium
    int ptFee = 0; // Miễn phí với Premium

    return (basicFee + classFee * numsOfClasses + ptFee * usingPT) * months;
}
