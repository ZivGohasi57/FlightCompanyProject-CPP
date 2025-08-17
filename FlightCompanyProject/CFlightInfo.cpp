#include "CFlightInfo.h"
#include <iostream>

using namespace std;

// ===== Constructor & Destructor =====
CFlightInfo::CFlightInfo(const string flightDest, const int flightNum, const int flightMin, const int flightDis)
	: Destination(flightDest) , flightNumber(flightNum), flightMinutes(flightMin), flightDistance(flightDis)
{
}

CFlightInfo::CFlightInfo(const CFlightInfo& other)
	: Destination(other.Destination) , flightDistance(other.flightDistance), flightMinutes(other.flightMinutes) , flightNumber(other.flightNumber)
{
}



CFlightInfo::~CFlightInfo()
{
}



// ===== Getters =====
int CFlightInfo::getFlightNumber() const
{
	return this->flightNumber;
}

string CFlightInfo::getDestination() const
{
	return this->Destination;

}

int CFlightInfo::getFlightMinutes() const
{
	return this->flightMinutes;

}

int CFlightInfo::getFlightDistance() const
{
	return this->flightDistance;

}

// ===== Setters =====
bool CFlightInfo::setFlightNumber(const int newFlightNum)
{
	if (newFlightNum > 0)
	{
		this->flightNumber = newFlightNum;
		return true;
	}
	return false;
}

void CFlightInfo::SetDest(const string newDestination)
{
	this->Destination = newDestination;
}

bool CFlightInfo::setFlightMinutes(const int newFlightMinutes)
{
	if (newFlightMinutes >= 0)
	{
		this->flightMinutes = newFlightMinutes;
		return true;
	}
	return false;
}

bool CFlightInfo::setFlightDistance(const int newFlightDistance)
{
	if (newFlightDistance >= 0)
	{
		this->flightDistance = newFlightDistance;
		return true;
	}
	return false;
}

// ===== Methods =====
bool CFlightInfo::IsEqual(const CFlightInfo& other) const
{
	if (this->flightNumber == other.flightNumber) 
	{
		return true;
	}
	return false;
}

void CFlightInfo::Print() const
{
	cout << "Flight Info:\n";
	cout << "Flight Number: " << this->flightNumber << "\n";
	cout << "Flight Destination: " << this->Destination << "\n";
	cout << "Flight Minutes: " << this->flightMinutes << "\n";
	cout << "Flight Distance: " << this->flightDistance << "\n";

}
