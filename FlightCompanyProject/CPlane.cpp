#include "CPlane.h"
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
CPlane::CPlane(int planeIdentifier, string planeModel, int numOfSeats) {
	this->planeIdentifier = planeIdentifier;
	this->planeModel = planeModel;
	this->numOfSeats = numOfSeats;
}
int CPlane::getPlaneIdentifier() {
	return this->planeIdentifier;
}
string CPlane::getPlaneModel() {
	return this->planeModel;
}
int CPlane::getNumOfSeats() {
	return this->numOfSeats;
}
void CPlane::print() {
	cout << "Plane identifier:%d, " << planeIdentifier << "Plane model:%s, " << planeModel
		<< "Number of seats on the plane:%d." << numOfSeats << endl;
}
bool CPlane::isEqual(int planeIdentifier) {
	return (this->planeIdentifier == planeIdentifier) ? 1: 0;
}
CPlane::~CPlane() {

}
