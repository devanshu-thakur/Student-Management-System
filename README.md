# Smart Student Management System

A menu-driven Student Management System built with **C++20**. It manages student details using a text file and stores subject-wise marks in an SQLite database.

## Features

- **Register New Student** — saves student details and registration date.
- **Check Student Details** — search for a student by name or ID.
- **Remove Student** — remove a student's stored details.
- **Update Student Details** — update existing student information.
- **Marks Record**
  - **Set Marks** — add marks for a registered student.
  - **Get Marks** — view a student's marks.
  - **Update Marks** — update an existing marks record.
- **Exit** — close the application.

> The Rank List menu option is not implemented yet.

## Technologies Used

- C++20
- GCC / MinGW-w64
- SQLite
- Text-file handling
- Visual Studio Code

## Project Files

```text
main.cpp
project.h
register_new.cpp
check_details.cpp
remove_details.cpp
update_details.cpp
set_marks.cpp
get_marks.cpp
update_marks.cpp
student.txt        # Student details used by the application
new.db             # SQLite database for subject marks; created when needed
README.md
```

## Requirements

- Windows
- A C++ compiler such as GCC from MSYS2 UCRT64
- SQLite development library for compiling the project

If you use MSYS2 UCRT64, install SQLite from the **UCRT64 terminal**:

```bash
pacman -S mingw-w64-ucrt-x86_64-sqlite3
```

## Build the Application

Open a terminal in the project folder and run:

```bash
g++ -std=c++20 main.cpp register_new.cpp remove_details.cpp check_details.cpp update_details.cpp set_marks.cpp get_marks.cpp update_marks.cpp -o student_App.exe -lsqlite3
```

Then run it in PowerShell:

```powershell
.\student_App.exe
```

If compilation fails, check that every source file listed in the build command exists in the project folder and that SQLite is installed and available to the compiler.

## Data Storage

- Student details are stored in `student.txt`.
- Subject-wise marks are stored in `new.db`, an SQLite database file.
- The application checks the student's ID against `student.txt` before working with marks.
- Keep `student.txt` and `new.db` in the working directory when you want to keep using the same records.

The `.db` file is created locally by the application. It is not automatically shared with other users when the source code is uploaded to GitHub.

## Notes

- The marks are entered in this order: **Maths, FoCP, FoEE, PC, E_Physics**.
- Back up `student.txt` and `new.db` before making changes if they contain records you need.
- Do not upload private student information to a public repository.

## Purpose

This project is created for educational purposes to practise C++ programming, file handling, SQL, and SQLite database integration.
