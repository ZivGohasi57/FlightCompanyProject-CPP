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
    CAddress(int houseNumber, string streetName, string cityName = "Tel Aviv");
    CAddress(const CAddress& other);
    //getters
    string getCityName() const;
    string getStreetName() const;
    int getHouseNumber() const;
    //setters
    void setCityName(string cityName);
    void setStreetName(string streetName);
    void setHouseNumber(int houseNumber);
    //misc
    void Print() const;
    void UpdateAddress(const string cityName, const string streetName, const int houseNumber);
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