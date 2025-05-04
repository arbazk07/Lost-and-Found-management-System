#include "../include/LostFoundSystem.h"
#include "../include/Utilities.h"
#include <filesystem>
#include <sstream>
#include <algorithm>

LostFoundSystem::LostFoundSystem() {
    // Create data directory if it doesn't exist
    if (!std::filesystem::exists("data")) {
        std::filesystem::create_directory("data");
    }
    loadItems();
}

void LostFoundSystem::loadItems() {
    // Load lost items
    std::ifstream lostFile("data/lost_items.txt");
    if (lostFile.is_open()) {
        std::string line;
        while (std::getline(lostFile, line)) {
            std::string itemName, location, description, date, reporterName, contact;
            parseCSVLine(line, itemName, location, description, date, reporterName, contact);
            
            User reporter(reporterName, contact);
            LostItem item(itemName, location, description, date, reporter);
            lostItems.push_back(item);
        }
        lostFile.close();
    }

    // Load found items
    std::ifstream foundFile("data/found_items.txt");
    if (foundFile.is_open()) {
        std::string line;
        while (std::getline(foundFile, line)) {
            std::string itemName, location, description, date, reporterName, contact;
            parseCSVLine(line, itemName, location, description, date, reporterName, contact);
            
            User reporter(reporterName, contact);
            FoundItem item(itemName, location, description, date, reporter);
            foundItems.push_back(item);
        }
        foundFile.close();
    }
}

void LostFoundSystem::parseCSVLine(const std::string& line, std::string& itemName, std::string& location, 
                                  std::string& description, std::string& date, std::string& reporterName, 
                                  std::string& contact) {
    std::stringstream ss(line);
    std::string token;
    
    std::getline(ss, itemName, ',');
    std::getline(ss, location, ',');
    std::getline(ss, description, ',');
    std::getline(ss, date, ',');
    std::getline(ss, reporterName, ',');
    std::getline(ss, contact, ',');
}

void LostFoundSystem::addLostItem() {
    Utilities::showInfoMessage("Report a Lost Item");
    
    std::string reporterName = Utilities::getValidInput("Enter your name: ", false);
    std::string contact = Utilities::getValidInput("Enter your contact: ", false);
    std::string itemName = Utilities::getValidInput("Enter item name: ", false);
    std::string location = Utilities::getValidInput("Enter location where item was lost: ", false);
    std::string description = Utilities::getValidInput("Enter item description: ", false);
    
    std::string date;
    bool validDate = false;
    while (!validDate) {
        date = Utilities::getValidInput("Enter date lost (DD-MM-YYYY): ", false);
        validDate = Utilities::isValidDate(date);
        if (!validDate) {
            Utilities::showErrorMessage("Invalid date format. Please use DD-MM-YYYY.");
        }
    }

    User user(reporterName, contact);
    LostItem lost(itemName, location, description, date, user);
    lost.saveToFile();
    lostItems.push_back(lost);
    
    Utilities::showSuccessMessage("Your lost item has been reported successfully!");
}

void LostFoundSystem::addFoundItem() {
    Utilities::showInfoMessage("Report a Found Item");
    
    std::string reporterName = Utilities::getValidInput("Enter your name: ", false);
    std::string contact = Utilities::getValidInput("Enter your contact: ", false);
    std::string itemName = Utilities::getValidInput("Enter item name: ", false);
    std::string location = Utilities::getValidInput("Enter location where item was found: ", false);
    std::string description = Utilities::getValidInput("Enter item description: ", false);
    
    std::string date;
    bool validDate = false;
    while (!validDate) {
        date = Utilities::getValidInput("Enter date found (DD-MM-YYYY): ", false);
        validDate = Utilities::isValidDate(date);
        if (!validDate) {
            Utilities::showErrorMessage("Invalid date format. Please use DD-MM-YYYY.");
        }
    }

    User user(reporterName, contact);
    FoundItem found(itemName, location, description, date, user);
    found.saveToFile();
    foundItems.push_back(found);
    
    Utilities::showSuccessMessage("Your found item has been reported successfully!");
}

