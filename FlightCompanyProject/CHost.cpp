#include "CHost.h"
#include <iostream>

using namespace std;

CHost::CHost(const char* name, eType type)
    : CCrewMember(name), m_type(type) {
}

CHost::CHost(const CHost& other)
    : CCrewMember(other), m_type(other.m_type) {
}

CHost::~CHost() = default;

const CHost& CHost::operator=(const CHost& other)
{
    if (this != &other)
    {
        CCrewMember::operator=(other);
        m_type = other.m_type;
    }
    return *this;
}

const char* CHost::TypeToStr(eType t)
{
    switch (t)
    {
    case eRegular:  return "Regular";
    case eSuper:    return "Super";
    case eCalcelan: return "Calaelan";
    default:        return "Regular";
    }
}

void CHost::Print(ostream& os) const
{
    os << "Host " << TypeToStr(m_type) << ' '
        << getMemberName() << " minutes " << getMemberAirTime() << endl;
}

void CHost::GetPresent() const
{
    cout << getMemberName()
        << " thanking the company for receiving the holiday gift" << endl;
    cout << "I was not expecting it" << endl;
}

void CHost::GetUniform() const
{
    cout << getMemberName() << ": I think the new uniform is very nice!" << endl;
}
