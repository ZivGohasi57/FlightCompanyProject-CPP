#include "CPilot.h"
#include <cmath>
#include <iostream>
using namespace std;

CPilot::CPilot(const string& name, bool isCaptain, const CAddress* home)
    : CCrewMember(name), isCaptain(isCaptain), home(home) {
}

CPilot::CPilot(const CPilot& other)
    : CCrewMember(other), isCaptain(other.isCaptain), home(other.home) {
}

CPilot::~CPilot() {}

bool CPilot::getIsCaptain() const { return isCaptain; }
const CAddress* CPilot::getHome() const { return home; }
void CPilot::setIsCaptain(bool captain) { isCaptain = captain; }
void CPilot::setHome(const CAddress* addr) { home = addr; }

void CPilot::GetPresent() const {
    cout << getMemberName()
        << " thanking the company for receiving the holiday gift" << endl;
}
void CPilot::GetUniform() const {
    cout << getMemberName()
        << ": this is the fifth time I get a new uniform, this is a waste of money!" << endl;
}
void CPilot::GoToSimulator() const {
    cout << "Pilot " << getMemberName() << " got the message will come soon" << endl;
}

bool CPilot::operator+=(int minutes) {
    if (minutes <= 0) return false;
    int add = minutes;
    if (isCaptain) add = static_cast<int>(round(minutes * 1.1));
    setMemberAirTime(getMemberAirTime() + add);
    return true;
}

bool CPilot::operator==(const CPilot& other) const {
    if (getMemberName() != other.getMemberName()) return false;
    if (home == nullptr && other.home == nullptr) return true;
    if (home == nullptr || other.home == nullptr) return false;
    return *home == *other.home;
}

void CPilot::Print(std::ostream& os) const {
    os << "Pilot  " << getMemberName()
        << " minutes " << getMemberAirTime();
    if (home) os << " Home " << *home;
    if (isCaptain) os << "  a Captain" << std::endl;
    else           os << "\n Not a Captain" << std::endl;
}


ostream& operator<<(ostream& os, const CPilot& pilot) {
    pilot.Print(os);
    return os;
}
