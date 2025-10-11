#include "Math.h"
#include <spdlog/spdlog.h>

float Math::add(const float &numOne, const float &numTwo) {
  spdlog::info("[MATH::add]: Adding {} and {}...", numOne, numTwo);
  return numOne + numTwo;
}
