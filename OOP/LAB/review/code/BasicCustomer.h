#ifndef BASICCUSTOMER_H
#define BASICCUSTOMER_H

#include "Customer.h"

class BasicCustomer : public Customer {
public:
    BasicCustomer(std::string name, std::string idCard, int months, bool usingPT, int numsOfClasses);

    // Override phương thức tính chi phí cho khách Basic
    int calculateSpent() override;
};

#endif
