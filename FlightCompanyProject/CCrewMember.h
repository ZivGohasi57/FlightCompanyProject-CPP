#pragma once
#include <string>
#include "CAddress.h"

using namespace std;

class CCrewMember
{
    friend ostream& operator<<(ostream& os, const CCrewMember& member);

private:
    static int s_nextId;
    int crewMemberNumber;
    string memberName;
    int memberAirTime;
    CAddress memberAddress;

public:
    static const int START_ID = 1000;
    CCrewMember(const string name, const CAddress& address, int airTime = 0);
    CCrewMember(const string name);
    CCrewMember(const string name, int airTime);
    CCrewMember(const CCrewMember& other);
    virtual CCrewMember* Clone() const { return new CCrewMember(*this); }
    virtual void Print(ostream& os) const;
    virtual ~CCrewMember();

    string getMemberName() const;
    int getMemberAirTime() const;
    CAddress getMemberAddress() const;
    int getMemberId() const;

    void setMemberName(const string newName);
    void setMemberAddress(const CAddress& newAddress);
    void setMemberAirTime(const int airTime);

    void operator=(const CCrewMember& other);
    bool operator==(const CCrewMember& other) const;
    virtual bool operator+=(int minutes);
    virtual void GetPresent() const;
    virtual void GetUniform() const;
};
