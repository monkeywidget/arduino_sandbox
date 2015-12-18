int sensorPins[5] = {A0, A1, A2, A3, A4};    // select the input pin for the potentiometer
//int sensorValue = 0;  // variable to store the value coming from the sensor
char buffer[50];

int sensorValueA0 = 0;  // variable to store A0
int sensorValueA1 = 0;  // variable to store A1
int sensorValueA2 = 0;  // variable to store A2
int sensorValueA3 = 0;  // variable to store A3
int sensorValueA4 = 0;  // variable to store A4


void setup() {
  for (int i = 0; i<5; i++) {
    pinMode(sensorPins[i], INPUT);
  }
  Serial.begin(9600);
}

void loop() {

  // read the value from the sensors:
  sensorValueA0 = analogRead(sensorPins[0]);
  sensorValueA1 = analogRead(sensorPins[1]);
  sensorValueA2 = analogRead(sensorPins[2]);
  sensorValueA3 = analogRead(sensorPins[3]);
  sensorValueA4 = analogRead(sensorPins[4]);

  sprintf(buffer, "[%d %d %d %d %d]", 
                  sensorValueA0, sensorValueA1, 
                  sensorValueA2, sensorValueA3, sensorValueA4 );
  Serial.println(buffer) ;

  /* for (int i = 0; i<5; i++) {
    sensorValue = analogRead(sensorPins[i]);
    sprintf(buffer, "Sensor %d: %d", i, sensorValue );
    Serial.println(buffer) ;
  }*/
  delay(1000);        // delay in between reads = 1s
}
