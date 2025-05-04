#include "../include/Utilities.h"
#include <algorithm>
#include <cctype>
#include <regex>

namespace Utilities {

    void showWelcomeMessage() {
        std::cout << "\n                                                          " << std::endl;
        std::cout << "                                                            " << std::endl;
        std::cout << "    WELCOME TO THE LOST & FOUND MANAGEMENT SYSTEM            " << std::endl;
        std::cout << "                                                            " << std::endl;
        std::cout << "    A centralized platform to report and find lost items    " << std::endl;
        std::cout << "                                                            " << std::endl;
        std::cout << "                                                             " << std::endl;
    }

    void showExitMessage() {
        std::cout << "\nTHANK YOU FOR USING THE LOST & FOUND SYSTEM!" << std::endl;
        std::cout << "Have a great day!\n" << std::endl;
    }

    void showSuccessMessage(const std::string& message) {
        std::cout << "\nSUCCESS: " << message << std::endl;
    }

    void showErrorMessage(const std::string& message) {
        std::cout << "\nERROR: " << message << std::endl;
    }

    void showInfoMessage(const std::string& message) {
        std::cout << "\nINFO: " << message << std::endl;
    }

    bool isValidDate(const std::string& date) {
        std::regex datePattern("\\d{2}-\\d{2}-\\d{4}");
        return std::regex_match(date, datePattern);
    }

    std::string getValidInput(const std::string& prompt, bool allowEmpty) {
        std::string input;
        bool valid = false;
        
        while (!valid) {
            std::cout << prompt;
            std::getline(std::cin, input);
            
            input = trim(input);
            
            if (input.empty() && !allowEmpty) {
                showErrorMessage("Input cannot be empty. Please try again.");
            } else {
                valid = true;
            }
        }
        
        return input;
    }

    std::string trim(const std::string& str) {
        auto start = std::find_if_not(str.begin(), str.end(), [](unsigned char c) {
            return std::isspace(c);
        });
        
        auto end = std::find_if_not(str.rbegin(), str.rend(), [](unsigned char c) {
            return std::isspace(c);
        }).base();
        
        return (start < end) ? std::string(start, end) : std::string();
    }

    std::string toLowerCase(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), 
                      [](unsigned char c) { return std::tolower(c); });
        return result;
    }
} 