//your starship
#define SELF 0
#define ENNEMY 1

const int shipImgW = 16;
const int shipImgH = 14;
char shipImg[] = "ZZZZZZZZZZZZZZZZZZWWWWWWWWRRZZZZZZZZWWWZZZZZZZZZZZZZZWWWBWWRZZZZZZZZZWWWWBZZZZZZZRRRWWWWRRWWWWZZZZRYWWWWYYRRWWWWZRRRWWWWRRWWWWZZZZZZZWWWWRZZZZZZZZZZZWWWBWWRZZZZZZZZWWWZZZZZZZZZZZWWWWWWWWRRZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
const int alienImgW = 14;
const int alienImgH = 11;
char alienImg[] ="GGGZZZZZZZZGGGZZZGZZZZZZGZZZZZGGGGGGGGGGZZZGGGGGGGGGGGGZGGGZGGGGGGZGGGGGGZZGGGGZZGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGZZZGGZZGGZZZGZGGZGGZZGGZGGZZZZZZGZZGZZZZZ";
class _ship {
  public :
    TFT_eSprite sp_ship = TFT_eSprite(&tft);
    byte type = SELF;
    byte scale = 2;
    int shipX = 4;
    int shipY = 60;
    int speedY = 0;
    int speedX = 0;

    _ship(byte t) {
      type=t;
      sp_ship.setColorDepth(4);
      sp_ship.createSprite(16 * scale, 14 * scale);
      switch (type) {
        case 0 :
          generate_sprite(&sp_ship, shipImg, shipImgW, shipImgH, 0, 0, scale);
          break;
        case  1:
          generate_sprite(&sp_ship, alienImg, alienImgW, alienImgH, 0, 0, scale);
          break;
      }
    }

    void update() {
      if (shipY >= SCREEN_HEIGHT - shipImgH*scale) {
        shipY = SCREEN_HEIGHT - shipImgH*scale;
      } else {
        shipY += speedY;
      }
      if (shipY <= 1) {
        shipY = 1;
      } else {
        shipY += speedY;
      }
      if (shipX <= -30*scale ) {
        shipX = SCREEN_WIDTH + int(random(180));
        shipY =  int(random(SCREEN_HEIGHT));
        speedX=random(1,4);
      } else {
        shipX -= speedX;
      }
      
    }
    void draw() {
      tft.fillRect(shipX+speedX , shipY-3, (shipImgW) * scale, (shipImgH+3) * scale , TFT_BLACK);
      sp_ship.pushSprite(shipX, shipY);
    }


};
