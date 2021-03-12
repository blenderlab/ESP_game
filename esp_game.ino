
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

#define SCREEN_WIDTH 240 // OLED display width, in pixels
#define SCREEN_HEIGHT 135 // OLED display height, in pixels
#include "common.h"
#include "stars.h"
#include "ship.h"
#define BUTTON_R        22
#define BUTTON_L        21


_starfield starfield;
_ship ship(SELF);
_ship ennemies[5](ENNEMY);

void setup(void) {
  Serial.begin(9600);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(0, 0);
  button_init();
  starfield.init();
  for(int i=0;i<5;i++){
    ennemies[i].speedX=1*int(random(1,4));
    ennemies[i].shipX=180+int(random(200));
    ennemies[i].shipY=int(random(128));
  }
}
void shipr() {
  ship.speedY = 1;
}
void shipl() {
    ship.speedY = -1;

}
void ships() {
  ship.speedY = 0;
}


void button_init()
{
  pinMode(BUTTON_R, INPUT_PULLDOWN);
  attachInterrupt(BUTTON_R, shipl, RISING);
  pinMode(BUTTON_L, INPUT_PULLDOWN);
  attachInterrupt(BUTTON_L, shipr, RISING);

}

void loop() {
  
  starfield.draw();
  for(int i=0;i<5;i++){
    ennemies[i].update();
    ennemies[i].draw();
    
  }
  ship.update();
  ship.draw();
  delay(20);
}
