#include <iostream>
#include <string>
#include "Inventory.h"

// displayMenu: Prints the available options to the user.
void displayMenu() {
    std::cout << "\n==============================\n";
    std::cout << "      INVENTORY SYSTEM      \n";
    std::cout << "==============================\n";
    std::cout << "1. Add a new item\n";
    std::cout << "2. Remove an item\n";
    std::cout << "3. Update item quantity\n";
    std::cout << "4. View inventory\n";
    std::cout << "5. Exit\n";
    std::cout << "==============================\n";
    std::cout << "Enter your choice (1-5): ";
}

// main: The entry point of the application.
// Contains the main loop to handle user interaction.
int main() {
    Inventory myInventory("inventory_data.txt");
    
    int choice = 0;
    
    while (choice != 5) {
        displayMenu();
        
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                int id, qty;
                std::string name;
                double price;
                
                std::cout << "Enter Item ID (integer): ";
                std::cin >> id;
                std::cout << "Enter Item Name (single word): ";
                std::cin >> name;
                std::cout << "Enter Quantity: ";
                std::cin >> qty;
                std::cout << "Enter Price: ";
                std::cin >> price;
                
                myInventory.addItem(id, name, qty, price);
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter the ID of the item to remove: ";
                std::cin >> id;
                
                myInventory.removeItem(id);
                break;
            }
            case 3: {
                int id, newQty;
                std::cout << "Enter Item ID to update: ";
                std::cin >> id;
                std::cout << "Enter the new quantity: ";
                std::cin >> newQty;
                
                myInventory.updateQuantity(id, newQty);
                break;
            }
            case 4: {
                myInventory.displayInventory();
                break;
            }
            case 5: {
                std::cout << "Exiting system. Goodbye!\n";
                break;
            }
            default: {
                std::cout << "Invalid choice. Please select a number between 1 and 5.\n";
                break;
            }
        }
    }

    return 0;
}
