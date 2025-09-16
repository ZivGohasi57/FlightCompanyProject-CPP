#pragma once
#include <string>
#include <iostream>

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
    virtual ~CPlane();

    virtual CPlane* Clone() const
    {
        return new CPlane(*this);
    }

    int getPlaneIdentifier() const;
    string getPlaneModel() const;
    int getNumOfSeats() const;

    void setPlaneIdentifier(int planeIdentifier);
    void setPlaneModel(string planeModel);
    void setNumOfSeats(int numOfSeats);

    bool operator==(const CPlane& other) const;
    void operator=(const CPlane& other);
    CPlane& operator++();
    CPlane operator++(int);
};
