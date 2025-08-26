#include "CFlight.h"

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

