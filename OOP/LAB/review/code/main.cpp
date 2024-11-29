#include <iostream>
#include <vector>
#include <algorithm>
#include "PremiumCustomer.h"
#include "BasicCustomer.h"
#include "NonMemberCustomer.h"

using namespace std;

void addNewCustomer(vector<Customer*>& customers) {
    string name, idCard;
    int type, months, numsOfClasses;
    bool usingPT;

    cout << "Nhập thông tin khách hàng: \n";
    cout << "Tên: ";
    cin >> name;
    cout << "Số CMND: ";
    cin >> idCard;
    cout << "Loại gói dịch vụ (1: Premium, 2: Basic, 3: Non-member): ";
    cin >> type;
    cout << "Số tháng sử dụng dịch vụ: ";
    cin >> months;

    Customer* customer = nullptr;

    // Tạo đối tượng khách hàng tương ứng với từng loại gói dịch vụ
    if (type == 1) {
        customer = new PremiumCustomer(name, idCard, months, true, 0);
    } else if (type == 2) {
        cout << "Có sử dụng dịch vụ PT hay không (1: Có, 0: Không): ";
        cin >> usingPT;
        customer = new BasicCustomer(name, idCard, months, usingPT, 0);
    } else if (type == 3) {
        cout << "Có sử dụng dịch vụ PT hay không (1: Có, 0: Không): ";
        cin >> usingPT;
        cout << "Số lớp học đã tham gia: ";
        cin >> numsOfClasses;
        customer = new NonMemberCustomer(name, idCard, months, usingPT, numsOfClasses);
    }

    customer->addSpent(customer->calculateSpent());
    customers.push_back(customer);
}

bool cmp(Customer* a, Customer* b) {
    return a->getTotalSpent() > b->getTotalSpent();
}

void getTopSpender(vector<Customer*>& customers) {
    // Sắp xếp khách hàng theo chi tiêu từ cao xuống thấp
    std::sort(customers.begin(), customers.end(), cmp);

    // In danh sách khách hàng theo chi tiêu
    std::cout << "Danh sách khách hàng theo chi tiêu giảm dần:" << std::endl;
    for (const auto& customer : customers) {
        std::cout << "CMND: " << customer->getIdCard()
                  << ", Tên: " << customer->getName()
                  << ", Tổng chi tiêu: " << customer->getTotalSpent() << " nghìn VND" << std::endl;
    }
}

int main() {
    vector<Customer*> customers;

    // Nhập thông tin khách hàng
    int numCustomers;
    cout << "Nhập số lượng khách hàng: ";
    cin >> numCustomers;
    for (int i = 0; i < numCustomers; i++) {
        addNewCustomer(customers);
    }

    // In thông tin khách hàng
    for (auto& customer : customers) {
        customer->printInfo();
    }

    // In thông tin khách hàng chi tiêu nhiều nhất theo thứ tự giảm dần
    getTopSpender(customers);

    // Giải phóng bộ nhớ
    for (auto& customer : customers) {
        delete customer;
    }

    return 0;
}
