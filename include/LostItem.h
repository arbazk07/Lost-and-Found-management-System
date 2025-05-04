#pragma once
#include "Item.h"

class LostItem : public Item {
public:
    LostItem();
    LostItem(std::string itemName, std::string location, std::string description, 
            std::string date, User reporter);
    
    void saveToFile() override;
}; 