#pragma once
#include <string>
#include "CAddress.h"

using namespace std;

class CCrewMember
{
    friend ostream& operator<<(ostream& os, const CCrewMember& member);

private:
    static int s_crewMemberNumber;
    int crewMemberNumber;
    string memberName;
    int memberAirTime;
    CAddress memberAddress;

public:
    CCrewMember(const string name, const CAddress& address, int airTime = 0);
    CCrewMember(const string name);
    CCrewMember(const CCrewMember& other);
    ~CCrewMember();


    // getters
    string getMemberName() const;
    int getMemberAirTime() const;
    CAddress getMemberAddress() const;
    int getMemberId() const;

    // setters
    void setMemberName(const string newName);
    void setMemberAddress(const CAddress& newAddress);
    void setMemberAirTime(const int airTime);


    // methods
    void operator=(const CCrewMember& other);
    bool operator==(const CCrewMember& other) const;
    bool operator+=(const int minutes);

};

