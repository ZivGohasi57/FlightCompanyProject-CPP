#pragma once
#include <string>
#include <iostream>

using namespace std;

class CAddress
{
    friend ostream& operator<<(ostream& os, const CAddress& address);
    friend istream& operator>>(istream& is, CAddress& a);

private:
    string cityName;
    string streetName;
    int houseNumber;

public:
    CAddress(const int houseNumber = 1, const char* streetName = "Hertzel", const char* cityName = "Tel Aviv");
    CAddress(const CAddress& other);
    ~CAddress();

    string getCityName() const;
    string getStreetName() const;
    int getHouseNumber() const;

    void setCityName(string cityName);
    void setStreetName(string streetName);
    void setHouseNumber(int houseNumber);

    void UpdateAddress(const string cityName, const string streetName, const int houseNumber);
    void operator=(const CAddress& other);
    bool operator==(const CAddress& other) const;
    bool operator!=(const CAddress& other) const;
    string GetCurrentAddress();
};
