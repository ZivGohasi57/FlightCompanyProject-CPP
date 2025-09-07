#include "CFlightCompany.h"
#include <iostream>

// ===== Constructors / Destructor =====
CFlightCompany::CFlightCompany(const string name)
	: companyName(name), crewCount(0), planeCount(0), flightCount(0)
{
	for (int i = 0; i < MAX_CREWS; i++) crewMembers[i] = nullptr;
	for (int i = 0; i < MAX_PLANES; i++) planes[i] = nullptr;
	for (int i = 0; i < MAX_FLIGHT; i++) flights[i] = nullptr;
}

CFlightCompany::CFlightCompany(const CFlightCompany& other)
	: companyName(other.companyName), crewCount(other.crewCount),
	planeCount(other.planeCount), flightCount(other.flightCount)
{
	
	for (int i = 0; i < MAX_CREWS; i++)
		crewMembers[i] = nullptr;
	for (int i = 0; i < MAX_PLANES; i++)
		planes[i] = nullptr;
	for (int i = 0; i < MAX_FLIGHT; i++)
		flights[i] = nullptr;

	
	for (int i = 0; i < crewCount; i++) {
		crewMembers[i] = new CCrewMember(*other.crewMembers[i]);
	}

	
	for (int i = 0; i < planeCount; i++) {
		planes[i] = new CPlane(*other.planes[i]);
	}

	
	for (int i = 0; i < flightCount; i++) {
		flights[i] = new CFlight(*other.flights[i]);
	}
}

bool CFlightCompany::AddCrewMember(const CCrewMember& member) {
	for (int i = 0; i < crewCount; i++) {
		if (crewMembers[i]->getMemberId() == member.getMemberId()) {
			return false;
		}
	}
	if (crewCount >= MAX_CREWS) return false;
	crewMembers[crewCount] = new CCrewMember(member);
	crewCount++;
	return true;
}


bool CFlightCompany::AddPlane(const CPlane& plane) {
	for (int i = 0; i < planeCount; i++) {
		if (planes[i]->getPlaneIdentifier() == plane.getPlaneIdentifier()) {
			return false;
		}
	}
	if (planeCount >= MAX_PLANES) return false;
	planes[planeCount] = new CPlane(plane);
	planeCount++;
	return true;
}


bool CFlightCompany::AddFlight(const CFlight& flight) {
	for (int i = 0; i < flightCount; i++) {
		if (flight == *flights[i]) {
			return false;
		}
	}
	if (flightCount >= MAX_FLIGHT) return false;
	flights[flightCount] = new CFlight(flight);
	flightCount++;
	return true;
}


bool CFlightCompany::AddCrewToFlight(int flightNumber, int memberId) {
	CCrewMember* member = nullptr;
	for (int i = 0; i < crewCount; i++) {
		if (crewMembers[i]->getMemberId() == memberId) {
			member = crewMembers[i];
			break;
		}
	}
	if (!member) return false;
	for (int i = 0; i < flightCount; i++) {
		if (flights[i]->GetFlightInfo().getFlightNumber() == flightNumber) {
			return (*flights[i] + member);
		}
	}
	return false;
}


CPlane* CFlightCompany::GetPlane(int index) {
	if (index >= planeCount || index < 0) return nullptr;
	return planes[index];
}



void CFlightCompany::Print(ostream& out) {
	out << "Flight company: " << companyName << endl;
	out << "There are " << crewCount << " Crew members:" << endl;
	for (int i = 0; i < crewCount; i++) {
		if (crewMembers[i]) out << *crewMembers[i];
	}
	out << "There are " << planeCount << " Planes:" << endl;
	for (int i = 0; i < planeCount; i++) {
		if (planes[i]) out << *planes[i];
	}
	out << "There are " << flightCount << " Flights:" << endl;
	for (int i = 0; i < flightCount; i++) {
		if (flights[i]) out << *flights[i];
	}
}


CFlightCompany::~CFlightCompany()
{
	for (int i = 0; i < crewCount; i++) delete crewMembers[i];
	for (int i = 0; i < planeCount; i++) delete planes[i];
	for (int i = 0; i < flightCount; i++) delete flights[i];
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


void CFlightCompany::operator=(const CFlightCompany& other) {
	if (this == &other) return;
	companyName = other.companyName;
	for (int i = 0; i < crewCount; i++) delete crewMembers[i];
	for (int i = 0; i < planeCount; i++) delete planes[i];
	for (int i = 0; i < flightCount; i++) delete flights[i];
	crewCount = other.crewCount;
	planeCount = other.planeCount;
	flightCount = other.flightCount;
	for (int i = 0; i < crewCount; i++)
		crewMembers[i] = new CCrewMember(*other.crewMembers[i]);
	for (int i = 0; i < planeCount; i++)
		planes[i] = new CPlane(*other.planes[i]);
	for (int i = 0; i < flightCount; i++)
		flights[i] = new CFlight(*other.flights[i]);
}