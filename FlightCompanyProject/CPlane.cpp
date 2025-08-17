#include "CPlane.h"
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
CPlane::CPlane(const int pIdentifier, const int seatNum, const string pModel) :
	planeIdentifier(pIdentifier), planeModel(pModel), numOfSeats(seatNum) {}

CPlane::CPlane(const CPlane& other):
	planeIdentifier(other.planeIdentifier), numOfSeats(other.numOfSeats), 
	planeModel(other.planeModel){}
//gettes
int CPlane::getPlaneIdentifier() const {
	return this->planeIdentifier;
}
string CPlane::getPlaneModel() const {
	return this->planeModel;
}
int CPlane::getNumOfSeats() const {
	return this->numOfSeats;
}
//setters
void CPlane::setPlaneIdentifier(int planeIdentifier) {
	this->planeIdentifier = planeIdentifier;
}
void CPlane::setPlaneModel(string planeModel) {
	this->planeModel = planeModel;
}
void CPlane::setNumOfSeats(int numOfSeats) {
	this->numOfSeats = numOfSeats;
}
//misc
void CPlane::Print() const {
	cout <<"Plane info:\n"
		 << "Plane identifier:" << this->planeIdentifier << "\n"
		 << "Plane model:" << this->planeModel << "\n"
		 << "Number of seats on the plane:" << this->numOfSeats 
		 << endl;
}
bool CPlane::IsEqual(const CPlane& other) const{
	return (this->planeIdentifier == other.planeIdentifier) ? 1: 0;
}
CPlane::~CPlane() {

}