void LostFoundSystem::displayLostItems() {
    if (lostItems.empty()) {
        Utilities::showInfoMessage("No lost items have been reported yet.");
        return;
    }
    
    std::cout << "\nLOST ITEMS" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "ID  | Item Name           | Location            | Date Lost" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    
    for (size_t i = 0; i < lostItems.size(); i++) {
        printf("%-3zu | %-20s | %-20s | %s\n", 
               i + 1, 
               lostItems[i].getItemName().substr(0, 20).c_str(),
               lostItems[i].getLocation().substr(0, 20).c_str(),
               lostItems[i].getDate().c_str());
    }
    
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "\nEnter item ID to view details or press Enter to return: ";
    
    std::string input;
    std::getline(std::cin, input);
    
    if (!input.empty()) {
        try {
            int index = std::stoi(input) - 1;
            if (index >= 0 && index < static_cast<int>(lostItems.size())) {
                displayItemDetails("lost", index);
            } else {
                Utilities::showErrorMessage("Invalid ID selected.");
            }
        } catch (std::exception&) {
            Utilities::showErrorMessage("Invalid input. Please enter a number.");
        }
    }
}

void LostFoundSystem::displayFoundItems() {
    if (foundItems.empty()) {
        Utilities::showInfoMessage("No found items have been reported yet.");
        return;
    }
    
    std::cout << "\nFOUND ITEMS" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "ID  | Item Name           | Location            | Date Found" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    
    for (size_t i = 0; i < foundItems.size(); i++) {
        printf("%-3zu | %-20s | %-20s | %s\n", 
               i + 1, 
               foundItems[i].getItemName().substr(0, 20).c_str(),
               foundItems[i].getLocation().substr(0, 20).c_str(),
               foundItems[i].getDate().c_str());
    }
    
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "\nEnter item ID to view details or press Enter to return: ";
    
    std::string input;
    std::getline(std::cin, input);
    
    if (!input.empty()) {
        try {
            int index = std::stoi(input) - 1;
            if (index >= 0 && index < static_cast<int>(foundItems.size())) {
                displayItemDetails("found", index);
            } else {
                Utilities::showErrorMessage("Invalid ID selected.");
            }
        } catch (std::exception&) {
            Utilities::showErrorMessage("Invalid input. Please enter a number.");
        }
    }
}

void LostFoundSystem::matchItems() {
    if (lostItems.empty() || foundItems.empty()) {
        Utilities::showInfoMessage("Not enough data to find matches. Need both lost and found items.");
        return;
    }
    
    bool matchesFound = false;
    std::cout << "\nPOTENTIAL MATCHES" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    
    for (size_t i = 0; i < lostItems.size(); i++) {
        for (size_t j = 0; j < foundItems.size(); j++) {
            // Check for potential matches based on item name and location
            std::string lostName = Utilities::toLowerCase(lostItems[i].getItemName());
            std::string foundName = Utilities::toLowerCase(foundItems[j].getItemName());
            
            if (lostName == foundName || 
                (lostName.find(foundName) != std::string::npos) || 
                (foundName.find(lostName) != std::string::npos)) {
                
                if (!matchesFound) {
                    std::cout << "Lost Item                | Found Item               | Match Confidence" << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    matchesFound = true;
                }
                
                // Calculate a simple confidence score
                int confidence = 0;
                if (Utilities::toLowerCase(lostItems[i].getItemName()) == 
                    Utilities::toLowerCase(foundItems[j].getItemName()))
                    confidence += 50;
                else
                    confidence += 30;
                    
                if (Utilities::toLowerCase(lostItems[i].getLocation()) == 
                    Utilities::toLowerCase(foundItems[j].getLocation()))
                    confidence += 30;
                
                if (lostItems[i].getDate() == foundItems[j].getDate())
                    confidence += 20;
                
                printf("%-24s | %-24s | %d%%\n", 
                       lostItems[i].getItemName().substr(0, 24).c_str(),
                       foundItems[j].getItemName().substr(0, 24).c_str(),
                       confidence);
                
                std::cout << "Location: " << lostItems[i].getLocation().substr(0, 15) << 
                             " | Location: " << foundItems[j].getLocation().substr(0, 15) << 
                             " | IDs: L" << (i+1) << ", F" << (j+1) << std::endl;
                
                std::cout << "---------------------------------------------------" << std::endl;
            }
        }
    }
    
    if (!matchesFound) {
        std::cout << "No potential matches found at this time." << std::endl;
    }
    
    if (matchesFound) {
        std::cout << "\nTo view details of a matched item, use the View Lost/Found Items menu options." << std::endl;
        std::cout << "Press Enter to continue...";
        std::cin.ignore();
    }
}

