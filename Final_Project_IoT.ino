#define BLYNK_TEMPLATE_ID "TMPL6soUJBnXJ"
#define BLYNK_TEMPLATE_NAME "iot project"
#define BLYNK_AUTH_TOKEN "qlkbrbO1hUxWyIBtERpSH3zEFXlbkIDz"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Define motion sensor pin
int motion_sensor = 32;
int motion_data = 0;

// Blynk credentials
const char* auth = BLYNK_AUTH_TOKEN;

// WiFi credentials
char ssid[] = "Goku";
char pass[] = "esp32@Wifi";

// Timer object for Blynk
BlynkTimer timer;

// Function to send sensor data to Blynk
void sendSensor() {
  motion_data = digitalRead(motion_sensor);
  Serial.println(motion_data);
  Blynk.virtualWrite(V0, motion_data);
}

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Configure motion sensor pin as input
  pinMode(motion_sensor, INPUT);

  // Connect to Blynk
  Blynk.begin(auth, ssid, pass);

  // Set a timer to call sendSensor() every 100 ms
  timer.setInterval(100L, sendSensor);
}

void loop() {
  // Run Blynk and timer
  Blynk.run();
  timer.run();
}
