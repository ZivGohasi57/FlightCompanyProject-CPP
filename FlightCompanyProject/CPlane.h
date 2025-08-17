#pragma once
#include <string>

using namespace std;

class CPlane
{
private:
    int planeIdentifier;
    string planeModel;
    int numOfSeats;
public:
    CPlane(int planeIdentifier, string planeModel, int numOfSeats);
    int getPlaneIdentifier();
    string getPlaneModel();
    int getNumOfSeats();
    void print();
    bool isEqual(int planeIdentifier);
    ~CPlane();
};


// ===== CPlane =====
// members
//
// serial number int
// model name string
// seats count int
//
// methods
//
// ctor
// getters
// print
// is equal (compare by serial number)
