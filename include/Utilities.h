#pragma once
#include <string>
#include <iostream>

namespace Utilities {
    // Display formatted messages
    void showWelcomeMessage();
    void showExitMessage();
    void showSuccessMessage(const std::string& message);
    void showErrorMessage(const std::string& message);
    void showInfoMessage(const std::string& message);
    
    // Input validation
    bool isValidDate(const std::string& date);
    std::string getValidInput(const std::string& prompt, bool allowEmpty = false);
    
    // String manipulation
    std::string trim(const std::string& str);
    std::string toLowerCase(const std::string& str);
} 