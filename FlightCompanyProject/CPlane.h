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
    CPlane(int planeIdentifier, const string& planeModel, int numOfSeats);
    int getPlaneIdentifier() const;
    string getPlaneModel() const;
    int getNumOfSeats() const;
    void setPlaneIdentifier(int planeIdentifier);
    void setPlaneModel(string planeModel);
    void setNumOfSeats(int numOfSeats);
    void print() const;
    bool isEqual(const CPlane& other) const;
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
