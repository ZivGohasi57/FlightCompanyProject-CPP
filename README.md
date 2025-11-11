# Flight Company Management System (C++)

A C++ project that models a flight company’s core operations (flights, routes, passengers, and bookings) with an emphasis on reliability, validation, and debuggability.

## Features
- Manage flights and passengers: create, update, search.
- Booking & cancellation with input validation and error handling.
- Modular OOP design (clear separation between models and services).
- Simple CLI for basic operations.

## Project Layout
- Visual Studio solution (`.sln`) for Windows builds.
- Optional cross-platform build using CMake (see below).

## Build & Run

### Visual Studio (Windows)
1. Open `FlightCompanyProject.sln` in Visual Studio.
2. Set the startup project (CLI app) and build in Debug/Release.
3. Run from Visual Studio (or from `x64/Release` / `x64/Debug` output folder).

### CMake (cross-platform)
If you prefer CMake:
```bash
mkdir -p build && cd build
cmake ..
cmake --build .
# run the produced binary
./flight_company
