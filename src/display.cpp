#include "display.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void initDisplay() {
  u8g2.begin();
}

void drawMenu(String items[], int length, int index) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tr);
  for (int i = 0; i < length; i++) {
    String line = (i == index ? ">" : " ") + items[i];
    u8g2.drawStr(0, 12 + i * 12, line.c_str());
  }
  u8g2.sendBuffer();
}