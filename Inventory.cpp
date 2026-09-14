#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Item {
private:
    string name;
    int quantity;
    double unitPrice;

public:
    Item(string n, int q, double p) {
        name = n;
        quantity = q;
        unitPrice = p;
    }

    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getUnitPrice() const { return unitPrice; }

    bool updateQuantity(int change) {
        if (quantity + change < 0) {
            return false;
        }
        quantity += change;
        return true;
    }

    double getTotalValue() const {
        return quantity * unitPrice;
    }
};

class Inventory {
private:
    vector<Item> items;

public:
    void addItem() {
        string name;
        int quantity;
        double price;

        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter unit price: ";
        cin >> price;

        if (quantity < 0 || price < 0) {
            cout << "Invalid quantity or price!\n";
            return;
        }

        items.push_back(Item(name, quantity, price));
        cout << "Item \"" << name << "\" added.\n";
    }

    void removeItem() {
        string name;
        cout << "Enter item name to remove: ";
        cin >> name;

        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getName() == name) {
                items.erase(it);
                cout << "Item \"" << name << "\" removed successfully.\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

    void updateStock() {
        string name;
        int change;
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter quantity change: ";
        cin >> change;

        for (size_t i = 0; i < items.size(); i++) {
            if (items[i].getName() == name) {
                if (items[i].updateQuantity(change)) {
                    cout << "Updated quantity: " << items[i].getQuantity() << "\n";
                } else {
                    cout << "Error: Stock quantity cannot go negative!\n";
                }
                return;
            }
        }
        cout << "Item not found.\n";
    }

    void searchItem() {
        string name;
        cout << "Enter item name to search: ";
        cin >> name;

        for (size_t i = 0; i < items.size(); i++) {
            if (items[i].getName() == name) {
                cout << "Found: " << items[i].getName() << " | Qty: " << items[i].getQuantity() 
                     << " | Price: " << items[i].getUnitPrice() << " EGP\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

    void displayInventory() {
        if (items.empty()) {
            cout << "Inventory is empty.\n";
            return;
        }

        double totalInventoryValue = 0;
        for (size_t i = 0; i < items.size(); i++) {
            cout << "Item: " << items[i].getName() << " | Qty: " << items[i].getQuantity() 
                 << " | Price: " << items[i].getUnitPrice() << " EGP | Total: " << items[i].getTotalValue() << " EGP\n";
            totalInventoryValue += items[i].getTotalValue();
        }
        cout << "-------------------------------------------\n";
        cout << "Total Inventory Value: " << totalInventoryValue << " EGP\n";
    }
};

int main() {
    Inventory myInventory;
    int choice;

    while (true) {
        cout << "\n=== Inventory Management System ===\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Update Quantity\n";
        cout << "4. Search Item\n";
        cout << "5. Display Inventory\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) myInventory.addItem();
        else if (choice == 2) myInventory.removeItem();
        else if (choice == 3) myInventory.updateStock();
        else if (choice == 4) myInventory.searchItem();
        else if (choice == 5) myInventory.displayInventory();
        else if (choice == 6) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid option! Try again.\n";
        }
    }
    return 0;
}
