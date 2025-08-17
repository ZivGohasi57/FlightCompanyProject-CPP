#pragma once
#include <string>


using namespace std;

class CFlightCompany
{

private:
    string companyName;


public:
    CFlightCompany(const string name);
    CFlightCompany(const CFlightCompany& other);
    ~CFlightCompany();


    // getters
    string getCompanyName() const;

    // setters
    void SetName(const string newCompnayName);


    // methods
    void Print() const;

};
