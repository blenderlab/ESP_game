

void generate_sprite(TFT_eSprite * sprite, char img[], int imgW, int imgH, int x, int y, int scale) {
  uint16_t cellColor;
  char curPix;
  // create a color map with known colors (16 maximum for 4 bit Sprite
  uint16_t cmap[16];
  cmap[0]  = TFT_BLACK; // We will keep this as black
  cmap[1]  = TFT_NAVY;
  cmap[2]  = TFT_DARKGREEN;
  cmap[3]  = TFT_DARKCYAN;
  cmap[4]  = TFT_MAROON;
  cmap[5]  = TFT_PURPLE;
  cmap[6]  = TFT_PINK;
  cmap[7]  = TFT_LIGHTGREY;
  cmap[8]  = TFT_YELLOW;
  cmap[9]  = TFT_BLUE;
  cmap[10] = TFT_GREEN;
  cmap[11] = TFT_CYAN;
  cmap[12] = TFT_RED;
  cmap[13] = TFT_MAGENTA;
  cmap[14] = TFT_WHITE;  // Keep as white for text
  cmap[15] = TFT_BLUE;   // Keep as blue for sprite border
  sprite->createPalette(cmap);

  for (int i = 0; i < imgW * imgH; i++) {
    curPix = img[i];
    if (curPix == 'W') {
      cellColor = 14;
    }
    else if (curPix == 'Y') {
      cellColor = 8;
    }
    else if (curPix == 'B') {
      cellColor = 1;
    }
    else if (curPix == 'R') {
      cellColor = 12;
    }
    else if (curPix == 'G') {
      cellColor = 10;
    }
    if (curPix != 'Z' and scale == 1) {
      sprite->drawPixel(x + i % imgW, y + i / imgW, cellColor);
    }
    else if (curPix != 'Z' and scale > 1) {
      sprite->fillRect(x + scale * (i % imgW), y + scale * (i / imgW), scale, scale, cellColor);
    }
  }
}
