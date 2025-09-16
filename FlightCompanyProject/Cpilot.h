#pragma once
#include "CCrewMember.h"
#include "CAddress.h"
#include <string>
#include <iostream>
using namespace std;

class CPilot : public CCrewMember {
    friend ostream& operator<<(ostream& os, const CPilot& pilot);

private:
    bool isCaptain;           // true if captain
    const CAddress* home;     // non-owning pointer, may be nullptr

public:
    // constructors
    CPilot(const string& name, bool isCaptain, const CAddress* home = nullptr);
    CPilot(const CPilot& other);

    // destructor
    ~CPilot();

    // getters
    bool getIsCaptain() const;
    const CAddress* getHome() const;

    // setters
    void setIsCaptain(bool captain);
    void setHome(const CAddress* addr);

    // methods
    string GetPresent() const;     // gift
    string GetUniform() const;     // uniform type
    void GoToSimulator() const;    // simulator requirement

    // overloads
    bool operator==(const CPilot& other) const;
    bool operator+=(int minutes);  // add airtime (+10% if captain, rounded)

    void Print(ostream& os) const;
};
