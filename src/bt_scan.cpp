#include "display.h"
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>

BLEScan* pBLEScan;

void runBTScan() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tr);
  u8g2.drawStr(0, 12, "Scanning BT...");
  u8g2.sendBuffer();

  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();
  pBLEScan->setActiveScan(true);
  BLEScanResults foundDevices = pBLEScan->start(5);

  u8g2.clearBuffer();
  for (int i = 0; i < foundDevices.getCount() && i < 5; i++) {
    BLEAdvertisedDevice device = foundDevices.getDevice(i);
    u8g2.drawStr(0, 12 + i * 12, device.getName().c_str());
  }
  u8g2.sendBuffer();
}