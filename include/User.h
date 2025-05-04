#pragma once
#include <string>

class User {
private:
    std::string name;
    std::string contact;
public:
    User();
    User(std::string name, std::string contact);
    std::string getName() const;
    std::string getContact() const;
}; 