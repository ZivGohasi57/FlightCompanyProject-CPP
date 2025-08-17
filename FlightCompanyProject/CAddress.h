#pragma once
#include <string>

using namespace std;

class CAddress
{
private:
    string cityName;
    string streetName;
    int houseNumber;
public:
    CAddress(string cityName = "Tel Aviv", string streetName, int houseNumber);
    string getCityName();
    string getStreetName();
    int getHouseNumber();
    void print();
    void updateAddress(string cityName, string streetName, int houseNumber);
    ~CAddress();
};

// ===== CAddress =====
// members
//
// city string
// street name string
// house number int
//
// methods
//
// ctor
// getters
// print
// update address