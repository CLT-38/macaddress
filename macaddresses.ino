#include <WiFi.h>
#include <BLEDevice.h>

bool printed = false;

void setup() {
  Serial.begin(9600);

  // Initialiser BLE (pour la MAC Bluetooth)
  BLEDevice::init("");

  // Initialiser le Wi-Fi (obligatoire pour charger les MAC)
  WiFi.mode(WIFI_STA);   // active la pile WiFi
  delay(100);            // petit délai pour laisser le WiFi charger la MAC
}

void loop() {
  delay(3000);  // attente pour que serial soit prêt
  if (!printed) {
    // Wi-Fi STA
    Serial.print("MAC WiFi STA : ");
    Serial.println(WiFi.macAddress());

    // Wi-Fi AP
    Serial.print("MAC WiFi AP  : ");
    Serial.println(WiFi.softAPmacAddress());

    // Bluetooth
    BLEAddress addr = BLEDevice::getAddress();
    const uint8_t* bt = addr.getNative();
    Serial.printf("MAC Bluetooth: %02X:%02X:%02X:%02X:%02X:%02X\n",
                  bt[0], bt[1], bt[2], bt[3], bt[4], bt[5]);

    printed = true;
  }
}
