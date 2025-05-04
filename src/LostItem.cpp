#include "../include/LostItem.h"
#include <fstream>

LostItem::LostItem() : Item() {}

LostItem::LostItem(std::string itemName, std::string location, std::string description, 
                 std::string date, User reporter)
    : Item(itemName, location, description, date, reporter) {}

void LostItem::saveToFile() {
    std::ofstream file("data/lost_items.txt", std::ios::app);
    if (file.is_open()) {
        file << itemName << "," << location << "," << description << "," << date << ","
             << reporter.getName() << "," << reporter.getContact() << std::endl;
        file.close();
    }
} 