#include "Math.h"
#include <spdlog/spdlog.h>

float Math::add(const float& firstNumber, const float& secondNumber) {
  spdlog::info("[MATH::add]: Adding {} and {}...", firstNumber, secondNumber);

  float sum = firstNumber + secondNumber;

  spdlog::info("[MATH::add]: Sum: {}", sum);

  return sum;
}
