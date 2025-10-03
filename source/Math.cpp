#include "Math.h"

float Math::calculateCGPA(const std::vector<float>& grades) {
  spdlog::info("[CGPA]: Initiating...");

  int counter = 0;
  float sum = 0.0f;
  float average = 0.0f;

  for (const auto& grade : grades) {
    sum += grade;
    counter++;
    spdlog::info("[CGPA]: Iterate count: {}", counter);
  }

  spdlog::info("[CGPA]: Calculating average...");
  average = sum / counter;
  spdlog::info("[CGPA]: Averagae calculated successfully.");

  return average;
}
