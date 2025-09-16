#pragma once
#include "CPlane.h"
#include <string>
using namespace std;

class CCargo : public CPlane
{
private:
    int maxWeightKg;
    int maxVolume;
    int loadedWeightKg;
    int loadedVolume;

public:
    CCargo() = delete;
    CCargo(int seats, const string model, int maxKg, int maxVol);
    CCargo(const CCargo& other);
    virtual ~CCargo();

    const CCargo& operator=(const CCargo& other);

    bool Load(int kg, int volume);

    int getMaxWeight() const { return maxWeightKg; }
    int getMaxVolume() const { return maxVolume; }
    int getLoadedWeight() const { return loadedWeightKg; }
    int getLoadedVolume() const { return loadedVolume; }
    CPlane* Clone() const override { return new CCargo(*this); }


};
