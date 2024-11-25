#include <geophysics/cost.h>

double calculateCost(const std::vector<std::shared_ptr<Data>> &data, const Alpha &alpha)
{
    if (data.empty())
    {
        throw std::runtime_error("Empty data array");
    }

    double totalCost = 0.0;
    double totalWeight = 0.0;

    for (const auto &d : data)
    {
        totalCost += d->cost(alpha);
        totalWeight += d->weight;
    }

    return totalCost / totalWeight;
}