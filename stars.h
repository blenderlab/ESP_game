#define NBSTARS 20

class star {
  public:
    int x;
    int y;
    byte s;
    void draw() {
      tft.fillRect((x+s), y,2,2,TFT_BLACK );
      tft.fillRect(x, y, 2,2,TFT_WHITE/((4-s)*2));
    }
    void move() {
      x = x - s;
      if (x < -5) {
        x = SCREEN_WIDTH+5;
        y = int(random(SCREEN_HEIGHT));
        s = int(random(3)) + 1;
      }
    }
};

class _starfield {
  public:
    star stars[NBSTARS];

    void init() {
      for (int i = 0; i < NBSTARS; i++) {
        stars[i].x = random(SCREEN_WIDTH);
        stars[i].y = random(SCREEN_HEIGHT);
        stars[i].s = random(3) + 1;
        stars[i].draw();
      }
    }
    void update() {
      for (int i = 0; i < NBSTARS; i++) {
        stars[i].move();
      }
    }
    void draw() {
      update();
      for (int i = 0; i < NBSTARS; i++) {
        stars[i].draw();
      }
      tft.fillRect(0,0,3,128,TFT_BLACK);
  
    }
};
