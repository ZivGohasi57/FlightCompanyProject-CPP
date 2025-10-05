#include "CFlightCompany.h"
#include "CPilot.h"
#include "CCargo.h"
#include "CHost.h"
#include "PlaneCrewFactory.h"
#include "CFlightCompException.h"
#include <cctype>
#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

CFlightCompany::CFlightCompany(const string name)
    : companyName(name), crewCount(0), planeCount(0), flightCount(0)
{
    for (int i = 0; i < MAX_CREWS; i++) crewMembers[i] = nullptr;
    for (int i = 0; i < MAX_PLANES; i++) planes[i] = nullptr;
    for (int i = 0; i < MAX_FLIGHT; i++) flights[i] = nullptr;
}

CFlightCompany::CFlightCompany(const string& fileName, int)
    : companyName(""), crewCount(0), planeCount(0), flightCount(0)
{
    for (int i = 0; i < MAX_CREWS; i++) crewMembers[i] = nullptr;
    for (int i = 0; i < MAX_PLANES; i++) planes[i] = nullptr;
    for (int i = 0; i < MAX_FLIGHT; i++) flights[i] = nullptr;

    ifstream in(fileName.c_str());
    if (!in.is_open()) {
        cout << "Cannot open file" << endl;
        CPlaneCrewFactory::GetCompanyDataFromUser(*this);
        if (crewCount == 0) {
            CHost* h = new CHost("temp", CHost::eRegular);
            AddCrewMember(*h);
            delete h;
        }
        return;
    }


    string company;
    in >> company;
    companyName = company;

    int crewCnt;
    in >> crewCnt;
    for (int i = 0; i < crewCnt; ++i) {
        CCrewMember* m = CPlaneCrewFactory::GetCrewMemberFromFile(in);
        if (m) AddCrewMember(*m);
        delete m;
    }

    int planeCnt;
    in >> planeCnt;
    unordered_map<int, CPlane*> idToPlane;
    for (int i = 0; i < planeCnt; ++i) {
        CPlane* p = CPlaneCrewFactory::GetPlaneFromFile(in);
        if (p) {
            int pid = p->getPlaneIdentifier();
            AddPlane(*p);
            delete p;
            idToPlane[pid] = planes[planeCount - 1];
        }
    }

    int flightCnt;
    in >> flightCnt;
    for (int i = 0; i < flightCnt; ++i) {
        string dest; int num; int min; int km; int hasPlane; int planeId = -1;
        in >> dest >> num >> min >> km >> hasPlane;
        if (hasPlane == 1) in >> planeId;
        CFlightInfo fi(dest, num, min, km);
        CPlane* pl = nullptr;
        if (planeId != -1) {
            auto it = idToPlane.find(planeId);
            if (it != idToPlane.end()) pl = it->second;
        }
        CFlight fl(fi, pl);
        int fcrew; in >> fcrew;
        for (int j = 0; j < fcrew; ++j) {
            int t; in >> t;
            string name; in >> name;
            int minutes; in >> minutes;
            if (t == 0) { int skip; in >> skip; }
            else {
                int hasAddr; in >> hasAddr;
                if (hasAddr == 1) { int h; string s, c; in >> h >> s >> c; }
                int cap; in >> cap;
            }
            CCrewMember* found = nullptr;
            for (int k = 0; k < crewCount; ++k)
                if (crewMembers[k]->getMemberName() == name) { found = crewMembers[k]; break; }
            if (found) fl + found;
        }
        AddFlight(fl);
    }
}


CFlightCompany::CFlightCompany(const CFlightCompany& other)
    : companyName(other.companyName), crewCount(other.crewCount),
    planeCount(other.planeCount), flightCount(other.flightCount)
{
    for (int i = 0; i < MAX_CREWS; i++) crewMembers[i] = nullptr;
    for (int i = 0; i < MAX_PLANES; i++) planes[i] = nullptr;
    for (int i = 0; i < MAX_FLIGHT; i++) flights[i] = nullptr;
    for (int i = 0; i < crewCount; i++) crewMembers[i] = new CCrewMember(*other.crewMembers[i]);
    for (int i = 0; i < planeCount; i++) planes[i] = new CPlane(*other.planes[i]);
    for (int i = 0; i < flightCount; i++) flights[i] = new CFlight(*other.flights[i]);
}

CFlightCompany::~CFlightCompany()
{
    for (int i = 0; i < crewCount; i++) delete crewMembers[i];
    for (int i = 0; i < planeCount; i++) delete planes[i];
    for (int i = 0; i < flightCount; i++) delete flights[i];
}

