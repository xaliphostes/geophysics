#pragma once
#include <vector>
#include "Data.h"

struct CostFunctionParams
{
    const Serie &measure;
    const Serie &compute;
    double w{1.0};
    const Serie *weights{nullptr};
    void *others{nullptr};
};

using CostFunction = std::function<double(const CostFunctionParams &)>;

double calculateCost(const std::vector<std::shared_ptr<Data>> &data, const Alpha &alpha);
