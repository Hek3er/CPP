#pragma once

#include <iostream>
#include <time.h>
#include <stdlib.h>

class Base {
public:
    virtual ~Base();
};

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);