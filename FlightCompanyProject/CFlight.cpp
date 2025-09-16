#include "CFlight.h"
#include "Cpilot.h"   // CPilot
#include "CCargo.h"   // CCargo (CPlane subclass)
#include <typeinfo>
#include <iostream>

CFlight::CFlight(const CFlightInfo& flightInfo, CPlane* flightPlane)
	: info(flightInfo), plane(flightPlane), crewCount(0)
{
	for (int i = 0; i < MAX_CREW; i++)
	{
		crew[i] = nullptr;
	}
}

CFlight::~CFlight()
{
}

void CFlight::SetPlane(CPlane* newPlane)
{
	plane = newPlane;
}

CPlane* CFlight::GetPlane() const
{
    return plane;
}

void CFlight::SetFlightInfo(const CFlightInfo& newInfo)
{
    info = newInfo;
}

CFlightInfo CFlight::GetFlightInfo() const
{
    return info;
}

int CFlight::GetCrewCount() const
{
    return crewCount;
}

bool CFlight::operator+(CCrewMember* member)
{
	if (crewCount >= MAX_CREW)
	{
		return false;
	}
	if (member == nullptr)
	{
		return false;
	}
	crew[crewCount++] = member;
	return true;
}

bool CFlight::operator==(const CFlight& other) const
{
	return info == other.info;
}

CFlight& CFlight::operator=(const CFlight& other)
{
    if (this != &other) {
        info = other.info;
        plane = other.plane;
        crewCount = other.crewCount;
        for (int i = 0; i < crewCount; i++)
            crew[i] = other.crew[i];
    }
    return *this;
}

ostream& operator<<(ostream& os, const CFlight& f)
{
    os << "Flight " << f.info;
    if (f.plane != nullptr)
        os << *(f.plane);
    else
        os << "No plane assign yet ";

    if (f.crewCount == 0)
    {
        os << "There are 0 crew members in flight:\n";
    }
    else
    {
        os << "Crew members in flight:\n";
        for (int i = 0; i < f.crewCount; i++)
        {
            os << *(f.crew[i]);
        }
    }
    return os;
}

bool CFlight::TakeOff() const
{
    // 1) Plane must be assigned
    if (!plane) {
        return false;
    }

    // 2) Determine if this is a cargo flight (plane is CCargo)
    const bool isCargo = (dynamic_cast<CCargo*>(plane) != nullptr);

    // 3) Analyze crew composition
    int pilots = 0;
    int seniorHosts = 0; // counted only if your project has CSeniorHost

    for (int i = 0; i < crewCount; ++i) {
        CCrewMember* m = crew[i];
        if (!m) continue;

        if (dynamic_cast<CPilot*>(m)) {
            ++pilots;
            continue;
        }
        // Count senior hosts only if the type exists in your project
        if (dynamic_cast<CSeniorHost*>(m)) {
            ++seniorHosts;
            continue;
        }
    }

    // 4) Validate rules
    if (isCargo) {
        // Cargo: at least one pilot
        if (pilots < 1) {
            return false;
        }
    }
    else {
        // Passenger: exactly one pilot; if there is a senior host, at most one
        if (pilots != 1) {
            return false;
        }
        if (seniorHosts > 1) {
            return false;
        }
    }

    return true;
}