bool CFlightCompany::AddCrewMember(const CCrewMember& member)
{
    for (int i = 0; i < crewCount; ++i)
        if (crewMembers[i]->getMemberId() == member.getMemberId()) return false;
    if (crewCount >= MAX_CREWS) return false;
    crewMembers[crewCount++] = member.Clone();
    return true;
}

bool CFlightCompany::AddPlane(const CPlane& plane)
{
    for (int i = 0; i < planeCount; ++i)
        if (planes[i]->getPlaneIdentifier() == plane.getPlaneIdentifier()) return false;
    if (planeCount >= MAX_PLANES) return false;
    planes[planeCount++] = plane.Clone();
    return true;
}

bool CFlightCompany::AddFlight(const CFlight& flight)
{
    for (int i = 0; i < flightCount; i++)
        if (flight == *flights[i]) return false;
    if (flightCount >= MAX_FLIGHT) return false;
    flights[flightCount] = new CFlight(flight);
    flightCount++;
    return true;
}

bool CFlightCompany::AddCrewToFlight(int flightNumber, int memberId)
{
    CCrewMember* member = nullptr;
    for (int i = 0; i < crewCount; i++)
        if (crewMembers[i]->getMemberId() == memberId) { member = crewMembers[i]; break; }
    if (!member) return false;
    for (int i = 0; i < flightCount; i++)
        if (flights[i]->GetFlightInfo().getFlightNumber() == flightNumber)
            return (*flights[i] + member);
    return false;
}

CPlane* CFlightCompany::GetPlane(int index)
{
    if (index >= planeCount || index < 0) return nullptr;
    return planes[index];
}

CPlane& CFlightCompany::operator[](int index)
{
    if (planeCount > 0 && index >= 0 && index < planeCount) return *(planes[index]);
    static CPlane dummy(1, "Dummy");
    return dummy;
}

const CPlane& CFlightCompany::operator[](int index) const
{
    if (planeCount > 0 && index >= 0 && index < planeCount) return *(planes[index]);
    static CPlane dummy(1, "Dummy");
    return dummy;
}


void CFlightCompany::Print(ostream& out)
{
    out << "Flight company: " << (companyName.empty() ? "Unnamed" : companyName) << endl;
    out << "There are " << crewCount << " Crew members:" << endl;
    for (int i = 0; i < crewCount; i++) if (crewMembers[i]) out << *crewMembers[i];
    out << "There are " << planeCount << " Planes:" << endl;
    for (int i = 0; i < planeCount; i++) if (planes[i]) out << *planes[i];
    out << "There are " << flightCount << " Flights:" << endl;
    for (int i = 0; i < flightCount; i++) if (flights[i]) out << *flights[i];
}


string CFlightCompany::getCompanyName() const { return this->companyName; }
void CFlightCompany::SetName(const string newCompnayName) { this->companyName = newCompnayName; }

ostream& operator<<(ostream& os, const CFlightCompany& company)
{
    os << "Flight company: " << company.companyName << endl;
    return os;
}

void CFlightCompany::operator=(const CFlightCompany& other)
{
    if (this == &other) return;
    companyName = other.companyName;
    for (int i = 0; i < crewCount; i++) delete crewMembers[i];
    for (int i = 0; i < planeCount; i++) delete planes[i];
    for (int i = 0; i < flightCount; i++) delete flights[i];
    crewCount = other.crewCount;
    planeCount = other.planeCount;
    flightCount = other.flightCount;
    for (int i = 0; i < crewCount; i++) crewMembers[i] = new CCrewMember(*other.crewMembers[i]);
    for (int i = 0; i < planeCount; i++) planes[i] = new CPlane(*other.planes[i]);
    for (int i = 0; i < flightCount; i++) flights[i] = new CFlight(*other.flights[i]);
}

bool CFlightCompany::IsCargo(const CPlane* p) { return dynamic_cast<const CCargo*>(p) != nullptr; }

CCrewMember* CFlightCompany::GetCrewMember(int index) const
{
    if (index < 0 || index >= crewCount) return nullptr;
    return crewMembers[index];
}

int CFlightCompany::GetCargoCount() const
{
    int cnt = 0;
    for (int i = 0; i < planeCount; ++i) if (IsCargo(planes[i])) ++cnt;
    return cnt;
}

void CFlightCompany::CrewGetPresent() const
{
    for (int i = 0; i < crewCount; ++i) if (crewMembers[i]) crewMembers[i]->GetPresent();
}

void CFlightCompany::CrewGetUniform() const
{
    for (int i = 0; i < crewCount; ++i) if (crewMembers[i]) crewMembers[i]->GetUniform();
}

