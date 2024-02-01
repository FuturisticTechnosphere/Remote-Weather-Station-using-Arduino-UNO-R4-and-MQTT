/*
  Smart Weather Station with Arduino, DHT11 Sensor, and LCD Display
  
  Authors: Salvatore Zuccaro and Luigi Emiliano Basso
  Date: 31/01/2024
  Description:
  This Arduino program transforms the device into a Smart Weather Station by utilizing a DHT11 sensor for measuring humidity and temperature.
  The real-time readings are displayed on a 16x2 LCD screen. The system includes an alert feature that changes the display color to red and activates an external LED when the temperature surpasses a predefined threshold.

  Hardware:
  - DHT11 sensor connected to digital pin 7
  - 16x2 LCD screen connected to the following pins:
    - RS: 12, EN: 11, D4: 5, D5: 4, D6: 10, D7: 9
  - External LED connected to digital pin 8

  Libraries:
  - LiquidCrystal.h for LCD interfacing
  - DHT.h for DHT sensor communication
  - WiFiS3.h for WiFi connectivity
  - ArduinoMqttClient.h for MQTT messaging
  - Arduino_JSON.h for JSON data formatting

  Connectivity:
  - WiFi communication using the IEEE802.11 protocol
  - MQTT messaging protocol for data transmission

  Note: Ensure that the required libraries are installed in the Arduino IDE.

  License: MIT License

  References:
  - DHT sensor library: https://github.com/adafruit/DHT-sensor-library
  - LiquidCrystal library: https://www.arduino.cc/en/Reference/LiquidCrystal
  - WiFiS3 library: https://github.com/arduino/ArduinoCore-renesas/tree/main/libraries/WiFiS3/examples
  - ArduinoMqttClient library: https://github.com/arduino-libraries/ArduinoMqttClient
  - Arduino_JSON library: https://github.com/arduino-libraries/Arduino_JSON
*/

#include <LiquidCrystal.h>                                  
#include <DHT.h>
#include <WiFiS3.h>
#include <ArduinoMqttClient.h>
#include <Arduino_JSON.h>


#define DHTPIN 7          // DHT11 sensor connected to pin 7                                 
#define DHTTYPE DHT11     
#define PIN_LED 8         // LED connected to pin 8                                  
#define HighTemp 30       // Predefined Treshold temperature set to 30 degrees
#define CLOCK 2           // Clock connected to pin 2
#define DATA 3            // Data connected to pin 3

const char* ssid = "";         // Enter your SSID    
const char* password = "";     // Enter your WiFi Password
const char* mqtt_broker = "";  // Specify the MQTT broker you are using
int mqtt_port = 1883;          
char topic[50];                 

DHT dht(DHTPIN, DHTTYPE);                                      // Create a DHT object
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 10, d7 = 9;   // Create a LiquidCrystal object
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                     // Define the LCD pin connections
float hr, temp;                                                // Variables to store humidity and temperature readings

int interval = 1000;                          // Initial update interval (1 second)
int encoderPos = 0;                           // Initial position of the encoder
volatile boolean StateA;                      // State of the encoder pin A (Clock)
volatile boolean StateB;                      // State of the encoder pin B (Data)
volatile boolean RotationDetected = false;    // Flag to detect encoder rotation

IPAddress localIP;
WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

void initWiFi() {                              
  WiFi.begin(ssid, password);                 // Connect the Board to WiFi
  Serial.print("\nConnecting to WiFi ..");     
  while (WiFi.status() != WL_CONNECTED) {      
    Serial.print('.');
    delay(1000);
  }
  Serial.print("\nYou're connected to ");
  Serial.println(WiFi.SSID());
  IPAddress localIP = WiFi.localIP();         // Assign the Board local IP to the localIP variable
  Serial.print("IP:");
  Serial.println(localIP);  
}

