#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DHT.h>

const byte rxPin = 9;
const byte txPin = 8;
const byte DHT11_PIN = 7;

SoftwareSerial BTSerial(rxPin, txPin); // RX TX
DHT dht;
unsigned int TempDelay;

void readTemp();

void setup() {
  // define pin modes for tx, rx:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  dht.setup(DHT11_PIN); // data pin 2

  BTSerial.begin(115200);
  Serial.begin(9600);
  Serial.println(F(__FILE__ " " __DATE__ " " __TIME__));
  TempDelay = dht.getMinimumSamplingPeriod();
}

void loop() {

  readTemp();

}

void readTemp(){
    static unsigned long lastRun = millis();
    String tempString;    
    float humidity = dht.getHumidity();
    float temperature = dht.getTemperature();
    String dhtStatus = dht.getStatusString();

    if ((millis() - lastRun) > TempDelay) {
        lastRun = millis();
        if (dhtStatus == "OK"){
            tempString = "?" + String(dht.toFahrenheit(temperature),0) + "|" + String(humidity,0) + ";";
            // tempString = "" + String(humidity,0) + ";" + String(temperature,0) + ";" + String(dht.toFahrenheit(temperature),0) + ";";
            Serial.println(tempString);
            BTSerial.println(tempString);
        }
    }
}