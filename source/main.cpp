#include <iostream>
#include <spdlog/spdlog.h>
#include "Math.h"

int main (int argc, char *argv[]) {
  spdlog::info("Starting program...");

  Math::add(10, 5);

  spdlog::info("Closing program...");
  return 0;
}
