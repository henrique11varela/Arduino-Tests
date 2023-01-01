#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int x = 63, y = 31;
bool xIncrement = true, yIncrement = true;
int r = 4;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS); //starts screen
  display.clearDisplay();
  display.display();
}

void loop() {
  if (x > SCREEN_WIDTH - r)
    xIncrement = false;
  else if (x < 0 + r)
    xIncrement = true;

  if (y > SCREEN_HEIGHT - r)
    yIncrement = false;
  else if (y < 0 + r)
    yIncrement = true;

  if (xIncrement)
    x++;
  else
    x--;

  if (yIncrement)
    y++;
  else
    y--;

  display.clearDisplay();
  display.drawCircle(x, y, r, WHITE);
  display.display();
}

//clears display buffer
//display.clearDisplay();
