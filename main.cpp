#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Menu {
    string code;
    string name;
    int price;
    bool category;
    bool available;
};

vector<Menu> menuList;

void addMenu() {
    Menu newMenu;
    cout << "Enter menu code: ";
    cin >> newMenu.code;
    cout << "Enter menu name: ";
    cin >> newMenu.name;
    cout << "Enter menu price: ";
    cin >> newMenu.price;
    cout << "Enter menu category (1 for makanan, 0 for not minuman): ";
    cin >> newMenu.category;
    cout << "Enter menu status (1 for available, 0 for not available): ";
    cin >> newMenu.available;
    menuList.push_back(newMenu);
    cout << "Menu added successfully!" << endl;
}

void viewMenu() {
    if (menuList.empty()) {
        cout << "No menu available." << endl;
        return;
    }
    cout << "Menu list:" << endl;
    for (const auto& menu : menuList) {
        cout << "Code: " << menu.code << ", Name: " << menu.name << ", Price: " << menu.price
                << ", Category: " << (menu.category ? "Makanan" : "Minuman") << ", Available: " << (menu.available ? "Yes" : "No") << endl;
    }
}

void updateMenuStatus() {
    string code;
    cout << "Enter menu code to update status: ";
    cin >> code;
    for (auto& menu : menuList) {
        if (menu.code == code) {
            cout << "Enter new status (1 for available, 0 for not available): ";
            cin >> menu.available;
            cout << "Menu status updated successfully!" << endl;
            return;
        }
    }
    cout << "Menu not found!" << endl;
}

void admin() {
    cout << "Admin function" << endl;
    int choice;
    do {
        cout << "1. Add Menu\n2. View Menu\n3. Update Menu Status\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addMenu();
                break;
            case 2:
                viewMenu();
                break;
            case 3:
                updateMenuStatus();
                break;
            case 4:
                cout << "Exiting admin menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}

void staff() {
    cout << "Staff function" << endl;
}

int main() {
    string username;
    string password;
    string adminUsername = "admin";
    string staffUsername = "staff";
    string adminPassword = "pass";
    string staffPassword = "pass";

    char choice;

    while (true) {
        cout << "Login" << endl;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (username == adminUsername && password == adminPassword) {
            admin();
        } else if (username == staffUsername && password == staffPassword) {
            staff();
        } else {
            cout << "Login failed. Incorrect username or password." << endl;
        }
    }

    return 0;
}
