#pragma once
#include "types.h"

using Mapping = std::function<Alpha(const UserAlpha &)>;

Alpha defaultMapping(const UserAlpha &userAlpha);
