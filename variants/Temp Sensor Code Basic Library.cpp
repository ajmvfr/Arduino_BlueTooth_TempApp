// #include <Arduino.h>
// #include <SoftwareSerial.h>
// #include <DHT.h>

// const byte rxPin = 9;
// const byte txPin = 8;
// const byte DHT11_PIN = 7;

// SoftwareSerial BTSerial(rxPin, txPin); // RX TX
// DHT dht;

// void setup() {
//   // define pin modes for tx, rx:
//   pinMode(rxPin, INPUT);
//   pinMode(txPin, OUTPUT);

//   dht.setup(DHT11_PIN); // data pin 2

//   BTSerial.begin(115200);
//   Serial.begin(9600);
//   Serial.println(F(__FILE__ " " __DATE__ " " __TIME__));
// }

// void loop() {

//   int sample = dht.getMinimumSamplingPeriod();

//   float humidity = dht.getHumidity();
//   float temperature = dht.getTemperature();

//   Serial.print(sample);
//   Serial.print("\t");
//   Serial.print(dht.getStatusString());
//   Serial.print("\t");
//   Serial.print(humidity, 1);
//   Serial.print("\t\t");
//   Serial.print(temperature, 1);
//   Serial.print("\t\t");
//   Serial.println(dht.toFahrenheit(temperature), 1);

//   delay(1500);

// }

