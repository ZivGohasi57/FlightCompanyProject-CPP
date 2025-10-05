#include "CFlightInfo.h"
#include "CFlightCompException.h"
#include <iostream>
using namespace std;

CFlightInfo::CFlightInfo(const string flightDest, const int flightNum, const int flightMin, const int flightDis)
    : Destination(flightDest)
{
    if (Destination.size() > 20) Destination = Destination.substr(0, 20);
    setFlightNumber(flightNum);
    setFlightMinutes(flightMin);
    setFlightDistance(flightDis);
}


CFlightInfo::CFlightInfo(const CFlightInfo& other)
    : Destination(other.Destination),
    flightDistance(other.flightDistance),
    flightMinutes(other.flightMinutes),
    flightNumber(other.flightNumber)
{
}

CFlightInfo::~CFlightInfo() {}

int CFlightInfo::getFlightNumber() const { return this->flightNumber; }
string CFlightInfo::getDestination() const { return this->Destination; }
int CFlightInfo::getFlightMinutes() const { return this->flightMinutes; }
int CFlightInfo::getFlightDistance() const { return this->flightDistance; }

bool CFlightInfo::setFlightNumber(const int newFlightNum)
{
    if (newFlightNum > 0) { this->flightNumber = newFlightNum; return true; }
    this->flightNumber = -1; return false;
}

void CFlightInfo::SetDest(const string newDestination) { this->Destination = newDestination; }

bool CFlightInfo::setFlightMinutes(const int newFlightMinutes)
{
    if (newFlightMinutes >= 0) { this->flightMinutes = newFlightMinutes; return true; }
    this->flightMinutes = -1; return false;
}

bool CFlightInfo::setFlightDistance(const int newFlightDistance)
{
    if (newFlightDistance >= 0) { this->flightDistance = newFlightDistance; return true; }
    this->flightDistance = -1; return false;
}

int CFlightInfo::GetFNum() { return flightNumber; }

bool CFlightInfo::operator==(const CFlightInfo& other) const { return this->flightNumber == other.flightNumber; }
bool CFlightInfo::operator!=(const CFlightInfo& other) const { return this->flightNumber != other.flightNumber; }

void CFlightInfo::operator=(const CFlightInfo& other)
{
    this->Destination = other.Destination;
    this->flightDistance = other.flightDistance;
    this->flightMinutes = other.flightMinutes;
    this->flightNumber = other.flightNumber;
}

ostream& operator<<(ostream& os, const CFlightInfo& info)
{
    os << "Flight Info dest: " << info.Destination
        << " Number " << info.flightNumber
        << " minutes " << info.flightMinutes
        << " KM " << info.flightDistance << endl;
    return os;
}

CFlightInfo::operator int() const { return this->flightMinutes; }
