#include "lights.h"

LightsModule::LightsModule(int neopixel_pin, int neopixel_count)
    : neopixel_strip_{neopixel_count, neopixel_pin, NEO_GRB + NEO_KHZ800},
      program_{nullptr} {
  this->neopixel_strip_.begin();
  this->neopixel_strip_.show();
}

uint32_t LightsModule::ConvertColor_(Color color) {
  return this->neopixel_strip_.Color(color.r, color.g, color.b);
}

void LightsModule::Clear() {
  this->neopixel_strip_.clear();
  this->neopixel_strip_.show();
}

void LightsModule::Loop() {
  this->Clear();

  if (this->program_ != nullptr) this->program_(this);
}

void LightsModule::SetProgram(void (*program)()) {
  this->program_ = program;
}

void LightsModule::SetToColor(int led, uint32_t color) {
  this->neopixel_strip_.setPixelColor(led, color);
  this->neopixel_strip_.show();
}

void LightsModule::SetToColor(int led, Color color) {
  this->SetToColor(led, this->ConvertColor_(color));
}

void LightsModule::SetAllToColor(uint32_t color) {
  for (int i = 0; i < this->neopixel_strip_.numPixels(); ++i) {
    this->neopixel_strip_.setPixelColor(i, color);
  }

  this->neopixel_strip_.show();
}

void LightsModule::SetAllToColor(Color color) {
  this->SetAllToColor(this->ConvertColor_(color));
}

void LightsModule::BlinkToColor(int led, uint32_t color, int duration) {
  uint32_t tmp = this->neopixel_strip_.getPixelColor(led);

  this->SetToColor(led, color);
  delay(duration);
  this->SetToColor(led, tmp);
}

void LightsModule::BlinkToColor(int led, Color color, int duration) {
  this->BlinkToColor(led, this->ConvertColor_(color), duration);
}

void LightsModule::BlinkAllToColor(uint32_t color, int duration) {
  uint32_t tmp = this->neopixel_strip_.getPixelColor(0);

  this->SetAllToColor(color);
  delay(duration);
  this->SetAllToColor(tmp);
}

void LightsModule::BlinkAllToColor(Color color, int duration) {
  this->BlinkAllToColor(this->ConvertColor_(color), duration);
}

void LightsModule::ColorWipeAll(uint32_t color, int duration) {
  for (int i = 0; i < this->neopixel_strip_.numPixels(); ++i) {
    this->SetToColor(i, color);
    delay(duration);
  }
}

void LightsModule::ColorWipeAll(Color color, int duration) {
  this->ColorWipeAll(this->ConvertColor_(color), duration);
}

void LightsModule::ChaseAll(uint32_t color, int duration) {
  for (int i = 0; i < 10; ++i) {
    for (int ii = 0; ii <= 2; ++ii) {
      this->neopixel_strip_.clear();

      for (int n = ii; n < this->neopixel_strip_.numPixels(); n += 2) {
        this->neopixel_strip_.setPixelColor(n, color);
      }

      this->neopixel_strip_.show();
      delay(duration);
    }
  }
}

void LightsModule::ChaseAll(Color color, int duration) {
  this->ChaseAll(this->ConvertColor_(color), duration);
}