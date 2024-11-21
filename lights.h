#ifndef _LIGHTS_H_
#define _LIGHTS_H_

#include <Adafruit_NeoPixel.h>

/**
 * A representation of a color structure
 */
typedef struct {
  //! Red
  int r;

  //! Green
  int g;

  //! Blue
  int b;
} Color;

/**
 * @brief Lights Module
 */
class LightsModule {
  private:

  //! The Neopixel led strip
  Adafruit_NeoPixel neopixel_strip_;
  
  //! The selected program the loop is set to use.
  void (*program_)(LightsModule*);
  
  /**
  * @brief Convert a color from RGB to NEOPIXEL
  * @param color - The color to convert
  * @return The converted color
  */
  uint32_t ConvertColor_(Color color);
  
  public:
  /**
  * @brief Initialize the Lights Module
  * @param neopixel_pin - The neopixel data pin
  * @param neopixel_count - The neopixel led count
  */
  LightsModule(int neopixel_pin, int neopixel_count);

  /**
   * @brief Clears all of the neopixels
   */
  void Clear();

  /**
   * @brief The loop method of the lights module
   */
  void Loop();

  /**
   * @brief Set's the program the loop is going to run.
   * @param program - The neopixel program
   */
  void SetProgram(void (*program)());

  /**
   * @brief Set a specific neopixel led to the specified color
   * @param led - The led in question
   * @param color - The color to change the led to
   */
  void SetToColor(int led, uint32_t color);

  //! @copydoc SetToColor(int, uint32_t)
  void SetToColor(int led, Color color);

  /**
   * @brief Set all of the neopixel's leds to the specified color
   * @param color - The color to change the led to
   */
  void SetAllToColor(uint32_t color);

  //! @copydoc SetAllToColor(uint32_t)
  void SetAllToColor(Color color);
  
  /**
   * @brief Blink a specific led to a specific color
   * @param led - The led in question
   * @param color - The color to change to
   * @param duration - The blink duration
   */
  void BlinkToColor(int led, uint32_t color, int duration);

  //! @copydoc BlinkToColor(int, uint32_t, int)
  void BlinkToColor(int led, Color color, int duration);

  /**
   * @brief Blinks all of the neopixel's leds to the specific color. Will use first neopixel color as reset color.
   * @param color - The color to change the led to
   * @param duration - The blink duration
   */
  void BlinkAllToColor(uint32_t color, int duration);

  //! @copydoc BlinkAllToColor(uint32_t, int)
  void BlinkAllToColor(Color color, int duration);

  /**
   * @brief Color wipes of the neopixel's leds to the specific color
   * @param color - The color to change the led to
   * @param duration - The blink duration
   */
  void ColorWipeAll(uint32_t color, int duration);

  //! @copydoc ColorWipeAll(uint32_t, int)
  void ColorWipeAll(Color color, int duration);

  /**
   * @brief Chase effect on all of the neopixel's leds to the specific color
   * @param color - The color to change the led to
   * @param duration - The blink duration
   */
  void ChaseAll(uint32_t color, int duration);

  //! @copydoc ChaseAll(uint32_t, int)
  void ChaseAll(Color color, int duration);
};

#endif