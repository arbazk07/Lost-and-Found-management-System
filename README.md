# Lost & Found Management System

A centralized platform for reporting, finding, and matching lost and found items.

## Project Overview

The Lost & Found Management System is designed to help users report lost items, report found items, and match these items based on criteria like item name, location, and description. This system streamlines the process of returning lost items to their rightful owners.

## Features

- **Report Lost Items**: Users can report items they've lost with detailed information.
- **Report Found Items**: Users can report items they've found with detailed information.
- **View Items**: Browse through lost and found items in a formatted display.
- **Match Items**: The system automatically suggests potential matches between lost and found items.
- **Search Functionality**: Search for specific items by keywords.
- **Detailed Item View**: View comprehensive details about any item.

## Project Structure

```
LostFoundSystem/
├── include/           # Header files
│   ├── User.h         # User class definition
│   ├── Item.h         # Base item class  
│   ├── LostItem.h     # Lost item class
│   ├── FoundItem.h    # Found item class
│   ├── LostFoundSystem.h # Main system class
│   └── Utilities.h    # Utility functions
├── src/               # Source files
│   ├── User.cpp       # User class implementation
│   ├── Item.cpp       # Base item implementation
│   ├── LostItem.cpp   # Lost item implementation
│   ├── FoundItem.cpp  # Found item implementation
│   ├── LostFoundSystem.cpp # Main system implementation
│   ├── Utilities.cpp  # Utility functions implementation
│   └── main.cpp       # Program entry point
├── data/              # Data storage directory
│   ├── lost_items.txt # Lost items database
│   └── found_items.txt # Found items database
└── CMakeLists.txt     # CMake build configuration
```

## How to Build

### Prerequisites
- C++ compiler with C++17 support
- CMake (version 3.10 or higher)

### Build Steps
1. Clone the repository
2. Navigate to the project directory
3. Create a build directory: `mkdir build && cd build`
4. Generate build files: `cmake ..`
5. Build the project: `cmake --build .`

## How to Run

After building, run the executable:
```
./LostFoundSystem
```

## Data Storage

All lost and found items are stored in CSV format in text files located in the `data` directory. The system automatically loads these files on startup and saves new reports to them.

## Future Enhancements

- User authentication system
- Image upload for lost/found items
- Web interface
- Email notifications for potential matches
- Mobile application 