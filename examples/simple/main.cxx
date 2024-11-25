#include <geophysics/Data.h>
#include <geophysics/inversion.h>
#include <geophysics/monteCarlo.h>

class MyData : public Data
{
public:
    double cost(const Alpha &alpha) const override
    {
        // Implement your cost calculation
        return 0.0;
    }
};

int main()
{
    InversionModel model;

    // Set up data
    auto data1 = std::make_shared<MyData>();
    model.data.push_back(data1);

    // Set up alpha parameters
    model.alpha.min = {0.0, 0.0, 0.0};
    model.alpha.max = {1.0, 1.0, 1.0};
    model.alpha.mapping = defaultMapping;

    // Run Monte Carlo
    auto result = monteCarlo(model, 10000);

    return 0;
}