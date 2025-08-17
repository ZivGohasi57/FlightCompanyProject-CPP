#include "CFlightInfo.h"
#include <iostream>
using namespace std;

// ===== Constructor & Destructor =====
CFlightInfo::CFlightInfo(int flightNum, string Destination, int flightMinutes, int flightDistance)
{
	this->flightNumber = flightNum;
	this->Destination = Destination;
	this->flightMinutes = flightMinutes;
	this->flightDistance = flightDistance;
}

CFlightInfo::CFlightInfo(const CFlightInfo& other)
{
	this->Destination = other.Destination;
	this->flightDistance = other.flightDistance;
	this->flightMinutes = other.flightMinutes;
	this->flightNumber = other.flightNumber;
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
	return this->Destination

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
void CFlightInfo::setFlightNumber(int newFlightNum)
{
	this->flightNumber = newFlightNum;
}

void CFlightInfo::setDestination(string newDestination)
{
	this->Destination = newDestination;
}

void CFlightInfo::setFlightMinutes(int newFlightMinutes)
{
	this->flightMinutes = newFlightMinutes;
}

void CFlightInfo::setFlightDistance(int newFlightDistance)
{
	this->flightDistance = newFlightDistance;
}

// ===== Methods =====
bool CFlightInfo::IsEqual(const CFlightInfo& other) const
{
	if (this->flightNumber == other.flightNumber) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void CFlightInfo::print()
{
	cout << "Flight Info:\n";
	cout << "   Flight Number: " + this->flightNumber + "\n";
	cout << "   Flight Destination: " + this->Destination + "\n";
	cout << "   Flight Minutes: " + this->flightMinutes + "\n";
	cout << "   Flight Distance: " + this->flightDistance + "\n";

}
