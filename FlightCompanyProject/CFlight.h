#pragma once
#include <iostream>
#include "CFlightInfo.h"
#include "CPlane.h"
#include "CCrewMember.h"

using namespace std;

#define MAX_CREW 10

class CFlight
{
	friend ostream& operator<<(ostream& os, const CFlight& address);

private:
	CFlightInfo info;
	CPlane* plane;
	CCrewMember* crew[MAX_CREW];
	int crewCount;

public:
	CFlight(const CFlightInfo& flightInfo, CPlane* flightPlane = nullptr);
	~CFlight();

	void SetPlane(CPlane* newPlane);
	CPlane* GetPlane() const;

	void SetFlightInfo(const CFlightInfo& newInfo);
	CFlightInfo GetFlightInfo() const;

	int GetCrewCount() const;

	bool operator+(CCrewMember* meber);

	bool operator==(const CFlight& other) const;
};

