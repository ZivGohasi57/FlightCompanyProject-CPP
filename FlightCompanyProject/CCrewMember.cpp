#include "CCrewMember.h"
#include <iostream>

using namespace std;

// ===== Constructors / Destructor =====
CCrewMember::CCrewMember(const string& name, const CAddress& address, int airTime) 
	: memberName(name) , memberAirTime(airTime), memberAddress(address)
{
}

CCrewMember::CCrewMember(const CCrewMember& other)
	: memberName(other.memberName), memberAirTime(other.memberAirTime), memberAddress(other.memberAddress)
{
}

CCrewMember::~CCrewMember()
{
}

// ===== Getters =====
string CCrewMember::getMemberName() const
{
	return this->memberName;
}

int CCrewMember::getMemberAirTime() const
{
	return this->memberAirTime
}

CAddress CCrewMember::getMemberAddress() const
{
	return this->memberAddress;
}

// ===== Setters =====
void CCrewMember::setMemberName(const string newName)
{
	this->memberName = newName;
}

void CCrewMember::setMemberAddress(const CAddress& newAddress)
{
	this->memberAddress = newAddress;
}

// ===== Methods =====
void CCrewMember::print() const
{
	cout << "Crew Member:\n";
	cout << "   Member Name: " << this->memberName << "\n";
	cout << "   Member Air Time" << this->memberAirTime << "\n";
	cout << "   Member Address " << this->memberAddress.print() << "\n";
}

void CCrewMember::updateMemberAirTime(const int minutes)
{
	if (minutes <= 0)
	{
		return;
	}
	this->memberAirTime += minutes;
}

bool CCrewMember::isEqual(const CCrewMember& other) const
{
	if (this->memberName == other.memberName) {
		return true;
	}
	return false;
}
