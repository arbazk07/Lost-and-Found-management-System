#pragma once
#include "LostItem.h"
#include "FoundItem.h"
#include <iostream>
#include <fstream>
#include <vector>

class LostFoundSystem {
private:
    std::vector<LostItem> lostItems;
    std::vector<FoundItem> foundItems;
    
    // Helper methods
    void loadItems();
    void parseCSVLine(const std::string& line, std::string& itemName, std::string& location, 
                    std::string& description, std::string& date, std::string& reporterName, 
                    std::string& contact);
    
public:
    LostFoundSystem();
    
    void addLostItem();
    void addFoundItem();
    void displayLostItems();
    void displayFoundItems();
    void matchItems();
    
    // Added functionality
    void searchLostItems(const std::string& keyword);
    void searchFoundItems(const std::string& keyword);
    void displayItemDetails(const std::string& itemType, int index);
}; 