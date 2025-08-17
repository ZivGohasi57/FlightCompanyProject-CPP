#pragma once
#include <string>
#include "CAddress.h"

using namespace std;

class CCrewMember
{
public:
    CCrewMember(const string& name, const CAddress& address, int airTime = 0);
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
    void print() const;
    void updateMemberAirTime(const int minutes);
    bool isEqual(const CCrewMember& other) const;






private:
    string memberName;
    int memberAirTime;
    CAddress memberAddress;
};

// ===== CCrewMember =====
// members
//
// name string
// air time minutes int
// address CAddress
//
// methods
//
// ctor (with and without air time)
// update minutes (add minutes with validation)
// set/get name
// set/get address
// get air time
// print
// is equal (compare by name)
