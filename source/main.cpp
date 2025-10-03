#include <iostream>
#include <spdlog/spdlog.h>

float calculateCGPA(const std::vector<float>& grades) {
  spdlog::info("[CGPA]:Calculating CGPA...");
  float average = 0.0f;
  float sum = 0.0f;
  int counter = 0;

  for (const float& grade : grades) {
    sum += grade;
    counter++;
    spdlog::info("[CGPA]: Iteration: {}", counter);
  }

  spdlog::info("[CGPA]: Calculating average...");
  average = sum / counter;

  return average;
}

int main (int argc, char *argv[]) {
  spdlog::info("Starting program...");

  float cgpa = 0.0f;

  std::vector<float> grades;
  grades.push_back(75.0f);

  cgpa = calculateCGPA(grades);

  spdlog::info("CGPA result: {}", cgpa);

  return 0;
}
