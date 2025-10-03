#include <iostream>
#include <spdlog/spdlog.h>
#include "Math.h"

int main (int argc, char *argv[]) {
  spdlog::info("Starting program...");

  float cgpa = 0.0f;

  std::vector<float> grades;
  grades.push_back(75.0f);
  grades.push_back(89.5f);
  grades.push_back(95.5f);
  grades.push_back(96.25f);
  grades.push_back(95.0f);

  cgpa = Math::calculateCGPA(grades);

  spdlog::info("CGPA result: {}", cgpa);

  return 0;
}
