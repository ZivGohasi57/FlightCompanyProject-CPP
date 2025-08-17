#pragma once
#include <string>

using namespace std;

class CFlightInfo
{
public:
    CFlightInfo(int flightNum , string Destination, int flightMinutes, int flightDistance);
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
    bool isEqual(int flightNum1, int flightNum2);


    void print();


private:
    int flightNumber;
    string Destination;
    int flightMinutes;
    int flightDistance;
};



// ===== CFlightInfo =====
// members
//
// flight number int
// destination string
// flight time minutes int
// distance km int
//
// methods
//
// ctor
// setters & getters
// is equal (compare by flight number)
// print
