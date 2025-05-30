#include "display.h"
#include <WiFi.h>

void runWiFiScan() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tr);
  u8g2.drawStr(0, 12, "Scanning WiFi...");
  u8g2.sendBuffer();

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  int n = WiFi.scanNetworks();
  u8g2.clearBuffer();
  for (int i = 0; i < n && i < 5; i++) {
    u8g2.drawStr(0, 12 + i * 12, WiFi.SSID(i).c_str());
  }
  u8g2.sendBuffer();
}