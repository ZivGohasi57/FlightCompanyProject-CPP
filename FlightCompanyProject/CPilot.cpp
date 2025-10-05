#include "CPilot.h"
using namespace std;

CPilot::CPilot(const string& name, bool isCaptain, const CAddress* home)
    : CCrewMember(name)
{
    this->isCaptain = isCaptain;
    if (home) this->home = new CAddress(*home);
    else this->home = nullptr;
}

CPilot::CPilot(const CPilot& other) : CCrewMember(other)
{
    this->isCaptain = other.isCaptain;
    if (other.home) this->home = new CAddress(*other.home);
    else this->home = nullptr;
}

CPilot::~CPilot()
{
    delete home;
}

bool CPilot::getIsCaptain() const
{
    return isCaptain;
}

const CAddress* CPilot::getHome() const
{
    return home;
}

void CPilot::setIsCaptain(bool captain)
{
    isCaptain = captain;
}

void CPilot::setHome(const CAddress* addr)
{
    delete home;
    if (addr) home = new CAddress(*addr);
    else home = nullptr;
}

void CPilot::GetPresent() const
{
    cout << getMemberName() << " received a pilot present" << endl;
}

void CPilot::GetUniform() const
{
    cout << getMemberName() << " received a pilot uniform" << endl;
}

void CPilot::GoToSimulator() const
{
    cout << "Pilot " << getMemberName() << " is going to the simulator" << endl;
}

bool CPilot::operator==(const CPilot& other) const
{
    return getMemberId() == other.getMemberId();
}

bool CPilot::operator+=(int minutes)
{
    return CCrewMember::operator+=(minutes);
}

void CPilot::Print(ostream& os) const
{
    os << "Pilot: " << getMemberName();
    if (isCaptain) os << " (Captain)";
    os << endl;
    if (home) os << "Home address: " << *home << endl;
    os << "Flight hours: " << getMemberAirTime() << endl;
}

ostream& operator<<(ostream& os, const CPilot& pilot)
{
    pilot.Print(os);
    return os;
}
