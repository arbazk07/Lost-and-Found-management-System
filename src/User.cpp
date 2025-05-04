#include "../include/User.h"

User::User() : name(""), contact("") {}

User::User(std::string name, std::string contact) : name(name), contact(contact) {}

std::string User::getName() const {
    return name;
}

std::string User::getContact() const {
    return contact;
} 