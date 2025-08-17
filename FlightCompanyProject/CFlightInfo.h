#pragma once
#include <string>

using namespace std;

class CFlightInfo
{
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
    void setFlightNumber(int newFlightNum);
    void setDestination(string newDestination);
    void setFlightMinutes(int newFlightMinutes);
    void setFlightDistance(int newFlightDistance);
    

    // methods 
    bool IsEqual(const CFlightInfo& other) const;


    void print();


private:
    int flightNumber;
    string Destination;
    int flightMinutes;
    int flightDistance;
};

