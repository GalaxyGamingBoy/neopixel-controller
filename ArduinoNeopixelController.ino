#define NEOPIXEL_PIN 6
#define NEOPIXEL_COUNT 16

#include "lights.h"

LightsModule* lights = nullptr;

void MainProgram(LightsModule* controller) {
  controller->ColorWipeAll(Color{255, 127, 72}, 100);
  controller->SetAllToColor(Color{255, 255, 255});
  
  for (int i = 0; i < 3; ++i) controller->ChaseAll(Color{0, 0, 255}, 100);

  controller->ColorWipeAll(Color{255, 0, 0}, 50);
}

void setup() {
  lights = new LightsModule{NEOPIXEL_PIN, NEOPIXEL_COUNT};

  lights->SetProgram(MainProgram);
}

void loop() {
  lights->Loop();
}