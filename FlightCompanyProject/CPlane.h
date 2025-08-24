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

    // getters
    int getPlaneIdentifier() const;
    string getPlaneModel() const;
    int getNumOfSeats() const;

    // setters
    void setPlaneIdentifier(int planeIdentifier);
    void setPlaneModel(string planeModel);
    void setNumOfSeats(int numOfSeats);

    // methods
    void Print() const;
    bool IsEqual(const CPlane& other) const;
    ~CPlane();
};
