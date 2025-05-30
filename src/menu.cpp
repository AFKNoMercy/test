#include <Arduino.h>
#include "display.h"
#include "wifi_scan.h"
#include "wifi_attack.h"
#include "bt_scan.h"
#include "bt_spam.h"
#include "menu.h"

int menuIndex = 0;
String menuItems[] = {"WiFi Scan", "WiFi Attack", "BT Scan", "BT Spam"};
const int menuLength = sizeof(menuItems) / sizeof(menuItems[0]);

void showMainMenu() {
  drawMenu(menuItems, menuLength, menuIndex);
}

void handleMenuInput() {
  if (Serial.available()) {
    char key = Serial.read();
    if (key == '1') menuIndex = 0;
    else if (key == '2') menuIndex = 1;
    else if (key == '3') menuIndex = 2;
    else if (key == '4') menuIndex = 3;
    else return;

    drawMenu(menuItems, menuLength, menuIndex);
    delay(500);

    switch (menuIndex) {
      case 0: runWiFiScan(); break;
      case 1: runWiFiAttack(); break;
      case 2: runBTScan(); break;
      case 3: runBTSpam(); break;
    }

    delay(2000);
    drawMenu(menuItems, menuLength, menuIndex);
  }
}