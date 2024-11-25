#include <geophysics/monteCarlo.h>
#include <geophysics/cost.h>
#include <random>


InversionResult monteCarlo(const InversionModel &params, int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    auto genRandom = [&gen](double min, double max) -> double
    {
        std::uniform_real_distribution<> dis(min, max);
        return dis(gen);
    };

    if (params.alpha.min.size() != params.alpha.max.size())
    {
        throw std::runtime_error("Alpha min and max dimensions mismatch");
    }

    std::vector<std::pair<double, double>> limits;
    for (size_t i = 0; i < params.alpha.min.size(); ++i)
    {
        limits.emplace_back(params.alpha.min[i], params.alpha.max[i]);
    }

    InversionResult solution;
    solution.maxIteration = n;

    const int mod = static_cast<int>((n / 100.0) * 5); // 5%

    for (int i = 0; i < n; ++i)
    {
        // Generate user parameters
        UserAlpha userParams;
        for (const auto &limit : limits)
        {
            userParams.push_back(genRandom(limit.first, limit.second));
        }

        // Map to alpha parameters
        Alpha alpha = params.alpha.mapping(userParams);

        // Calculate cost
        double currentCost = calculateCost(params.data, alpha);

        if (currentCost < solution.cost)
        {
            solution.cost = currentCost;
            solution.fit = std::round((1.0 - currentCost) * 10000.0) / 100.0;
            solution.alpha = alpha;
            solution.user = userParams;
            solution.iteration = i;

            if (params.onMessage)
            {
                params.onMessage("\niteration: " + std::to_string(solution.iteration));
                params.onMessage("cost     : " + std::to_string(solution.cost));
                params.onMessage("fit      : " + std::to_string(solution.fit));
                params.onMessage("mean misfit angle : " + std::to_string(solution.cost * 90));
                params.onMessage("user-alpha:");
                for (const auto &v : userParams)
                {
                    params.onMessage("  " + std::to_string(v));
                }
            }
        }

        if (i % mod == 0 && params.onProgress)
        {
            params.onProgress(i, (i * 100.0) / n);
        }
    }

    return solution;
}
