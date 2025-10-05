#include "CFlight.h"
#include "Cpilot.h"
#include "CCargo.h"
#include <typeinfo>
#include <iostream>

using namespace std;

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

CCrewMember* const* CFlight::GetCrew() const
{
    return crew;
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
    if (this != &other)
    {
        info = other.info;
        plane = other.plane;
        crewCount = other.crewCount;
        for (int i = 0; i < crewCount; i++)
        {
            crew[i] = other.crew[i];
        }
    }
    return *this;
}

ostream& operator<<(ostream& os, const CFlight& f)
{
    os << "Flight " << f.info;
    if (f.plane) os << *(f.plane);
    else os << "No plane assign yet ";
    os << " There are " << f.crewCount << " crew memebers in flight:\n";
    for (int i = 0; i < f.crewCount; i++) if (f.crew[i]) os << *(f.crew[i]);
    return os;
}


bool CFlight::TakeOff()
{
    if (!plane)
    {
        return false;
    }

    const bool isCargo = (dynamic_cast<CCargo*>(plane) != nullptr);

    int pilots = 0;
    for (int i = 0; i < crewCount; ++i)
    {
        if (crew[i] && dynamic_cast<CPilot*>(crew[i]))
        {
            ++pilots;
        }
    }

    if (isCargo)
    {
        if (pilots < 1)
        {
            return false;
        }
    }
    else
    {
        if (pilots != 1)
        {
            return false;
        }
    }

    const int minutes = info.getFlightMinutes();

    if (isCargo)
    {
        cout << "Need to add " << minutes
            << " minutes to my log book" << endl;
    }

    for (int i = 0; i < crewCount; ++i)
    {
        if (crew[i])
        {
            *crew[i] += minutes;
        }
    }
    return true;
}
