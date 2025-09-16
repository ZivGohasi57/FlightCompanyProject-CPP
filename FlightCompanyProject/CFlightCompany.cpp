#include "CFlightCompany.h"
#include "Cpilot.h"  
#include "CCargo.h"   
#include <cctype>
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
	for (int i = 0; i < crewCount; ++i)
		if (crewMembers[i]->getMemberId() == member.getMemberId())
			return false;
	if (crewCount >= MAX_CREWS) return false;
	crewMembers[crewCount++] = member.Clone();
	return true;
}


bool CFlightCompany::AddPlane(const CPlane& plane) {
	for (int i = 0; i < planeCount; ++i)
		if (planes[i]->getPlaneIdentifier() == plane.getPlaneIdentifier())
			return false;
	if (planeCount >= MAX_PLANES) return false;
	planes[planeCount++] = plane.Clone();
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
// --- helper: detect cargo by dynamic type ---
bool CFlightCompany::IsCargo(const CPlane* p) {
	return dynamic_cast<const CCargo*>(p) != nullptr;  // true if CCargo
}

// --- GetCrewMember(index) ---
CCrewMember* CFlightCompany::GetCrewMember(int index) const {
	if (index < 0 || index >= crewCount) return nullptr;
	return crewMembers[index];
}

// --- CountCargoPlanes() ---
int CFlightCompany::GetCargoCount() const {
	int cnt = 0;
	for (int i = 0; i < planeCount; ++i) {
		if (IsCargo(planes[i])) ++cnt;
	}
	return cnt;
}


void CFlightCompany::CrewGetPresent() const {
	for (int i = 0; i < crewCount; ++i) if (crewMembers[i]) crewMembers[i]->GetPresent();
}
void CFlightCompany::CrewGetUniform() const {
	for (int i = 0; i < crewCount; ++i) if (crewMembers[i]) crewMembers[i]->GetUniform();
}
void CFlightCompany::PilotsToSimulator() const {
	for (int i = 0; i < crewCount; ++i)
		if (auto* p = dynamic_cast<CPilot*>(crewMembers[i])) p->GoToSimulator();
}




bool CFlightCompany::Takeoff(int flightNumber) {
	CFlight* flight = GetFlightByNum(flightNumber);
	if (!flight) return false;
	return flight->TakeOff();
}


CFlight* CFlightCompany::GetFlightByNum(int flightNumber) const {
	for (int i = 0; i < flightCount; ++i) {
		if (flights[i] &&
			flights[i]->GetFlightInfo().getFlightNumber() == flightNumber) { // :contentReference[oaicite:2]{index=2}:contentReference[oaicite:3]{index=3}
			return flights[i];
		}
	}
	return nullptr;
}
