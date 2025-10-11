#include "Math.h"
#include <spdlog/spdlog.h>

int main(int argc, char *argv[]) {
  spdlog::info("[MAIN]: Initiating program...");
  float num = Math::add(10.5f, 5.5f);
  return 0;
}
