#pragma once
#include "CCrewMember.h"
#include <iostream>

using namespace std;

class CHost : public CCrewMember
{
public:
    enum eType { eRegular, eSuper, eCalcelan };

    CHost() = delete;
    CHost(const char* name, eType type);
    CHost(const CHost& other);
    ~CHost();

    const CHost& operator=(const CHost& other);

    eType GetType() const;

    void Print(ostream& os) const override;
    void GetPresent() const override;
    void GetUniform() const override;

    CCrewMember* Clone() const override;

private:
    static const char* TypeToStr(eType t);
    eType m_type;
};