// Function to display temperature and humidity on the LCD
void ShowValue(float T, float H) {
  T = dht.readTemperature();             // Read temperature
  H = dht.readHumidity();                // Read humidity
  if (T >= HighTemp - 1) {               // Verify if the recorded temperature is higher than the treshold value - 1 (hysteresis)
    // Display the warning message on the LCD display
    lcd.setCursor(0, 0);
    lcd.print(F("High Temperature"));
    lcd.setCursor(0, 1);
    lcd.print(F("reached"));
    // Blink the Led until the if statement is true
    digitalWrite(PIN_LED, HIGH);  
    delay(1000);                  
    digitalWrite(PIN_LED, LOW); 
    delay(1000);                
  }else{
    lcd.setCursor(0, 0);
    lcd.print(F("T:"));
    lcd.print(T);                // Print temperature on the LCD screen
    lcd.write(223);              // Degree symbol
    lcd.print(F("C"));
    lcd.setCursor(0, 1);
    lcd.print(F("HR:"));         // Print relative humidity on the LCD screen
    lcd.print(H);
    lcd.print(F("%"));
  }
}
// Interrupt service routine for encoder rotation
void EncoderRotated(){ 
  StateB = digitalRead(DATA);  // Read the state of pin B
  RotationDetected = true;     // Set the rotation detection flag
}

void setup() {
  pinMode(PIN_LED, OUTPUT);                                                 
  pinMode(CLOCK, INPUT);                                                    // Set the CLOCK pin as input for the encoder
  pinMode(DATA, INPUT);                                                     // Set the DATA pin as input for the encoder
  attachInterrupt(digitalPinToInterrupt(CLOCK), EncoderRotated, CHANGE);    // Attach ISR to the CLOCK transition
  Serial.begin(9600);                                                       // Initialize the serial monitor
  dht.begin();                                                              // Initialize DHT
  lcd.begin(16, 2);                                                         // Initialize LCD
  lcd.setCursor(0, 0);
  lcd.print(F("Humidity detect"));
  lcd.setCursor(0, 1);
  lcd.print(F("and Temperature"));
  delay(10000);
  lcd.clear();
  initWiFi();                                                               // Calls "initWiFiW function in void setup
  Serial.println("Broker connecting");
  if (!mqttClient.connect(mqtt_broker, mqtt_port)) {                        // Connect to the MQTT broker, and verify if the connection happened
    Serial.print("MQTT connection failed! Error code = ");                  // Display the error code on the serial monitor, connecction did not occur
    Serial.println(mqttClient.connectError());
  }
  else{
  Serial.println("You're connected to the MQTT broker!");                   // Connection occurred 
  Serial.println();
  }
}
void loop() {
  int encoderReading = digitalRead(CLOCK);            // Read the current state of the CLOCK pin
  if (RotationDetected && encoderReading == 1)        // Verify that the rotation happened and make sure it occurs at once         
  {
    delay(1);                           
    StateA = digitalRead(CLOCK);                      // Read the current state of the CLOCK pin
    if (StateA != StateB)                             
    {
      ++encoderPos;                                   // Increment encoder position if the direction is positive
    }
    else
    {
      --encoderPos;                                   // Decrement encoder position if the direction is negative
    }
    RotationDetected = false;                         // Reset the rotation detection flag
    encoderPos = constrain(encoderPos, 1, 60);        // Limit encoder position between 1 and 60
    interval = encoderPos * 1000;                     // Update the interval based on encoder position
    Serial.print("Interval set to ");
    Serial.print(encoderPos);
    Serial.println(" seconds");
  }
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();             
  if (currentMillis - previousMillis >= interval) {   
    previousMillis = currentMillis;                   // New measuring interval set
    String ipaddress = WiFi.localIP().toString();     // Turn the IP address into a string
    String topicstring = "/" + ipaddress + "/env";    // Form a dinamic mqtt topic 
    strcpy(topic, topicstring.c_str());
    JSONVar doc;
    // Make one single JSON message which contains both Temperature and humidity
    doc["Temperature"]  = dht.readTemperature();
    doc["Humidity"] = dht.readHumidity();      
    String jsonString1 = JSON.stringify(doc);
    // Subscribe to the selected topic and publish sensor data
    mqttClient.subscribe(topic);
    mqttClient.beginMessage(topic);
    mqttClient.print(jsonString1);
    mqttClient.endMessage();
  }
  ShowValue(temp, hr);
}
