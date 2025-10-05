#include "PlaneCrewFactory.h"
#include "CPlane.h"
#include "CCargo.h"
#include "CCrewMember.h"
#include "CHost.h"
#include "CPilot.h"
#include "CAddress.h"
#include "CFlightCompany.h"
#include <iostream>
#include <fstream>
using namespace std;

static int read_int()
{
    int x;
    while (!(cin >> x)) { cin.clear(); cin.ignore(1024, '\n'); }
    return x;
}

PlaneType CPlaneCrewFactory::GetPlaneType(const CPlane* pPlane) {
    if (dynamic_cast<const CCargo*>(pPlane)) return eCargo;
    return eRegular;
}

CrewType CPlaneCrewFactory::GetCrewType(const CCrewMember* pCrew) {
    if (dynamic_cast<const CPilot*>(pCrew)) return ePilot;
    return eHost;
}

void CPlaneCrewFactory::GetCompanyDataFromUser(CFlightCompany& comp)
{
    string name;
    cout << "Company name: ";
    cin >> name;
    comp.SetName(name);

    cout << "How many crew members to add? ";
    int nCrew = read_int();
    for (int i = 0; i < nCrew; ++i) {
        CCrewMember* m = GetCrewFromUser();
        if (m) { comp.AddCrewMember(*m); delete m; }
    }

    cout << "How many planes to add? ";
    int nPlanes = read_int();
    for (int i = 0; i < nPlanes; ++i) {
        CPlane* p = GetPlaneFromUser();
        if (p) { comp.AddPlane(*p); delete p; }
    }
}

CPlane* CPlaneCrewFactory::GetPlaneFromUser()
{
    cout << "Plane type (0=regular, 1=cargo): ";
    int t = read_int();

    cout << "Model: ";
    string model; cin >> model;

    cout << "Seats: ";
    int seats = read_int();

    if (t == 1) {
        cout << "Max weight (kg): ";
        int maxKg = read_int();
        cout << "Max volume: ";
        int maxVol = read_int();
        return new CCargo(seats, model, maxKg, maxVol);
    }
    return new CPlane(seats, model);
}

CCrewMember* CPlaneCrewFactory::GetCrewFromUser()
{
    cout << "Crew type (0=host, 1=pilot): ";
    int t = read_int();

    cout << "Name: ";
    string name; cin >> name;

    cout << "Air minutes: ";
    int minutes = read_int();

    if (t == 0) {
        cout << "Host type (0=regular, 1=super, 2=calcelan): ";
        int ht = read_int();
        CHost::eType k = CHost::eRegular;
        if (ht == 1) k = CHost::eSuper;
        else if (ht == 2) k = CHost::eCalcelan;
        CHost* h = new CHost(name.c_str(), k);
        h->setMemberAirTime(minutes);
        return h;
    }
    else {
        cout << "Has home address? (0/1): ";
        int has = read_int();
        const CAddress* addr = nullptr;
        CAddress tmp;
        if (has == 1) {
            cout << "House number: ";
            int house = read_int();
            cout << "Street: ";
            string street; cin >> street;
            cout << "City: ";
            string city; cin >> city;
            tmp = CAddress(house, street.c_str(), city.c_str());
            addr = &tmp;
        }
        cout << "Is captain? (0/1): ";
        int cap = read_int();
        CPilot* p = new CPilot(name, cap == 1, addr);
        p->setMemberAirTime(minutes);
        return p;
    }
}

CCrewMember* CPlaneCrewFactory::GetCrewMemberFromFile(ifstream& in) {
    int type;
    if (!(in >> type)) return nullptr;
    if (type == 0) {
        string name; int minutes; int t;
        in >> name >> minutes >> t;
        CHost::eType ht = CHost::eRegular;
        if (t == 1) ht = CHost::eSuper;
        else if (t == 2) ht = CHost::eCalcelan;
        CHost* h = new CHost(name.c_str(), ht);
        h->setMemberAirTime(minutes);
        return h;
    }
    else {
        string name; int minutes; int hasAddr;
        in >> name >> minutes >> hasAddr;
        const CAddress* addr = nullptr;
        CAddress temp;
        if (hasAddr == 1) {
            int house; string street; string city;
            in >> house >> street >> city;
            temp = CAddress(house, street.c_str(), city.c_str());
            addr = &temp;
        }
        int captain; in >> captain;
        CPilot* p = new CPilot(name, captain == 1, addr);
        p->setMemberAirTime(minutes);
        return p;
    }
}

CPlane* CPlaneCrewFactory::GetPlaneFromFile(ifstream& in) {
    int type;
    if (!(in >> type)) return nullptr;
    if (type == 0) {
        int lastId, id, seats; string model;
        in >> lastId >> id >> model >> seats;
        CPlane* r = new CPlane(seats, model);
        CPlane::SetNextIdentifier(lastId);
        r->setPlaneIdentifier(id);
        return r;
    }
    else {
        int id, seats; string model;
        in >> id >> model >> seats;
        int maxVol, maxKg, vol, kg;
        in >> maxVol >> maxKg >> vol >> kg;
        CCargo* c = new CCargo(seats, model, maxKg, maxVol);
        c->setPlaneIdentifier(id);
        if (vol > 0 || kg > 0) c->Load(kg, vol);
        return c;
    }
}
