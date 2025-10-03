#include <iostream>
#include <spdlog/spdlog.h>
#include "Math.h"

int main (int argc, char *argv[]) {
  spdlog::info("Starting program...");

  Math::init();

  return 0;
}
