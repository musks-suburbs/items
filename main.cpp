// main.cpp
#include <iostream>
#include "Item.h"
#include "Inventory.h"

int getNumericInput(const std::string& prompt) {
    int input;
    while (true) {
        std::cout << prompt;
        if (std::cin >> input) {
            return input;
        } else {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void displayInventory(const Inventory& inventory) {
    std::cout << "\nInventory:" << std::endl;
    for (const auto& item : inventory.getItems()) {
        std::cout << item.getName() << " - $" << item.getPrice() << std::endl;
    }
}

int main() {
    Inventory inventory;

    while (true) {
        std::cout << "\nMenu:\n1. Add Item\n2. View Inventory\n3. Exit\nEnter your choice: ";
        int choice = getNumericInput("");

        switch (choice) {
            case 1: {
                std::string itemName;
                double itemPrice;

                std::cout << "Enter item name: ";
                std::cin.ignore();
                std::getline(std::cin, itemName);

                itemPrice = getNumericInput("Enter item price: ");
                Item newItem(itemName, itemPrice);
                inventory.addItem(newItem);
                std::cout << "Item added to inventory." << std::endl;
                break;
            }
            case 2:
                displayInventory(inventory);
                break;
            case 3:
                std::cout << "Exiting the application. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    }

    return 0;
}
