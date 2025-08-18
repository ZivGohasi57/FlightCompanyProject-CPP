#include "CAddress.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

CAddress::CAddress(const int hNumber, const string sName, const string cName)
: streetName(sName), cityName(cName)
{
	setHouseNumber(hNumber);
}
	
CAddress::CAddress(const CAddress& other):
	houseNumber(other.houseNumber), streetName(other.streetName), cityName(other.cityName){}
//getters
string CAddress::getCityName() const {
	return this->cityName;
}
string CAddress::getStreetName() const {
	return this->streetName;
}
int CAddress::getHouseNumber() const {
	return this->houseNumber;
}
//setters
void CAddress::setCityName(string cityName) {
	this->cityName = cityName;
}
void CAddress::setStreetName(string streetName) {
	this->streetName = streetName;
}
void CAddress::setHouseNumber(int houseNumber) {
	if (houseNumber <= 0) this->houseNumber = -1;//if invaild 
	this->houseNumber = houseNumber;
}
//misc
void CAddress::Print() const {
	cout << "Address info:\n" 
		<< "House number: " << this->houseNumber << "\n"
		<< "Street name: " << this->streetName << "\n"
		<< "City name: " << this->cityName 
		<< endl;
}
void CAddress::UpdateAddress(const string cityName, const string streetName, const int houseNumber) {
	this->cityName = cityName;
	this->streetName = streetName;
	setHouseNumber(houseNumber);
}
CAddress::~CAddress() {
	
}