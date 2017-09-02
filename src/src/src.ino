#include <dht.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

dht DHT11;

// Check flag for DHT11 sensor status
int check = 0;

#define DHT11_PIN 7 

void setup() {
  Serial.begin(9600);
  // Initialize display with I2C address 0x3D
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  
  // Clear the display buffer
  display.clearDisplay();

  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("ClimateBox!");
  display.display();
  delay(2000);

  display.setTextSize(1);
  display.println("Read sensor: ");

  // Check DHT11 sensor status
  switch(check) {
    case DHTLIB_OK:
      display.println("OK");
      break;
    case DHTLIB_ERROR_CHECKSUM:
      display.println("Checksum error");
      break;
    case DHTLIB_ERROR_TIMEOUT:
      display.println("Timeout error");
      break;
    default:
      display.println("Unknown error");
      break;
  }
  
  display.display();
  delay(3000);
  display.clearDisplay();
}

void loop() {
  display.setCursor(0,0);
  display.setTextSize(2);
  int chk = DHT11.read11(DHT11_PIN);
  display.println("Temp: ");
  display.println((float)DHT11.temperature);
  display.println("Humidity: ");
  display.println((float)DHT11.humidity);
  display.display();
  delay(10000);
  display.clearDisplay();
}
