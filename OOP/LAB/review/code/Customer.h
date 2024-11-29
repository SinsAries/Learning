#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
protected:
    std::string name;
    std::string idCard; // Số chứng minh nhân dân
    int months; // Số tháng sử dụng
    bool usingPT; // Sử dụng dịch vụ PT hay không
    int numsOfClasses; // Số lớp học đã tham gia
    int totalSpent; // Tổng chi tiêu của khách hàng trong tháng

public:
    Customer(std::string name, std::string idCard, int months, bool usingPT, int numsOfClasses);

    // Getter
    std::string getName() const;
    std::string getIdCard() const;
    int getTotalSpent() const;

    // Phương thức tính toán chi phí của một khách hàng (mỗi lớp con sẽ override phương thức này)
    virtual int calculateSpent() = 0;

    // Phương thức in thông tin khách hàng
    void printInfo() const;

    // Phương thức trả về tổng chi tiêu của khách hàng
    void addSpent(int amount);
};

#endif
