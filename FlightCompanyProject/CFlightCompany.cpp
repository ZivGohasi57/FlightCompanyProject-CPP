#include "CFlightCompany.h"
#include <iostream>

// ===== Constructors / Destructor =====
CFlightCompany::CFlightCompany(const string name)
	: companyName(name)
{
}

CFlightCompany::CFlightCompany(const CFlightCompany& other)
	: companyName(other.companyName)
{
}
bool CFlightCompany::AddCrewMember(CCrewMember member) {
	for (int i = 0; i < crewCount; i++) {
		if (member.getMemberName() == crewMembers[i]->getMemberName()) {
			return 0;
		}
	}
	*crewMembers[crewCount] = member;
	return 1;
}

bool CFlightCompany::AddPlane(CPlane plane) {
	for (int i = 0; i < planeCount; i++) {
		if (plane.getPlaneIdentifier() == planes[i]->getPlaneIdentifier()) {
			return 0;
		}
	}
	*planes[planeCount] = plane;
}

bool CFlightCompany::AddFlight(CFlight flight) {
	for (int i = 0; i < flightCount; i++) {
		if (flight == *flights[i]) {
			return 0;
		}
	}
	*flights[flightCount] = flight;
}
bool CFlightCompany::AddCrewToFlight(int flightNumber, int memberId) {
	CCrewMember* member;
	for (int i = 0; i < crewCount; i++) {
		if (crewMembers[i]->getMemberId() == memberId) member = crewMembers[i];
	}
	for (int i = 0; i < flightCount; i++) {
		if (flights[i]->GetFlightInfo().getFlightNumber() == flightNumber) {
			*flights[i] + member;
		}
	}
}
CPlane* CFlightCompany::GetPlane(int index) {
	if (index > MAX_PLANES || index < 0) {
		return nullptr;
	}
	return planes[index];
}
void CFlightCompany::Print(ostream& out) {
	out << "Flight company:" << companyName
		<< "\n" << "there are " << crewCount << " Crew members:" << endl;
	for (int i = 0; i < crewCount; i++) {
		out << crewMembers[i];
	}
	out << "there are " << planeCount << " Planes:" << endl;
	for (int i = 0; i < planeCount; i++) {
		out << planes[i];
	}
	out << "there are " << flightCount << " Flights:" << endl;
	for (int i = 0; i < flightCount; i++) {
		out << flights[i];
	}
}

CFlightCompany::~CFlightCompany()
{
}

// ===== Getters =====
string CFlightCompany::getCompanyName() const
{
	return this->companyName;
}

// ===== Setters =====
void CFlightCompany::SetName(const string newCompnayName)
{
	this->companyName = newCompnayName;
}

// ===== Methods =====
ostream& operator<<(ostream& os, const CFlightCompany& company)
{
	os << "Flight company: " << company.companyName << endl;
	return os;
}


void CFlightCompany:: operator=(const CFlightCompany& other) {
	this->companyName = other.companyName;
}