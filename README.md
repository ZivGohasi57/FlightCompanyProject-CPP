# Flight Company Management System (C++)

A C++ project that models a flight company's core operations, including flights, passengers, and bookings.  
The focus is on modular design, validation, and reliability through debugging and testing.

## Features
- Manage flights and passengers (create, update, search)
- Booking and cancellation with input validation and error handling
- Object-oriented modular design with clear separation between models and services
- Simple command-line interface for operations and testing
- Lightweight unit tests for verifying core logic

## Project Structure

├── src/
│ ├── models/ # Flight, Passenger, Route, etc.
│ ├── services/ # BookingService, SearchService, Validation
│ ├── cli/ # main.cpp (CLI entry point)
│ └── utils/ # helpers, parsing, logging
├── include/ # public headers
├── tests/
│ ├── test_search.cpp # flight search validation
│ ├── test_booking.cpp # booking and cancellation tests
│ └── test_validation.cpp # input and data validation
├── data/ # sample input files (CSV/JSON)
├── Makefile # or CMakeLists.txt
└── README.md

## Build & Run

### Visual Studio (Windows)
1. Open `FlightCompanyProject.sln` in Visual Studio.
2. Set the CLI project as the startup project.
3. Build (Debug or Release).
4. Run from Visual Studio or from the compiled binary folder.

### CMake (cross-platform)
```bash
mkdir -p build && cd build
cmake ..
cmake --build .
./flight_company


Requires a C++17 (or newer) compiler such as g++, clang++, or MSVC.


# Search flights
./flight_company --search --from TLV --to LHR --date 2025-01-05

# Book a seat
./flight_company --book --flight-id 1027 --passenger "Dana Levi" --seat 12A

# Cancel a booking
./flight_company --cancel --booking-id BK-000123


Tests

The project includes lightweight assertion-based unit tests.
To run them, compile and execute any of the test files under tests/.

Example:

g++ -std=c++17 -Iinclude tests/test_search.cpp src/models/*.cpp src/services/*.cpp -o test_search
./test_search


Suggested tests:

Search logic validation (origin, destination, date)

Booking constraints (duplicate seats, invalid IDs)

Input parsing and error handling

Development Guidelines

Use RAII and smart pointers where appropriate

Prefer STL containers (std::vector, std::string, std::map) and algorithms

Validate all inputs and handle all return values and error codes

Keep functions short and focused

Build with warnings enabled (-Wall -Wextra) and fix all warnings

Roadmap

Add persistence layer (file/SQLite-based)

Extend seat map and fare rules

Implement JSON import/export

Add CI workflow for automatic builds and tests

License

MIT License
