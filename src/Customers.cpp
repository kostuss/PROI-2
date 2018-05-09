#include <vector>
#include <iostream>
#include "Customer.h"
#include "Customers.h"

using namespace std;
Customers::Customers() {
    front=NULL;
}
Customers::~Customers() {
    while (front!=NULL)
        pop();
}
void Customers:: pop() {

    if(front == NULL)
        std::cout<<"No customers\n";
    else
    {
        front=front->getLink();
    }
}
void Customers::printCustomer(Customer *ptr) {
    cout << "Customer: " << ptr->getName() << "| Is vip: " << ptr->isVIP() <<endl;

}
void Customers:: showCustomers() {
    Customer *ptr;
    ptr = front;

    if (front == NULL)
        cout<<"No customers left\n";
    else
    {
        cout << endl;
        while(ptr != NULL)
        {
            printCustomer(ptr);
            ptr=ptr->getLink();
        }
    }
}
void Customers:: addCustomer(std::string name, bool vip) {
    Customer *tmp, *q;
    tmp = new Customer(name, vip);


    if (front == NULL || vip > front->isVIP()){

        tmp->setLink(front);
        front = tmp;

    }
    else
    {

        q = front;
        while (q->getLink() != NULL && q->getLink()->isVIP() >= vip) {
            q=q->getLink();
        }

        tmp->setLink(q->getLink());
        q->setLink(tmp);

    }
}