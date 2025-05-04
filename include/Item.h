#pragma once
#include <string>
#include "User.h"

// Base Item class
class Item {
protected:
    std::string itemName;
    std::string location;
    std::string description;
    std::string date;
    User reporter;
public:
    Item();
    Item(std::string itemName, std::string location, std::string description, std::string date, User reporter);
    
    std::string getItemName() const;
    std::string getLocation() const;
    std::string getDescription() const;
    std::string getDate() const;
    User getReporter() const;

    virtual void saveToFile() = 0; // pure virtual function
}; 