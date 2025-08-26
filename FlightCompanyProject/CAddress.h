#pragma once
#include <string>

using namespace std;

class CAddress
{
    friend ostream& operator<<(ostream& os, const CAddress& address);
    friend istream& operator>>(std::istream& is, CAddress& a);
private:
    string cityName;
    string streetName;
    int houseNumber;


public:
    CAddress(const int houseNumber, const string streetName, const string cityName = "Tel Aviv");
    CAddress(const CAddress& other);

    // getters
    string getCityName() const;
    string getStreetName() const;
    int getHouseNumber() const;

    // setters
    void setCityName(string cityName);
    void setStreetName(string streetName);
    void setHouseNumber(int houseNumber);

    // methods
    void UpdateAddress(const string cityName, const string streetName, const int houseNumber);
    void operator=(const CAddress& other);
    bool operator==(const CAddress& other) const;
    bool operator!=(const CAddress& other) const;
    string GetCurrentAddress()

    ~CAddress();
};

