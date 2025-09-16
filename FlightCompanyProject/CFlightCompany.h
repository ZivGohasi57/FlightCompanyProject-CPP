#pragma once
#include "CCrewMember.h"
#include "CPlane.h"
#include "CFlight.h"
#include <string>

#define MAX_CREWS 10
#define MAX_PLANES 10
#define MAX_FLIGHT 10
using namespace std;

class CFlightCompany
{
    friend ostream& operator<<(ostream& os, const CFlightCompany& company);

private:
    string companyName;
    CCrewMember* crewMembers[MAX_CREWS];
    CPlane* planes[MAX_PLANES];
    CFlight* flights[MAX_FLIGHT];
    int crewCount = 0;
    int planeCount = 0;
    int flightCount = 0;
    static bool IsCargo(const CPlane* p);

public:
    CFlightCompany(const string name);
    CFlightCompany(const CFlightCompany& other);
    bool AddCrewMember(const CCrewMember& member);
    bool AddPlane(const CPlane& plane);
    bool AddFlight(const CFlight& flight);
    bool AddCrewToFlight(int flightNumber, int memberId);
    CPlane* GetPlane(int index);
    void Print(ostream& out);
    CCrewMember* GetCrewMember(int index) const;   
    int CountCargoPlanes() const;
    void NotifyPilotsSimulator() const;
    void DistributePresents() const;
    void UpdateUniforms() const;
    bool Takeoff(int flightNumber);                
    ~CFlightCompany();


    // getters
    string getCompanyName() const;

    // setters
    void SetName(const string newCompnayName);

    void operator=(const CFlightCompany& other);

};
