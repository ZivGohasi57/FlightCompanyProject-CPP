#pragma once
#include <string>


using namespace std;

class CFlightCompany
{

private:
    string companyName;


public:
    CFlightCompany(const string& name);
    CFlightCompany(const CFlightCompany& other);
    ~CFlightCompany();


    // getters
    string getCompanyName() const;

    // setters
    void setCompanyName(const string& newCompnayName);


    // methods
    void print() const;

};
