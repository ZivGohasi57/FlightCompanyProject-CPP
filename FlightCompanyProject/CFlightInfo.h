#pragma once
#include <string>

using namespace std;

class CFlightInfo
{
    friend ostream& operator<<(ostream& os, const CFlightInfo& info);

private:
    int flightNumber;
    string Destination;
    int flightMinutes;
    int flightDistance;


public:
    CFlightInfo(const string Destination, const int flightNum, const int flightMinutes, const int flightDistance);
    CFlightInfo(const CFlightInfo& other);
    ~CFlightInfo();


    // getters
    int getFlightNumber() const;
    string getDestination() const;
    int getFlightMinutes() const;
    int getFlightDistance()const;


    // setters
    bool setFlightNumber(const int newFlightNum);
    void SetDest(const string newDestination);
    bool setFlightMinutes(const int newFlightMinutes);
    bool setFlightDistance(const int newFlightDistance);
    

    // methods 
    bool operator==(const CFlightInfo& other) const;
    void operator=(const CFlightInfo& other);
};

