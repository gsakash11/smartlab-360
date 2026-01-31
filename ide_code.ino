#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
// LED pins
#define LED1 26
#define LED2 27
void setup() {
  Serial.begin(115200);
  // Initialize Bluetooth
  SerialBT.begin("RoboLab_BT"); // Bluetooth device name
  Serial.println("Bluetooth Started. Ready to pair.");
  // Set LED pins as OUTPUT
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  // Turn OFF LEDs initially
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}
void loop() {
  if (SerialBT.available()) {
    String command = SerialBT.readStringUntil('\n');
    command.trim(); // Remove extra spaces
    Serial.println(command);
    // LED 1 control
    if (command == "L1_ON") {
      digitalWrite(LED1, HIGH);
    }
    else if (command == "L1_OFF") {
      digitalWrite(LED1, LOW);
    }
    // LED 2 control
    else if (command == "L2_ON") {
      digitalWrite(LED2, HIGH);
    }
    else if (command == "L2_OFF") {
      digitalWrite(LED2, LOW);
    }
  }
}
