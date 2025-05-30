#include "display.h"

void setup() {
  initDisplay();
  String menu[] = {"WiFi Scan", "Deauth", "BT Scan", "BT Spam"};
  drawMenu(menu, 4, 0);
}

void loop() {
  // Future: add button handling to select actions
}