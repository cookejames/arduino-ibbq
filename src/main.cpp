#include <Arduino.h>
#include "NimBLEDevice.h"

void setup()
{
  Serial.begin(115200);

  NimBLEDevice::init("");

  Serial.println("Scanning");
  NimBLEScan *pScan = NimBLEDevice::getScan();
  pScan->setActiveScan(true);
  NimBLEScanResults results = pScan->start(10);
  Serial.println("Scanning complete");
  // NimBLEUUID serviceUuid("ABCD");

  for (int i = 0; i < results.getCount(); i++)
  {
    NimBLEAdvertisedDevice device = results.getDevice(i);
    Serial.println(i);
    Serial.println(device.toString().c_str());
    // Serial.println(device.getPayload());
    Serial.println(device.getName().c_str());

    // if (device.isAdvertisingService(serviceUuid))
    // {
    //   // create a client and connect
    // }
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
}