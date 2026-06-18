#include "Inventory.h"
#include <fstream>
#include <sstream>
#include <iomanip>

// Item Constructor: Initializes an Item with the given ID, name, quantity, and price.
Item::Item(int id, std::string name, int quantity, double price) {
    this->id = id;
    this->name = name;
    this->quantity = quantity;
    this->price = price;
}

// getId: Returns the unique identifier of the item.
int Item::getId() const {
    return id;
}

// getName: Returns the name of the item.
std::string Item::getName() const {
    return name;
}

// getQuantity: Returns the current quantity of the item in stock.
int Item::getQuantity() const {
    return quantity;
}

// getPrice: Returns the price of a single unit of the item.
double Item::getPrice() const {
    return price;
}

// setQuantity: Updates the quantity of the item.
void Item::setQuantity(int newQuantity) {
    if (newQuantity >= 0) {
        quantity = newQuantity;
    } else {
        std::cout << "Error: Quantity cannot be negative.\n";
    }
}

// setPrice: Updates the price of the item.
void Item::setPrice(double newPrice) {
    if (newPrice >= 0.0) {
        price = newPrice;
    } else {
        std::cout << "Error: Price cannot be negative.\n";
    }
}

// displayItem: Prints the item's details to the standard output.
void Item::displayItem() const {
    std::cout << "ID: " << id 
              << " | Name: " << name 
              << " | Quantity: " << quantity 
              << " | Price: $" << std::fixed << std::setprecision(2) << price << "\n";
}

// toFileString: Formats the item's details as a comma-separated string for file storage.
std::string Item::toFileString() const {
    return std::to_string(id) + "," + name + "," + std::to_string(quantity) + "," + std::to_string(price);
}

// Inventory Constructor: Initializes the inventory system and attempts to load data from the specified file.
Inventory::Inventory(std::string file) {
    filename = file;
    loadFromFile();
}

// addItem: Creates a new Item and adds it to the inventory list, then saves the updated list.
void Inventory::addItem(int id, std::string name, int quantity, double price) {
    for (const auto& item : items) {
        if (item.getId() == id) {
            std::cout << "Error: Item with ID " << id << " already exists.\n";
            return;
        }
    }
    
    Item newItem(id, name, quantity, price);
    items.push_back(newItem);
    std::cout << "Item added successfully.\n";
    saveToFile();
}

// removeItem: Searches for an item by ID and removes it from the inventory if found.
void Inventory::removeItem(int id) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getId() == id) {
            items.erase(it);
            std::cout << "Item removed successfully.\n";
            saveToFile();
            return;
        }
    }
    std::cout << "Error: Item with ID " << id << " not found.\n";
}

// updateQuantity: Searches for an item by ID and updates its stock quantity.
void Inventory::updateQuantity(int id, int newQuantity) {
    for (auto& item : items) {
        if (item.getId() == id) {
            item.setQuantity(newQuantity);
            std::cout << "Quantity updated successfully.\n";
            saveToFile();
            return;
        }
    }
    std::cout << "Error: Item with ID " << id << " not found.\n";
}

// displayInventory: Iterates through the item vector and displays each item.
void Inventory::displayInventory() const {
    if (items.empty()) {
        std::cout << "The inventory is currently empty.\n";
        return;
    }
    
    std::cout << "\n--- Current Inventory ---\n";
    for (const auto& item : items) {
        item.displayItem();
    }
    std::cout << "-------------------------\n";
}

// saveToFile: Writes all inventory items to the file specified during initialization.
void Inventory::saveToFile() const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& item : items) {
            outFile << item.toFileString() << "\n";
        }
        outFile.close();
    } else {
        std::cout << "Error: Unable to open file for saving.\n";
    }
}

// loadFromFile: Reads inventory data from the file and populates the items vector.
void Inventory::loadFromFile() {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        items.clear();
        std::string line;
        
        while (std::getline(inFile, line)) {
            std::stringstream ss(line);
            std::string temp;
            int id, quantity;
            std::string name;
            double price;

            if (std::getline(ss, temp, ',')) id = std::stoi(temp);
            if (std::getline(ss, name, ',')) {}
            if (std::getline(ss, temp, ',')) quantity = std::stoi(temp);
            if (std::getline(ss, temp, ',')) price = std::stod(temp);

            Item loadedItem(id, name, quantity, price);
            items.push_back(loadedItem);
        }
        inFile.close();
    } else {
    }
}
