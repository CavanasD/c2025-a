#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Item {
    string model;
    long long quantity;
};

class WareHouse {
private:
    vector<Item> inventory; //List!
    const string filename = "item.txt";

public:
    WareHouse() {
        loadWare();
    }
    ~WareHouse() {
        saveWare();
    }

    void loadWare() {
        ifstream fin(filename);
        if (!fin.is_open()) {
            cout << "File Not Found, Constructing New File..." << endl;
            return;
        }
        Item item;
        while (fin >> item.model >> item.quantity) {
            inventory.push_back(item);
        }
        fin.close();
    }

    void saveWare() {
        ofstream fout(filename);
        for (auto &item : inventory) {
            fout << item.model << " " << item.quantity << endl;
        }
        fout.close();
    }

    void showInventory() {
        cout << "=== List of WareHouse ===" << endl;
        if (inventory.empty()) {
            cout << "No Inventory" << endl;
            return;
        }
        int index = 1;
        for (auto &item : inventory) {
            cout << index++ << ". MODEL : " << item.model
                 << ", QUANTITY: " << item.quantity << endl;
        }
    }

    void itemAdd() {
        string model;
        int quantity;
        cout << "Please Input the model: ";
        cin >> model;
        cout << "Please Input the Quantity: ";
        cin >> quantity;

        for (auto &item : inventory) {
            if (item.model == model) {
                item.quantity += quantity;
                cout << "Item Updated. Model:" << model
                     << " Quantity added to:  " << item.quantity << endl;
                return;
            }
        }
        inventory.push_back({model, quantity});
        cout << "Updated Successfully " << model
             << " Quantity: " << quantity << endl;
    }

    void itemOut() {
        string model;
        int quantity;
        cout << "Input the model: ";
        cin >> model;
        cout << "Input the Quantity: ";
        cin >> quantity;

        for (auto &item : inventory) {
            if (item.model == model) {
                if (item.quantity < quantity) {
                    cout << "Inventory is not Enough: " << item.quantity << endl;
                    return;
                }
                item.quantity -= quantity;
                cout << "Output Successfully, Model: " << model
                     << " Now " << item.quantity << "Left" << endl;
                return;
            }
        }
        cout << "Not FOund Such Inventory" << endl;
    }

    void menu() {
        int choice;
        while (true) {
            cout << "\n===== WareHouse =====" << endl;
            cout << "1. List" << endl;
            cout << "2. In" << endl;
            cout << "3. Out" << endl;
            cout << "4. Exit" << endl;
            cout << "Select a choice: ";
            cin >> choice;

            switch (choice) {
                case 1: showInventory(); break;
                case 2: itemAdd(); break;
                case 3: itemOut(); break;
                case 4: cout << "Saved and Exited" << endl; return;
                default: cout << "ERROR@!" << endl;
            }
        }
    }
};

int main() {
    WareHouse system;
    system.menu();
    return 0;
}
