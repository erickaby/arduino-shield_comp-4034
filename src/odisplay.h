#ifndef ODISPLAY_H
#define ODISPLAY_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH  128 // OLED display width, in pixels.
#define SCREEN_HEIGHT 32  // OLED display height, in pixels.  

#define OLED_RESET  4 // Reset Pin # or (-1 if sharing arduino reset pin)

class ODisplay
{
  private:
    /* Here will be the instance stored. */
    static ODisplay* _instance;

    /* Private constructor to prevent instancing. */
    ODisplay();

    int _health;

    int _ammo;

  public:
    /* Static access method */
    static ODisplay* getInstance();

    void refresh();

    void updateHealth(int newHealth);

    void updateAmmo(int newAmmo);

};

#endif // DISPLAY_H