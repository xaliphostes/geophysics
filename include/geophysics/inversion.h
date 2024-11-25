#pragma once
#include "types.h"
#include "Data.h"
#include "mapping.h"

struct InversionModel
{
    std::vector<std::shared_ptr<Data>> data;
    struct
    {
        Mapping mapping;
        std::vector<double> min;
        std::vector<double> max;
    } alpha;
    ProgressCallback onProgress;
    MessageCallback onMessage;
};

struct InversionResult
{
    Alpha alpha;
    UserAlpha user;
    double cost{1e32};
    double fit{0.0};
    int iteration{0};
    int maxIteration{0};
};
