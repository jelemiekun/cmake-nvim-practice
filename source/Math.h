#pragma once 
#include <spdlog/spdlog.h>
#include <vector>

namespace Math {
  void init();
  float calculateCGPA(const std::vector<float>& grades);
}

