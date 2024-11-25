#pragma once
#include "types.h"

class Data
{
public:
    virtual double cost(const Alpha &alpha) const = 0;
    double weight{1.0};
    virtual ~Data() = default;
};
