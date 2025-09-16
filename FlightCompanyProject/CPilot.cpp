#include "CPilot.h"
#include <cmath>

// ctor
CPilot::CPilot(const string& name, bool isCaptain, const CAddress* home)
    : CCrewMember(name), isCaptain(isCaptain), home(home) {}

CPilot::CPilot(const CPilot& other)
    : CCrewMember(other), isCaptain(other.isCaptain), home(other.home) {}

CPilot::~CPilot() {}

// getters
bool CPilot::getIsCaptain() const { return isCaptain; }
const CAddress* CPilot::getHome() const { return home; }

// setters
void CPilot::setIsCaptain(bool captain) { isCaptain = captain; }
void CPilot::setHome(const CAddress* addr) { home = addr; }

// gift
string CPilot::GetPresent() const {
    return isCaptain ? "Whiskey" : "Perfume";
}

// uniform
string CPilot::GetUniform() const {
    return isCaptain ? "Black uniform" : "Blue uniform";
}

// simulator
void CPilot::GoToSimulator() const {
    cout << "Pilot " << getMemberName() << " is going to simulator" << endl;
}

// add airtime
bool CPilot::operator+=(int minutes) {
    if (minutes <= 0) return false;
    int add = minutes;
    if (isCaptain) {
        add = static_cast<int>(round(minutes * 1.1)); // +10%, rounded
    }
    setMemberAirTime(getMemberAirTime() + add);
    return true;
}

// equality
bool CPilot::operator==(const CPilot& other) const {
    if (getMemberName() != other.getMemberName()) return false;

    if (home == nullptr && other.home == nullptr) return true;
    if (home == nullptr || other.home == nullptr) return false;
    return *home == *other.home;
}

// print
void CPilot::Print(ostream& os) const {
    os << "Pilot " << getMemberName()
        << " id " << getMemberId()
        << " air minutes " << getMemberAirTime()
        << " " << (isCaptain ? "[Captain]" : "[Co-Pilot]");
    if (home) os << " Address: " << *home;
    os << endl;
}

ostream& operator<<(ostream& os, const CPilot& pilot) {
    pilot.Print(os);
    return os;
}
