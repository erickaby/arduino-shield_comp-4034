#include "odisplay.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

ODisplay* ODisplay::_instance = 0;

ODisplay* ODisplay::getInstance()
{
  if (_instance == 0) {
    _instance = new ODisplay();
  }
  return _instance;
}

ODisplay::ODisplay() : _health{100}, _ammo{10}
{
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3c for 128x32
    Serial.println(F("SSD1036 allocation failed"));
    while(1); // Don't proceed, loop forever.
  }
  refresh();
}

void ODisplay::refresh() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print(F("AMMO"));
  display.setCursor(65, 0);
  display.print(F("HEALTH"));

  display.setTextSize(2);
  display.setCursor(0, 12);
  display.print(_ammo);
  display.setCursor(65, 12);
  display.print(_health);
  

  display.display();
}

void ODisplay::updateHealth(int newHealth) {
  _health = newHealth;
  refresh();
}

void ODisplay::updateAmmo(int newAmmo) {
  _ammo = newAmmo;
  refresh();
}

