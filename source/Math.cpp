#include "Math.h"

void Math::init() {
  spdlog::info("[CGPA]: Initiating...");

  float cgpa = 0.0f;

  std::vector<float> grades;
  grades.push_back(75.0f);
  grades.push_back(89.5f);
  grades.push_back(95.5f);
  grades.push_back(96.25f);
  grades.push_back(95.0f);

  cgpa = Math::calculateCGPA(grades);

  spdlog::info("[CGPA] Result: {}", cgpa);
}

float Math::calculateCGPA(const std::vector<float>& grades) {
  spdlog::info("[CGPA]: Calculating Grade Summation...");

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
