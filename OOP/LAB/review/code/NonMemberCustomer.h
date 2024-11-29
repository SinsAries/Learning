#ifndef NONMEMBERCUSTOMER_H
#define NONMEMBERCUSTOMER_H

#include "Customer.h"

class NonMemberCustomer : public Customer {
public:
    NonMemberCustomer(std::string name, std::string idCard, int months, bool usingPT, int numsOfClasses);

    // Override phương thức tính chi phí cho khách Non-member
    int calculateSpent() override;
};

#endif
