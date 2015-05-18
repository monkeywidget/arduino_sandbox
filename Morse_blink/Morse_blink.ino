/*
  Based on "Blink"   by Scott Fitzgerald

  Since many boards ship with "Blink" already installed, 
  I wanted an alternate Blink I could tell was mine.
  
  I've added
  - basic spaces and dit/dah for Morse code
  - 2 letters (S and O)
  - a basic message (S.O.S.) that repeats

  Tech details from Mr. Fitzgerald :
  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  modified May 2015
 */


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

void intraletter_space() {
  digitalWrite(13, LOW);  
  delay(150);
}

void interletter_space() {
  digitalWrite(13, LOW);  
  delay(400);
}

void interword_space() {
  digitalWrite(13, LOW);  
  delay(1000);
}

void dit() {
  digitalWrite(13, HIGH);
  delay(100);            
}

void dah() {
  digitalWrite(13, HIGH);
  delay(400);            
}

void send_S() {
  dit();
  intraletter_space();
  dit();
  intraletter_space();
  dit();
  interletter_space();
}

void send_O() {
  dah();
  intraletter_space();
  dah();
  intraletter_space();
  dah();
  interletter_space();
}


// the loop function runs over and over again forever
void loop() {
  send_S();
  send_O();
  send_S();  
  interword_space();
}
