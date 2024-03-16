#include <PinChangeInterrupt.h>

//Define pins
const int pinA = 2; //A button
const int pinB = 3; //B button

const int X = A0; //Joystick X
const int Y = A1; //Joystic Y
const int Key = 8; //Joystic key button

void sendA() {
  delayMicroseconds(10000); //to avoid chattering effect
  int buttonA = digitalRead(pinA);
  if (buttonA == 1) {
    Serial.println("a"); //Send "a" to ProtoPie
  }
}

void sendB() {
  delayMicroseconds(10000); //to avoid chattering effect
  int buttonB = digitalRead(pinB);
  if (buttonB == 1) {
    Serial.println("b"); //Send "b" to ProtoPie
  }
}


void setup() {
  Serial.begin(9600);

  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);

  pinMode(Key, INPUT);

  attachInterrupt(digitalPinToInterrupt(pinA), sendA, RISING); //Send a signal once
  attachInterrupt(digitalPinToInterrupt(pinB), sendB, RISING); //Send a signal once
  
}

void loop() {

  int xVal = analogRead (X);
  int yVal = analogRead (Y);
  int buttonVal = digitalRead (Key);

  if (xVal < 300) {
    Serial.println("left"); //Send "left" to ProtoPie
    delay(500); //Send a signal per 500ms to avoid chatting effect
  }

  if (xVal > 723) {
    Serial.println("right"); //Send "right" to ProtoPie
    delay(500); //Send a signal per 500ms to avoid chatting effect
  }
  
  if (yVal < 300) {
    Serial.println("up"); //Send "up" to ProtoPie
    delay(500); //Send a signal per 500ms to avoid chatting effect
  }

  if (yVal > 723) {
    Serial.println("down"); //Send "down" to ProtoPie
    delay(500); //Send a signal per 500ms to avoid chatting effect
  }

  if (buttonVal == LOW) {
    Serial.println ("press"); //Send "press" to ProtoPie
    delay(500); //Send a signal per 500ms to avoid chatting effect
  }
}