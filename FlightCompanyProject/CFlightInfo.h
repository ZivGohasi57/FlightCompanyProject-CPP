#pragma once
#include <string>

using namespace std;

class CFlightInfo
{

private:
    int flightNumber;
    string Destination;
    int flightMinutes;
    int flightDistance;


public:
    CFlightInfo(const int flightNum , const string& Destination, const int flightMinutes, const int flightDistance);
    CFlightInfo(const CFlightInfo& other);
    ~CFlightInfo();


    // getters
    int getFlightNumber() const;
    string getDestination() const;
    int getFlightMinutes() const;
    int getFlightDistance()const;


    // setters
    void setFlightNumber(const int newFlightNum);
    void setDestination(const string& newDestination);
    void setFlightMinutes(const int newFlightMinutes);
    void setFlightDistance(const int newFlightDistance);
    

    // methods 
    bool IsEqual(const CFlightInfo& other) const;


    void print() const;



};

