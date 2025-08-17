#include "CAddress.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

CAddress::CAddress(string cityName = "Tel Aviv", string streetName, int houseNumber) {
	this->cityName = cityName;
	this->streetName = streetName;
	this->houseNumber = houseNumber;
}
string CAddress::getCityName() {
	return this->cityName;
}
string CAddress::getStreetName() {
	return this->streetName;
}
int CAddress::getHouseNumber() {
	return this->houseNumber;
}
void CAddress::print() {
	cout << "City name:%s, " << cityName << "Street name:%s, " << streetName << "House number:%d." <<
		houseNumber << endl;
}
void CAddress::updateAddress(string cityName, string streetName, int houseNumber) {
	this->cityName = cityName;
	this->streetName = streetName;
	this->houseNumber = houseNumber;
}
CAddress::~CAddress() {
	
}