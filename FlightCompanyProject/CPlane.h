#pragma once
#include <string>

using namespace std;

class CPlane
{
    friend ostream& operator<<(ostream& os, const CPlane& plane);
private:
    static int s_nextIdentifier;
    int planeIdentifier;
    string planeModel;
    int numOfSeats;


public:
    CPlane(const int numOfSeats, const string planeModel);
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
    bool operator==(const CPlane& other) const;
    void operator=(const CPlane& other);
    CPlane& operator++();
    CPlane operator++(int);
    ~CPlane();
};
