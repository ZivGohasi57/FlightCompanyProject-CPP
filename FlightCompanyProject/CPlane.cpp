#include "CPlane.h"
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;


// ===== Constructor & Destructor =====
CPlane::CPlane(const int pIdentifier, const int seatNum, const string pModel):
numOfSeats(seatNum), planeModel(pModel)
{
	setPlaneIdentifier(pIdentifier);
}

CPlane::CPlane(const CPlane& other):
	planeIdentifier(other.planeIdentifier), numOfSeats(other.numOfSeats), 
	planeModel(other.planeModel)
{
}

CPlane::~CPlane()
{
}

// ===== Getters =====
int CPlane::getPlaneIdentifier() const 
{
	return this->planeIdentifier;
}

string CPlane::getPlaneModel() const 
{
	return this->planeModel;
}

int CPlane::getNumOfSeats() const 
{
	return this->numOfSeats;
}


// ===== Setters =====
void CPlane::setPlaneIdentifier(int planeIdentifier) 
{
	if (planeIdentifier <= 0) this->planeIdentifier = -1; // if invaild
	this->planeIdentifier = planeIdentifier;
}

void CPlane::setPlaneModel(string planeModel) 
{
	this->planeModel = planeModel;
}

void CPlane::setNumOfSeats(int numOfSeats) 
{
	this->numOfSeats = numOfSeats;
}


// ===== Methods =====
void CPlane::Print() const 
{
	cout <<"Plane " << planeIdentifier << " degem " << planeModel <<
		" seats " << numOfSeats << endl;
}

bool CPlane::IsEqual(const CPlane& other) const
{
	return (this->planeIdentifier == other.planeIdentifier) ? 1: 0;
}
