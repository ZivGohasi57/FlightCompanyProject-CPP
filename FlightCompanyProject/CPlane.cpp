#include "CPlane.h"
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
CPlane::CPlane(int planeIdentifier, const string& planeModel, int numOfSeats) {
	this->planeIdentifier = planeIdentifier;
	this->planeModel = planeModel;
	this->numOfSeats = numOfSeats;
}
CPlane::CPlane(const CPlane& other) {
	this->planeIdentifier = other.getPlaneIdentifier();
	this->planeModel = other.getPlaneModel();
	this->numOfSeats = other.getNumOfSeats();
}
int CPlane::getPlaneIdentifier() const {
	return this->planeIdentifier;
}
string CPlane::getPlaneModel() const {
	return this->planeModel;
}
int CPlane::getNumOfSeats() const {
	return this->numOfSeats;
}
void CPlane::setPlaneIdentifier(int planeIdentifier) {
	this->planeIdentifier = planeIdentifier;
}
void CPlane::setPlaneModel(string planeModel) {
	this->planeModel = planeModel;
}
void CPlane::setNumOfSeats(int numOfSeats) {
	this->numOfSeats = numOfSeats;
}
void CPlane::print() const {
	cout <<"Plane info:\n"
		 << "Plane identifier:%d\n" << this->planeIdentifier
		 << "Plane model:%s\n" << this->planeModel
		 << "Number of seats on the plane:%d" << this->numOfSeats 
		 << endl;
}
bool CPlane::isEqual(const CPlane& other) const{
	return (this->planeIdentifier == other.planeIdentifier) ? 1: 0;
}
CPlane::~CPlane() {

}
