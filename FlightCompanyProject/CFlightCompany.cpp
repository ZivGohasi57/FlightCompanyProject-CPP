#include "CFlightCompany.h"
#include <iostream>
using namespace std;

// ===== Constructors / Destructor =====
CFlightCompany::CFlightCompany(const string& name)
	: companyName(name)
{
}

CFlightCompany::CFlightCompany(const CFlightCompany& other)
	: companyName(other.companyName)
{
}

CFlightCompany::~CFlightCompany()
{
}

// ===== Getters =====
string CFlightCompany::getCompanyName() const
{
	return this->companyName;
}

// ===== Setters =====
void CFlightCompany::setCompanyName(const string& newCompnayName)
{
	this->companyName = newCompnayName;
}

// ===== Methods =====
void CFlightCompany::print() const
{
	cout << "Company Name: " << this->companyName << "\n";
}
