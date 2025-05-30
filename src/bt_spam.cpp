#include "display.h"
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

BLEServer* pServer = nullptr;

void runBTSpam() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tr);
  u8g2.drawStr(0, 12, "Spamming BT...");
  u8g2.sendBuffer();

  BLEDevice::init("ESP32_SPAMMER");
  pServer = BLEDevice::createServer();

  BLEAdvertising* pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->start();

  delay(10000); // Keep advertising for 10 seconds
  pAdvertising->stop();

  u8g2.clearBuffer();
  u8g2.drawStr(0, 12, "BT Spam Done.");
  u8g2.sendBuffer();
}