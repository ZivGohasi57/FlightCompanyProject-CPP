#pragma once
#include <string>
#include "CAddress.h"

using namespace std;

class CCrewMember
{

private:
    string memberName;
    int memberAirTime;
    CAddress memberAddress;

public:
    CCrewMember(const string name, const CAddress& address, int airTime = 0);
    CCrewMember(const CCrewMember& other);
    ~CCrewMember();


    // getters
    string getMemberName() const;
    int getMemberAirTime() const;
    CAddress getMemberAddress() const;

    // setters
    void setMemberName(const string newName);
    void setMemberAddress(const CAddress& newAddress);


    // methods
    void Print() const;
    bool UpdateMinutes(const int minutes);
    bool IsEqual(const CCrewMember& other) const;

};

