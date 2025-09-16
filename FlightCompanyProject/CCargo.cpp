#include "CCargo.h"

CCargo::CCargo(int seats, const std::string model, int maxKg, int maxVol)
    : CPlane(seats, model), maxWeightKg(maxKg), maxVolume(maxVol),
    loadedWeightKg(0), loadedVolume(0) {
}

CCargo::CCargo(const CCargo& other)
    : CPlane(other), maxWeightKg(other.maxWeightKg), maxVolume(other.maxVolume),
    loadedWeightKg(other.loadedWeightKg), loadedVolume(other.loadedVolume) {
}

CCargo::~CCargo() {}

const CCargo& CCargo::operator=(const CCargo& other)
{
    if (this != &other)
    {
        CPlane::operator=(other);
        maxWeightKg = other.maxWeightKg;
        maxVolume = other.maxVolume;
        loadedWeightKg = other.loadedWeightKg;
        loadedVolume = other.loadedVolume;
    }
    return *this;
}

bool CCargo::Load(int kg, int volume)
{
    if (kg < 0 || volume < 0) return false;
    if (loadedWeightKg + kg > maxWeightKg) return false;
    if (loadedVolume + volume > maxVolume) return false;
    loadedWeightKg += kg;
    loadedVolume += volume;
    return true;
}
