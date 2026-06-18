#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <vector>

// Item class to represent an individual item in the inventory
class Item {
private:
    int id;
    std::string name;
    int quantity;
    double price;

public:
    // Constructor
    Item(int id, std::string name, int quantity, double price);

    // Getters
    int getId() const;
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;

    // Setters
    void setQuantity(int newQuantity);
    void setPrice(double newPrice);

    // Display the item information
    void displayItem() const;
    
    // Format item for saving to a file
    std::string toFileString() const;
};

// Inventory class to manage a collection of items
class Inventory {
private:
    std::vector<Item> items;
    std::string filename;

public:
    // Constructor
    Inventory(std::string file);

    // Add a new item to the inventory
    void addItem(int id, std::string name, int quantity, double price);

    // Remove an item by its ID
    void removeItem(int id);

    // Update the quantity of an item
    void updateQuantity(int id, int newQuantity);

    // Display all items in the inventory
    void displayInventory() const;

    // Save the current state of the inventory to a file
    void saveToFile() const;

    // Load the inventory state from a file
    void loadFromFile();
};

#endif // INVENTORY_H
