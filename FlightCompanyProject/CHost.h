#pragma once

#include "CCrewMember.h"
#include <iosfwd>

using namespace std;


class CHost : public CCrewMember
{
public:
    enum eType { eRegular, eSuper, eCalcelan };

    CHost() = delete;
    CHost(const char* name, eType type);
    CHost(const CHost& other);
    ~CHost() override;

    const CHost& operator=(const CHost& other);

    eType GetType() const { return m_type; }

    void Print(std::ostream& os) const;
    void GetPresent() const;
    void GetUniform() const;

    CCrewMember* Clone() const { return new CHost(*this); }

private:
    static const char* TypeToStr(eType t);
    eType m_type;
};
