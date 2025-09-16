#pragma once
#include <iostream>
#include "CFlightInfo.h"
#include "CPlane.h"
#include "CCrewMember.h"

#define MAX_CREW 10

using namespace std;

class CFlight
{
    friend ostream& operator<<(ostream& os, const CFlight& flight);

private:
    CFlightInfo info;
    CPlane* plane;
    CCrewMember* crew[MAX_CREW];
    int crewCount;

public:
    CFlight(const CFlightInfo& flightInfo, CPlane* flightPlane = nullptr);
    ~CFlight();

    CCrewMember* const* GetCrew() const;

    void SetPlane(CPlane* newPlane);
    CPlane* GetPlane() const;

    void SetFlightInfo(const CFlightInfo& newInfo);
    CFlightInfo GetFlightInfo() const;

    int GetCrewCount() const;

    bool operator+(CCrewMember* member);
    bool operator==(const CFlight& other) const;
    CFlight& operator=(const CFlight& other);

    bool TakeOff();
};
