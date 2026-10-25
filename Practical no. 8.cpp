
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
using namespace std;

int main() {
    string name;
    double units, bill;

    cout << "=== ELECTRICITY BILL CALCULATOR ===\n";

    cout << "Enter consumer name: ";
    getline(cin, name);

    cout << "Enter electricity units consumed: ";

    try {
        if (!(cin >> units)) {
            throw invalid_argument(
                "Units must be a numeric value."
            );
        }

        if (units < 0) {
            throw invalid_argument(
                "Electricity units cannot be negative."
            );
        }

        // Simple bill calculation: Rs. 5 per unit
        bill = units * 5;

        cout << "\n--- Electricity Bill ---\n";
        cout << "Consumer Name: " << name << endl;
        cout << "Units Consumed: " << units << endl;
        cout << "Rate per Unit: Rs. 5" << endl;
        cout << "Total Electricity Bill: Rs. "
             << bill << endl;
    }
    catch (const invalid_argument& e) {
        cout << "\nError: " << e.what() << endl;
    }

    return 0;
}

