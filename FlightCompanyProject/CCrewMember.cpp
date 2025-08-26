#include "CCrewMember.h"
#include <iostream>

using namespace std;


int CCrewMember::s_crewMemberNumber = 1000;

// ===== Constructors / Destructor =====
CCrewMember::CCrewMember(const string name, const CAddress& address, int airTime) 
	: crewMemberNumber(s_crewMemberNumber++), memberName(name), memberAddress(address)
{
	setMemberAirTime(airTime);
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
	return this->memberAirTime;
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

void CCrewMember::setMemberAirTime(const int airTime)
{
	if (airTime > 0) 
	{
		this->memberAirTime = airTime;
		return;
	}
	this->memberAirTime = 0;
}

// ===== Methods =====
ostream& operator<<(ostream& os, const CCrewMember& member)
{
	os << "Crewmember " << member.memberName
		<< " minutes " << member.memberAirTime << endl;
	return os;
}
void CCrewMember::operator=(const CCrewMember& other) {
	this->memberAddress = other.memberAddress;
	this->memberAirTime = other.memberAirTime;
	this->memberName = other.memberName;
}

bool CCrewMember::operator==(const CCrewMember& other) const {
	return crewMemberNumber == other.crewMemberNumber;
}

bool CCrewMember::operator+=(const int minutes)
{
	if (minutes > 0)
	{
		this->memberAirTime += minutes;	
		return true;
	}
	return false;
}


