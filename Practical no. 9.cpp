
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main()
{
    string productName;
    string orderProduct;

    cout << "Enter the product name: ";
    getline(cin, productName);

    cout << "\nBefore moving:\n";
    cout << "Product name: " << productName << endl;

    // Transfer product information to the order
    orderProduct = std::move(productName);

    cout << "\nAfter moving:\n";
    cout << "Order product: " << orderProduct << endl;

    cout << "Original product string: \""
         << productName << "\"" << endl;

    return 0;
}

