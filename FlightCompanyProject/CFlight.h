// CFlight.h
#pragma once
#include <iostream>
#include "CFlightInfo.h"
#include "CPlane.h"
#include "CCrewMember.h"

// Forward declarations so dynamic_cast compiles even if you don't include the headers here
class CPilot;
class CSeniorHost;   // if you have such a class; otherwise this forward-decl is harmless
class CCargo;        // subclass of CPlane

using namespace std;

#define MAX_CREW 10

class CFlight
{
    friend ostream& operator<<(ostream& os, const CFlight& address);

private:
    CFlightInfo info;
    CPlane* plane;
    CCrewMember* crew[MAX_CREW];
    int         crewCount;

public:
    CFlight(const CFlightInfo& flightInfo, CPlane* flightPlane = nullptr);
    ~CFlight();

    CCrewMember* const* GetCrew() const { return crew; }

    void       SetPlane(CPlane* newPlane);
    CPlane* GetPlane() const;

    void       SetFlightInfo(const CFlightInfo& newInfo);
    CFlightInfo GetFlightInfo() const;

    int        GetCrewCount() const;

    bool       operator+(CCrewMember* meber);
    bool       operator==(const CFlight& other) const;
    CFlight& operator=(const CFlight& other);

    // === NEW ===
    // Validate and execute a takeoff for THIS flight.
    // Returns true if legal and "executed" (notifications printed); false otherwise.
    bool TakeOff() const;

    // (Optional convenience if you want callers to get at the array)
    // CCrewMember* const* GetCrew() const { return crew; }
};
