#include <dht.h>

dht DHT11;
int check = 0;

#define DHT11_PIN 7 
void setup() {
  Serial.begin(9600);
  Serial.println("Read sensor: ");
  switch(check) {
    case DHTLIB_OK:
      Serial.println("OK");
      break;
    case DHTLIB_ERROR_CHECKSUM:
      Serial.println("Checksum error");
      break;
    case DHTLIB_ERROR_TIMEOUT:
      Serial.println("Timeout error");
      break;
    default:
      Serial.println("Unknown error");
      break;
  }
}

void loop() {
  int chk = DHT11.read11(DHT11_PIN);
  Serial.println("Measurements: ");
  Serial.print("Temperature: ");
  Serial.println((float)DHT11.temperature);
  Serial.print("Humidity: ");
  Serial.println((float)DHT11.humidity);
  delay(5000);
}
