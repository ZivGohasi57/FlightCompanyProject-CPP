#include "CCrewMember.h"
#include <iostream>



int CCrewMember::s_nextId = CCrewMember::START_ID;

// ===== Constructors / Destructor =====
CCrewMember::CCrewMember(const string name, const CAddress& address, int airTime) 
	: crewMemberNumber(s_nextId++), memberName(name), memberAddress(address)
{
	setMemberAirTime(airTime);
}

CCrewMember::CCrewMember(const string name)
	: CCrewMember(name, CAddress(), 0) {
}


CCrewMember::CCrewMember(const string name, int airTime)
	: crewMemberNumber(s_nextId++), memberName(name), memberAddress(CAddress())
{
	setMemberAirTime(airTime);
}


CCrewMember::CCrewMember(const CCrewMember& other)
	: crewMemberNumber(other.crewMemberNumber),
	memberName(other.memberName),
	memberAirTime(other.memberAirTime),
	memberAddress(other.memberAddress)
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
 
int CCrewMember::getMemberId() const
{
	return crewMemberNumber;
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
	if (this == &other) return;
	crewMemberNumber = other.crewMemberNumber;
	memberAddress = other.memberAddress;
	memberAirTime = other.memberAirTime;
	memberName = other.memberName;
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

void CCrewMember::Print(ostream& os) const {
	os << "Crewmember " << getMemberName()
		<< " minutes " << getMemberAirTime() << endl;
}


void CCrewMember::GetPresent() const {
	cout << getMemberName()
		<< " thanking the company for receiving the holiday gift" << endl;
}

void CCrewMember::GetUniform() const {
	cout << getMemberName()
		<< ": this is the fifth time I change uniform this year" << endl;
}