void LostFoundSystem::searchLostItems(const std::string& keyword) {
    if (lostItems.empty()) {
        Utilities::showInfoMessage("No lost items have been reported yet.");
        return;
    }
    
    std::string searchTerm = Utilities::toLowerCase(keyword);
    std::vector<size_t> results;
    
    for (size_t i = 0; i < lostItems.size(); i++) {
        std::string itemName = Utilities::toLowerCase(lostItems[i].getItemName());
        std::string desc = Utilities::toLowerCase(lostItems[i].getDescription());
        std::string loc = Utilities::toLowerCase(lostItems[i].getLocation());
        
        if (itemName.find(searchTerm) != std::string::npos || 
            desc.find(searchTerm) != std::string::npos ||
            loc.find(searchTerm) != std::string::npos) {
            results.push_back(i);
        }
    }
    
    if (results.empty()) {
        Utilities::showInfoMessage("No matching lost items found.");
        return;
    }
    
    std::cout << "\nSEARCH RESULTS: LOST ITEMS" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "ID  | Item Name           | Location            | Date Lost" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    
    for (size_t i = 0; i < results.size(); i++) {
        size_t index = results[i];
        printf("%-3zu | %-20s | %-20s | %s\n", 
               index + 1, 
               lostItems[index].getItemName().substr(0, 20).c_str(),
               lostItems[index].getLocation().substr(0, 20).c_str(),
               lostItems[index].getDate().c_str());
    }
    
    std::cout << "---------------------------------------------------" << std::endl;
}

void LostFoundSystem::searchFoundItems(const std::string& keyword) {
    if (foundItems.empty()) {
        Utilities::showInfoMessage("No found items have been reported yet.");
        return;
    }
    
    std::string searchTerm = Utilities::toLowerCase(keyword);
    std::vector<size_t> results;
    
    for (size_t i = 0; i < foundItems.size(); i++) {
        std::string itemName = Utilities::toLowerCase(foundItems[i].getItemName());
        std::string desc = Utilities::toLowerCase(foundItems[i].getDescription());
        std::string loc = Utilities::toLowerCase(foundItems[i].getLocation());
        
        if (itemName.find(searchTerm) != std::string::npos || 
            desc.find(searchTerm) != std::string::npos ||
            loc.find(searchTerm) != std::string::npos) {
            results.push_back(i);
        }
    }
    
    if (results.empty()) {
        Utilities::showInfoMessage("No matching found items found.");
        return;
    }
    
    std::cout << "\nSEARCH RESULTS: FOUND ITEMS" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "ID  | Item Name           | Location            | Date Found" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    
    for (size_t i = 0; i < results.size(); i++) {
        size_t index = results[i];
        printf("%-3zu | %-20s | %-20s | %s\n", 
               index + 1, 
               foundItems[index].getItemName().substr(0, 20).c_str(),
               foundItems[index].getLocation().substr(0, 20).c_str(),
               foundItems[index].getDate().c_str());
    }
    
    std::cout << "---------------------------------------------------" << std::endl;
}

void LostFoundSystem::displayItemDetails(const std::string& itemType, int index) {
    if (itemType == "lost") {
        if (index < 0 || index >= static_cast<int>(lostItems.size())) {
            Utilities::showErrorMessage("Invalid item index.");
            return;
        }
        
        std::cout << "\nLOST ITEM DETAILS" << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "Item Name:     " << lostItems[index].getItemName() << std::endl;
        std::cout << "Location Lost: " << lostItems[index].getLocation() << std::endl;
        std::cout << "Description:   " << lostItems[index].getDescription() << std::endl;
        std::cout << "Date Lost:     " << lostItems[index].getDate() << std::endl;
        std::cout << "Reported By:   " << lostItems[index].getReporter().getName() << std::endl;
        std::cout << "Contact:       " << lostItems[index].getReporter().getContact() << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
    } else if (itemType == "found") {
        if (index < 0 || index >= static_cast<int>(foundItems.size())) {
            Utilities::showErrorMessage("Invalid item index.");
            return;
        }
        
        std::cout << "\nFOUND ITEM DETAILS" << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "Item Name:     " << foundItems[index].getItemName() << std::endl;
        std::cout << "Location Found:" << foundItems[index].getLocation() << std::endl;
        std::cout << "Description:   " << foundItems[index].getDescription() << std::endl;
        std::cout << "Date Found:    " << foundItems[index].getDate() << std::endl;
        std::cout << "Reported By:   " << foundItems[index].getReporter().getName() << std::endl;
        std::cout << "Contact:       " << foundItems[index].getReporter().getContact() << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
    }
    
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
} 