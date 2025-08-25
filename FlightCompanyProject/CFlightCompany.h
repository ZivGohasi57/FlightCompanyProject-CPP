#pragma once
#include <string>


using namespace std;

class CFlightCompany
{
    friend ostream& operator<<(ostream& os, const CFlightCompany& company);

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


};
