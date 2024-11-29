#include "NonMemberCustomer.h"

NonMemberCustomer::NonMemberCustomer(std::string name, std::string idCard, int months, bool usingPT, int numsOfClasses)
    : Customer(name, idCard, months, usingPT, numsOfClasses) {}

int NonMemberCustomer::calculateSpent() {
    // Phí cơ bản cho Non-member
    int basicFee = 200;
    int classFee = 0; // Không có lớp học cho Non-member
    int ptFee = 200; // 200 VND mỗi tháng hỗ trợ PT cho Non-member

    return (basicFee + classFee * numsOfClasses + ptFee * usingPT) * months;
}
