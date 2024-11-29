#ifndef PREMIUMCUSTOMER_H
#define PREMIUMCUSTOMER_H

#include "Customer.h"

class PremiumCustomer : public Customer {
public:
    PremiumCustomer(std::string name, std::string idCard, int months, bool usingPT, int numsOfClasses);

    // Override phương thức tính chi phí cho khách Premium
    int calculateSpent() override;
};

#endif
