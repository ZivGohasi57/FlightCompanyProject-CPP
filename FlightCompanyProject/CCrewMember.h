#pragma once
#include <string>
#include "CAddress.h"

using namespace std;

class CCrewMember
{
public:
    CCrewMember();
    ~CCrewMember();
};

// ===== CCrewMember =====
// members
//
// name string
// air time minutes int
// address CAddress
//
// methods
//
// ctor (with and without air time)
// update minutes (add minutes with validation)
// set/get name
// set/get address
// get air time
// print
// is equal (compare by name)