void CFlightCompany::PilotsToSimulator() const
{
    for (int i = 0; i < crewCount; ++i) if (auto* p = dynamic_cast<CPilot*>(crewMembers[i])) p->GoToSimulator();
}

bool CFlightCompany::Takeoff(int flightNumber)
{
    CFlight* flight = GetFlightByNum(flightNumber);
    if (!flight) return false;
    return flight->TakeOff();
}

CFlight* CFlightCompany::GetFlightByNum(int flightNumber) const
{
    for (int i = 0; i < flightCount; ++i)
        if (flights[i] && flights[i]->GetFlightInfo().getFlightNumber() == flightNumber) return flights[i];
    return nullptr;
}

void CFlightCompany::SaveToFile(const string& fileName) const
{
    ofstream out(fileName.c_str());
    if (!out.is_open()) throw CCompFileException(fileName, "Cannot open file for write");
    out << companyName << endl;
    out << crewCount << endl;
    for (int i = 0; i < crewCount; ++i) {
        if (dynamic_cast<CHost*>(crewMembers[i])) {
            CHost* h = dynamic_cast<CHost*>(crewMembers[i]);
            int t = 0;
            if (h->GetType() == CHost::eSuper) t = 1;
            else if (h->GetType() == CHost::eCalcelan) t = 2;
            out << 0 << ' ' << h->getMemberName() << ' ' << h->getMemberAirTime() << ' ' << t << endl;
        }
        else if (dynamic_cast<CPilot*>(crewMembers[i])) {
            CPilot* p = dynamic_cast<CPilot*>(crewMembers[i]);
            out << 1 << ' ' << p->getMemberName() << ' ' << p->getMemberAirTime() << ' ';
            if (p->getHome()) out << 1 << ' ' << p->getHome()->getHouseNumber() << ' ' << p->getHome()->getStreetName() << ' ' << p->getHome()->getCityName() << ' ';
            else out << 0 << ' ';
            out << (p->getIsCaptain() ? 1 : 0) << endl;
        }
    }
    out << planeCount << endl;
    for (int i = 0; i < planeCount; ++i) {
        if (dynamic_cast<CCargo*>(planes[i])) {
            CCargo* c = dynamic_cast<CCargo*>(planes[i]);
            out << 1 << ' ' << c->getPlaneIdentifier() << ' ' << c->getPlaneModel() << ' ' << c->getNumOfSeats() << endl;
            out << c->getMaxVolume() << " " << c->getMaxWeight() << " " << c->getLoadedVolume() << " " << c->getLoadedWeight() << endl;
        }
        else {
            out << 0 << ' ' << CPlane::GetNextIdentifier() << ' ' << planes[i]->getPlaneIdentifier() << ' ' << planes[i]->getPlaneModel() << ' ' << planes[i]->getNumOfSeats() << endl;
        }
    }
    out << flightCount << endl;
    for (int i = 0; i < flightCount; ++i) {
        CFlight* f = flights[i];
        out << f->GetFlightInfo().getDestination() << ' ' << f->GetFlightInfo().getFlightNumber() << ' ' << f->GetFlightInfo().getFlightMinutes() << ' ' << f->GetFlightInfo().getFlightDistance() << ' ';
        if (f->GetPlane()) out << 1 << ' ' << f->GetPlane()->getPlaneIdentifier() << endl;
        else out << 0 << endl;
        out << f->GetCrewCount() << endl;
        for (int j = 0; j < f->GetCrewCount(); ++j) {
            CCrewMember* m = f->GetCrew()[j];
            if (dynamic_cast<CHost*>(m)) {
                CHost* h = dynamic_cast<CHost*>(m);
                int t = 0;
                if (h->GetType() == CHost::eSuper) t = 1;
                else if (h->GetType() == CHost::eCalcelan) t = 2;
                out << 0 << ' ' << h->getMemberName() << ' ' << h->getMemberAirTime() << ' ' << t << endl;
            }
            else if (dynamic_cast<CPilot*>(m)) {
                CPilot* p = dynamic_cast<CPilot*>(m);
                out << 1 << ' ' << p->getMemberName() << ' ' << p->getMemberAirTime() << ' ';
                if (p->getHome()) out << 1 << ' ' << p->getHome()->getHouseNumber() << ' ' << p->getHome()->getStreetName() << ' ' << p->getHome()->getCityName() << ' ';
                else out << 0 << ' ';
                out << (p->getIsCaptain() ? 1 : 0) << endl;
            }
        }
    }
}

int CFlightCompany::GetCrewCount() const { return crewCount; }
int CFlightCompany::GetPlaneCount() const { return planeCount; }
int CFlightCompany::GetFlightCount() const { return flightCount; }
