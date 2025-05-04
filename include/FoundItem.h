#pragma once
#include "Item.h"

class FoundItem : public Item {
public:
    FoundItem();
    FoundItem(std::string itemName, std::string location, std::string description, 
             std::string date, User reporter);
    
    void saveToFile() override;
}; 