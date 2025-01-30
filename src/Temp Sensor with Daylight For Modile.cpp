#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DHT.h>

const byte rxPin = 9;
const byte txPin = 8;
const byte DHT11_PIN = 7;
const int ldr_pin = 4;

SoftwareSerial BTSerial(rxPin, txPin); // RX TX
DHT dht;
unsigned int TempDelay;

void sendBtString(float humidity, float temperature, String dhtStatus, int lightSensorState);

void setup() {
  // define pin modes for tx, rx:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(ldr_pin,INPUT);

  dht.setup(DHT11_PIN); // data pin 2

  BTSerial.begin(115200);
  Serial.begin(9600);
  Serial.println(F(__FILE__ " " __DATE__ " " __TIME__));
  TempDelay = dht.getMinimumSamplingPeriod();
}

void loop() {
  
  static int lightSensorState = 0; 
  static float humidity;
  static float temperature;
  static String dhtStatus;


  lightSensorState = digitalRead(ldr_pin);
  humidity = dht.getHumidity();
  temperature = dht.getTemperature();
  dhtStatus = dht.getStatusString();

  sendBtString(humidity, temperature, dhtStatus, lightSensorState);

}

void sendBtString(float humidity, float temperature, String dhtStatus, int lightSensorState){
    static unsigned long lastRun = millis();
    String tempString;    


    if ((millis() - lastRun) > TempDelay) {
        lastRun = millis();
        if (dhtStatus == "OK"){
            tempString = "?" + String(dht.toFahrenheit(temperature),0) + "|" + String(humidity,0) + "|" + String(lightSensorState) + ";";
            Serial.println(tempString);
            BTSerial.println(tempString);
        }
    }
}