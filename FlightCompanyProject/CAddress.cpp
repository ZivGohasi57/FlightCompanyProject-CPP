#include "CAddress.h"
#include <string>
#include <iostream>
#include <iomanip>



// ===== Constructor & Destructor =====
CAddress::CAddress(const int hNumber, const char* sName, const char* cName)
{
	if (sName != nullptr) {
		this->streetName = std::string(sName);
	}
	else {
		this->streetName = "";
	}

	if (cName != nullptr) {
		this->cityName = std::string(cName);
	}
	else {
		this->cityName = "";
	}

	setHouseNumber(hNumber);
}
	
CAddress::CAddress(const CAddress& other):
	houseNumber(other.houseNumber), streetName(other.streetName), cityName(other.cityName)
{
}

CAddress::~CAddress() 
{
}


// ===== Getters =====
string CAddress::getCityName() const 
{
	return this->cityName;
}

string CAddress::getStreetName() const 
{
	return this->streetName;
}

int CAddress::getHouseNumber() const 
{
	return this->houseNumber;
}



// ===== Setters =====
void CAddress::setCityName(string cityName) 
{
	this->cityName = cityName;
}

void CAddress::setStreetName(string streetName) 
{
	this->streetName = streetName;
}

void CAddress::setHouseNumber(int houseNumber) 
{
	if (houseNumber <= 0) this->houseNumber = -1;//if invaild 
	this->houseNumber = houseNumber;
}



// ===== Methods =====
ostream& operator<<(ostream& os, const CAddress& address) 
{
	os << address.cityName << " " << address.houseNumber <<
		" " << address.streetName << endl;
	return os;
}


istream& operator>>(std::istream& is, CAddress& a)
{
	cout << "Please enter house number street name and city name" << endl;
	is >> a.houseNumber >> a.cityName >> a.streetName;
	return is;
}

void CAddress:: operator=(const CAddress& other) {
	this->cityName = other.cityName;
	this->streetName = other.streetName;
	this->houseNumber = other.houseNumber;
}

void CAddress::UpdateAddress(const string cityName, const string streetName, const int houseNumber) 
{
	this->cityName = cityName;
	this->streetName = streetName;
	setHouseNumber(houseNumber);
}

bool CAddress::operator==(const CAddress& other) const
{
	return cityName == other.cityName && streetName == other.streetName && houseNumber == other.houseNumber;
}

bool CAddress::operator!=(const CAddress& other) const
{
	return !(cityName == other.cityName && streetName == other.streetName && houseNumber == other.houseNumber);
}

string CAddress::GetCurrentAddress() 
{
	return streetName + " " + to_string(houseNumber) + ", " + cityName + "\n";
}


