#pragma once
#include <Arduino.h>
#include <U8g2lib.h>

extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;

void initDisplay();
void drawMenu(String items[], int length, int index);
