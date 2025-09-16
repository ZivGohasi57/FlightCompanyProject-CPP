#pragma once
#include "CCrewMember.h"
#include "CAddress.h"
#include <string>
#include <iostream>
using namespace std;

class CPilot : public CCrewMember {
    friend ostream& operator<<(ostream& os, const CPilot& pilot);

private:
    bool isCaptain;
    const CAddress* home;

public:
    CPilot(const string& name, bool isCaptain, const CAddress* home = nullptr);
    CPilot(const CPilot& other);
    ~CPilot();

    bool getIsCaptain() const;
    const CAddress* getHome() const;
    void setIsCaptain(bool captain);
    void setHome(const CAddress* addr);

    void GetPresent() const override;
    void GetUniform() const override;
    void GoToSimulator() const;

    bool operator==(const CPilot& other) const;
    bool operator+=(int minutes);
    void Print(ostream& os) const;
};
