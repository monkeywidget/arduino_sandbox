int sensorPins[5] = {A0, A1, A2, A3, A4};    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
char buffer[20];

void setup() {
  for (int i = 0; i<5; i++) {
    pinMode(sensorPins[i], INPUT);
  }
  Serial.begin(9600);
}

void loop() {

  Serial.println("Reading sensors S");
  
  // read the value from the sensor:
  for (int i = 0; i<5; i++) {
    sensorValue = analogRead(sensorPins[i]);
    sprintf(buffer, "Sensor %d: %d\n", i, sensorValue );
    Serial.println(buffer) ;
  }
  delay(1000);        // delay in between reads = 1s
}
