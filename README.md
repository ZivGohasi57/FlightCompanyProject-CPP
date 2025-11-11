# Flight Company Management System (C++)

[![C++](https://img.shields.io/badge/C%2B%2B-17%2B-blue.svg)](https://en.cppreference.com/w/cpp)
[![Build](https://img.shields.io/badge/Build-CMake%20%7C%20MSVC%20%7C%20GCC%20%7C%20Clang-informational.svg)](#build--run)
[![Tests](https://img.shields.io/badge/Tests-assert--based-lightgrey.svg)](#tests)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](#license)

A C++ project that models a flight company's core operations (flights, passengers, bookings).  
Focus: modular design, validation, and reliability through debugging and testing.

---

## 🧩 Features
- Manage flights and passengers (create, update, search)
- Booking and cancellation with input validation and error handling
- Object-oriented modular design (models vs. services)
- Simple command-line interface
- Lightweight unit tests for core logic

---

## 🗂 Project Structure
```text
.
├── src/
│   ├── models/             # Flight, Passenger, Route, etc.
│   ├── services/           # BookingService, SearchService, Validation
│   ├── cli/                # main.cpp (CLI entry point)
│   └── utils/              # helpers, parsing, logging
├── include/                # public headers
├── tests/
│   ├── test_search.cpp     # flight search validation
│   ├── test_booking.cpp    # booking & cancellation rules
│   └── test_validation.cpp # input and data validation
├── data/                   # sample input files (CSV/JSON)
├── Makefile                # or CMakeLists.txt
└── README.md
````

---

## ⚙️ Prerequisites

* C++17 (or newer) compiler: MSVC, GCC, or Clang
* CMake 3.16+ (optional for cross-platform builds)
* (Optional) Git Bash / Terminal for CLI examples

---

## 🏗️ Build & Run

### 🪟 Visual Studio (Windows)

1. Open `FlightCompanyProject.sln` in Visual Studio.
2. Set the CLI project as the Startup Project.
3. Build (Debug or Release).
4. Run from Visual Studio or from the output folder.

### 🧱 CMake (cross-platform)

```bash
mkdir -p build && cd build
cmake ..
cmake --build .
./flight_company
```

> Requires a C++17 (or newer) compiler such as g++, clang++, or MSVC.

---

## 🚀 Usage (CLI Examples)

```bash
# Search flights
./flight_company --search --from TLV --to LHR --date 2025-01-05

# Book a seat
./flight_company --book --flight-id 1027 --passenger "Dana Levi" --seat 12A

# Cancel a booking
./flight_company --cancel --booking-id BK-000123
```

---

## 🧪 Tests

Lightweight assertion-based unit tests are located under `tests/`.
To run them, compile and execute any of the test files:

```bash
g++ -std=c++17 -Iinclude tests/test_search.cpp src/models/*.cpp src/services/*.cpp -o test_search
./test_search
```

### Suggested tests

* Search logic validation (origin, destination, date)
* Booking constraints (duplicate seats, invalid IDs)
* Input parsing and error handling

---

## 🧱 Development Guidelines

* Use RAII and smart pointers where appropriate
* Prefer STL containers (`std::vector`, `std::string`, `std::map`) and algorithms
* Validate all inputs and handle return values and error codes
* Keep functions small and focused
* Build with warnings enabled: `-Wall -Wextra` (treat warnings as errors in CI)

---

## 🗺️ Roadmap

* Add persistence layer (file/SQLite)
* Extend seat map and fare rules
* Implement JSON import/export
* Add CI workflow (build + tests)


