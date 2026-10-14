# Smart Student Management System

## About the Project
The Smart Student Management System is a menu-driven C++ application developed using C++20. It helps manage student records through file handling, allowing users to register, search, update, and remove student details.

## Features
- **Register Student:** Store student details and registration date.
- **Check Details:** Search students by name or ID.
- **Remove Student:** Delete student records.
- **Update Details:** Modify existing student information.
- **Rank List:** Planned for a future update.
- **Exit:** Close the application.

## Technologies Used
- C++20
- GCC Compiler
- Visual Studio Code
- File handling using text files

## Project Structure
```text
main.cpp
project.h
register_new.cpp
check_details.cpp
remove_details.cpp
update_details.cpp
student.txt
README.md
```

## How to Run

**1. Compile the project:**
```bash
g++ -std=c++20 main.cpp register_new.cpp remove_details.cpp check_details.cpp update_details.cpp -o student.exe
```

**2. Run the program:**
```powershell
.\student.exe
```

## Concepts Used
- Functions and header files
- Loops and conditional statements
- Strings and user input
- File handling (`ifstream`, `ofstream`)
- Searching, updating, and deleting records

## Future Improvements
- Complete the rank list feature.
- Prevent duplicate student IDs.
- Add better input validation.
- Introduce a database or graphical interface.

## Purpose
This project is created for educational purposes to practise C++ programming and file handling.
