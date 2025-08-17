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
    CPlane(const int planeIdentifier, const int numOfSeats, const string planeModel);
    CPlane(const CPlane& other);
    //getters
    int getPlaneIdentifier() const;
    string getPlaneModel() const;
    int getNumOfSeats() const;
    //setters
    void setPlaneIdentifier(int planeIdentifier);
    void setPlaneModel(string planeModel);
    void setNumOfSeats(int numOfSeats);
    //misc
    void Print() const;
    bool IsEqual(const CPlane& other) const;
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
