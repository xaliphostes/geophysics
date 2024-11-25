#pragma once
#include <vector>
#include <functional>
#include <string>
#include <memory>

class Serie;

using Alpha = std::vector<double>;
using UserAlpha = std::vector<double>;
using MessageCallback = std::function<void(const std::string &)>;
using ProgressCallback = std::function<void(int, double)>;
