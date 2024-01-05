#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;

struct MenuItem {
    string name;
    double price;
};

void showMenu(const map<string, MenuItem>& menu) {
    cout << "Menu:" << endl;
   // for (const auto& item : menu) {
    //    cout << item.first << "\t$" << fixed << setprecision(2) << item.second.price << endl;
    //}
    cout << "Quit\tQuit the order" << endl;
}

void saveBill(const map<string, MenuItem>& menu, const map<string, int>& orders) {
    ofstream outputFile("bills.txt");

    if (!outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    outputFile << "Bill Details:" << endl;
   // for (const auto& order : orders) {
    //    outputFile << order.first << "\t$" << fixed << setprecision(2) << menu.at(order.first).price << "\tQuantity: " << order.second << endl;
    //}

    double totalAmount = 0.0;
   // for (const auto& order : orders) {
    //    totalAmount += menu.at(order.first).price * order.second;
    //}
    totalAmount += (totalAmount * 0.05); // Adding 5% tax

    outputFile << "Total Amount (including 5% tax): $" << fixed << setprecision(2) << totalAmount << endl;

    outputFile.close();
}

int main() {
    map<string, MenuItem> menu = {
        {"Omelet", { "Omelet", 1.45 }},
        {"French Omelet", { "French Omelet", 2.45 }},
        {"Muffin", { "Muffin", 0.99 }},
        {"French Toast", { "French Toast", 1.99 }},
        {"Fruit Basket", { "Fruit Basket", 2.49 }},
        {"Cereal", { "Cereal", 0.69 }},
        {"Coffee", { "Coffee", 0.75 }},
        {"Tea", { "Tea", 0.50 }}
    };

    map<string, int> orders;

    char choice;
    do {
        showMenu(menu);

        cout << "Enter your choice (or type 'Quit' to finish): ";
        cin >> choice;

        if (menu.find(choice) != menu.end() && choice != "Quit") {
            cout << "Enter quantity: ";
            int quantity;
            cin >> quantity;

            // Update or insert the order
            orders[choice] += quantity;
        } else if (choice != "Quit") {
            cout << "Invalid choice. Please select an item from the menu." << endl;
        }

    } while (choice != "Quit");

    saveBill(menu, orders);

    cout << "Bill saved successfully." << endl;

    return 0;
}

