#include "CPlane.h"
#include "CCargo.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int CPlane::s_nextIdentifier = 100;

CPlane::CPlane(const int seatNum, const string pModel)
    : planeIdentifier(s_nextIdentifier++), numOfSeats(seatNum), planeModel(pModel)
{
    if (numOfSeats <= 0) numOfSeats = 1;
    if (planeModel.empty()) planeModel = "Unknown";
}

CPlane::CPlane(const CPlane& other)
    : planeIdentifier(other.planeIdentifier),
    numOfSeats(other.numOfSeats),
    planeModel(other.planeModel)
{
}

CPlane::~CPlane()
{
}

int CPlane::getPlaneIdentifier() const
{
    return this->planeIdentifier;
}

string CPlane::getPlaneModel() const
{
    return this->planeModel;
}

int CPlane::getNumOfSeats() const
{
    return this->numOfSeats;
}

void CPlane::setPlaneIdentifier(int planeIdentifier)
{
    if (planeIdentifier > 0) this->planeIdentifier = planeIdentifier;
}

void CPlane::setPlaneModel(string planeModel)
{
    this->planeModel = planeModel;
}

void CPlane::setNumOfSeats(int numOfSeats)
{
    if (numOfSeats > 0) this->numOfSeats = numOfSeats;
}

ostream& operator<<(ostream& os, const CPlane& plane)
{
    os << "Plane " << plane.getPlaneIdentifier()
        << " degem " << plane.getPlaneModel()
        << " seats " << plane.getNumOfSeats() << endl;

    if (auto cargo = dynamic_cast<const CCargo*>(&plane))
    {
        os << "Cargo M_vol " << cargo->getMaxVolume()
            << " M_Kg " << cargo->getMaxWeight()
            << " C_vol " << cargo->getLoadedVolume()
            << " C_Kg " << cargo->getLoadedWeight() << endl;
    }
    return os;
}

void CPlane::operator=(const CPlane& other)
{
    this->planeModel = other.planeModel;
    this->planeIdentifier = other.planeIdentifier;
    this->numOfSeats = other.numOfSeats;
}

bool CPlane::operator==(const CPlane& other) const
{
    return this->planeIdentifier == other.planeIdentifier;
}

CPlane& CPlane::operator++()
{
    ++numOfSeats;
    return *this;
}

CPlane CPlane::operator++(int)
{
    CPlane old(*this);
    ++(*this);
    return old;
}



void CPlane::SetNextIdentifier(int v)
{
    s_nextIdentifier = v;
}

int CPlane::GetNextIdentifier()
{
    return s_nextIdentifier;
}
