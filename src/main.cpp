#include "../include/LostFoundSystem.h"
#include "../include/Utilities.h"
#include <iostream>
#include <limits>
#include <filesystem>

void displayMenu() {
    std::cout << "\nMAIN MENU" << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "1. Report Lost Item" << std::endl;
    std::cout << "2. Report Found Item" << std::endl;
    std::cout << "3. View Lost Items" << std::endl;
    std::cout << "4. View Found Items" << std::endl;
    std::cout << "5. Match Lost and Found Items" << std::endl;
    std::cout << "6. Search for Items" << std::endl;
    std::cout << "7. Exit" << std::endl;
    
    std::cout << "\nOption Details:" << std::endl;
    std::cout << "1. Report Lost Item - Report an item you have lost with details like name, location, date, etc." << std::endl;
    std::cout << "2. Report Found Item - Report an item you have found and wish to return to its owner." << std::endl;
    std::cout << "3. View Lost Items - Browse through all reported lost items and view their details." << std::endl;
    std::cout << "4. View Found Items - Browse through all reported found items and view their details." << std::endl;
    std::cout << "5. Match Lost and Found Items - Automatically compare lost and found items to find potential matches." << std::endl;
    std::cout << "6. Search for Items - Search for specific items based on keywords." << std::endl;
    std::cout << "7. Exit - Close the application." << std::endl;
    
    std::cout << "\nEnter your choice (1-7): ";
}

int main() {
    // Create data directory
    std::filesystem::create_directory("data");
    
    LostFoundSystem system;
    int choice;
    
    Utilities::showWelcomeMessage();
    
    do {
        displayMenu();
        
        // Handle input validation
        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Utilities::showErrorMessage("Invalid input. Please enter a number.");
            std::cout << "\nEnter your choice (1-7): ";
        }
        
        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1:
                system.addLostItem();
                break;
                
            case 2:
                system.addFoundItem();
                break;
                
            case 3:
                system.displayLostItems();
                break;
                
            case 4:
                system.displayFoundItems();
                break;
                
            case 5:
                system.matchItems();
                break;
                
            case 6: {
                std::string keyword;
                
                std::cout << "\nSEARCH OPTIONS" << std::endl;
                std::cout << "-------------------" << std::endl;
                std::cout << "1. Search Lost Items" << std::endl;
                std::cout << "2. Search Found Items" << std::endl;
                
                std::cout << "\nEnter your choice (1-2): ";
                
                int searchChoice;
                std::cin >> searchChoice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                std::cout << "Enter search keyword: ";
                std::getline(std::cin, keyword);
                
                if (searchChoice == 1) {
                    system.searchLostItems(keyword);
                } else if (searchChoice == 2) {
                    system.searchFoundItems(keyword);
                } else {
                    Utilities::showErrorMessage("Invalid choice.");
                }
                break;
            }
                
            case 7:
                Utilities::showExitMessage();
                break;
                
            default:
                Utilities::showErrorMessage("Invalid choice. Please enter a number between 1 and 7.");
        }
        
    } while (choice != 7);
    
    return 0;
} 