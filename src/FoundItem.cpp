#include "../include/FoundItem.h"
#include <fstream>

FoundItem::FoundItem() : Item() {}

FoundItem::FoundItem(std::string itemName, std::string location, std::string description, 
                   std::string date, User reporter)
    : Item(itemName, location, description, date, reporter) {}

void FoundItem::saveToFile() {
    std::ofstream file("data/found_items.txt", std::ios::app);
    if (file.is_open()) {
        file << itemName << "," << location << "," << description << "," << date << ","
             << reporter.getName() << "," << reporter.getContact() << std::endl;
        file.close();
    }
} 