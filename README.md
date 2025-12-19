# 🔍 Lost & Found Management System

> A robust C++ console application for tracking and recovering assets in high-traffic environments.

## 🚀 Project Overview
This system is designed to streamline resource recovery in organizations, workplaces, and campuses. Unlike manual logbooks, this application offers a digital, persistent database to match "Lost" reports with "Found" inventory using automated logic.

It demonstrates core software engineering principles including **Data Persistence**, **Object-Oriented Design**, and **Search Efficiency**.

## ⚙️ Technical Highlights
* **Language:** C++
* **Architecture:** Modular design separating Interface (`.h`) from Implementation (`.cpp`).
* **Data Persistence:** Custom file-handling engine to store records in CSV format (`data/lost_items.txt`), ensuring data survives system restarts.
* **Algorithmic Logic:** Implements keyword matching algorithms to automatically suggest potential matches between lost and found datasets.

## 🛠️ Key Features
* **📝 Report Management:** Distinct workflows for logging Lost assets vs. Found inventory.
* **🔄 Auto-Matching:** System intelligently compares item descriptions and locations to suggest matches.
* **📂 Persistent Database:** detailed logging of IDs, categories, and descriptions.
* **🔎 Advanced Search:** Query the database by keywords or Item IDs.
* **📊 Formatted Display:** Clean console UI for viewing inventory lists.

## 📂 Project Structure
The codebase follows standard practice for C++ project organization:

```text
LostFoundSystem/
├── include/           # Header files (Interface)
│   ├── User.h
│   ├── Item.h         # Base Class (Polymorphism)
│   ├── LostItem.h     # Derived Class
│   ├── FoundItem.h    # Derived Class
│   ├── LostFoundSystem.h 
│   └── Utilities.h    
├── src/               # Source files (Implementation)
│   ├── User.cpp
│   ├── Item.cpp
│   ├── LostItem.cpp
│   ├── FoundItem.cpp
│   ├── LostFoundSystem.cpp
│   └── main.cpp       # Entry Point
├── data/              # Database
│   ├── lost_items.txt 
│   └── found_items.txt 
└── CMakeLists.txt     # Build Configuration
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

## 🔮 Future Enhancements

- User authentication system
- Image upload for lost/found items
- Web interface
- Email notifications for potential matches
- Mobile application 
- Migrating from local .txt storage to a SQL database.



Developed by Arbaz | Built with C++
