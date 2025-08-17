#include "CAddress.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

CAddress::CAddress(int hNumber, string sName, string cName) :
	houseNumber(hNumber), streetName(sName), cityName(cName) {}
	
CAddress::CAddress(const CAddress& other) {
	this->houseNumber = other.getHouseNumber();
	this->streetName = other.getStreetName();
	this->cityName = other.getCityName();
}
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
	this->houseNumber = houseNumber;
}
//misc
void CAddress::Print() const {
	cout << "Address info\n" 
		<< "House number:%d" << this->houseNumber 
		<< "Street name:%s\n" << this->streetName
		<< "City name:%s\n" << this->cityName 
		<< endl;
}
void CAddress::UpdateAddress(const string cityName, const string streetName, const int houseNumber) {
	this->cityName = cityName;
	this->streetName = streetName;
	this->houseNumber = houseNumber;
}
CAddress::~CAddress() {
	
}