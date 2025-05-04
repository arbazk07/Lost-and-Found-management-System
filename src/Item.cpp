#include "../include/Item.h"

Item::Item() : itemName(""), location(""), description(""), date("") {}

Item::Item(std::string itemName, std::string location, std::string description, std::string date, User reporter) {
    this->itemName = itemName;
    this->location = location;
    this->description = description;
    this->date = date;
    this->reporter = reporter;
}

std::string Item::getItemName() const {
    return itemName;
}

std::string Item::getLocation() const {
    return location;
}

std::string Item::getDescription() const {
    return description;
}

std::string Item::getDate() const {
    return date;
}

User Item::getReporter() const {
    return reporter;
} 