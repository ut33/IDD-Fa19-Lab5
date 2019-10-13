#include <Servo.h>
Servo myservo;
int pos = 0;

int BUTTON1 = 4;
int led = 2;
unsigned long turnOffAfter = 1750;
unsigned long ledTurnedOnAt;
unsigned long buttonPushedMillis;
bool ledReady = false;
bool ledState = false;

#include "pitches.h"
//int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
//
//int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};


//Star Wars
//int melody[] = {
//  NOTE_D3,NOTE_D3,NOTE_D3,NOTE_G3,NOTE_D4,NOTE_C4,NOTE_B3,NOTE_A3,NOTE_G4,NOTE_D4, \
//  NOTE_C4,NOTE_B3,NOTE_A3,NOTE_G4,NOTE_D4,NOTE_C4,NOTE_B3,NOTE_C4,NOTE_A3,0};
// 
//int noteDurations[] = {10,10,10,2,2,10,10,10,2,4, \
//  10,10,10,2,4,10,10,10,2,4};


//Swan Lake
int melody[] = {NOTE_E4,rest, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4,NOTE_E4,NOTE_E4,rest,NOTE_C4,NOTE_E4,NOTE_E4,rest,NOTE_C4,NOTE_E4,NOTE_E4,rest,NOTE_A3, \
NOTE_C4,NOTE_A3,NOTE_F3,NOTE_C4,NOTE_A3,NOTE_A3,NOTE_D4,NOTE_C4,NOTE_B3,NOTE_E4,rest,NOTE_A3,NOTE_B3,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_E4,rest,NOTE_C4,\
NOTE_E4,NOTE_E4,rest,NOTE_C4,NOTE_E4,NOTE_E4,rest,NOTE_A3,NOTE_C4,NOTE_A3,NOTE_F3,NOTE_C4,NOTE_A3,rest,rest,NOTE_A3,NOTE_B3,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,\
NOTE_G4,NOTE_G4,rest,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_A4,rest,NOTE_G4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_B4,rest,NOTE_A4,NOTE_GS4,NOTE_A3};
int noteDurations[] = {1,1,4,4,4,4,2,4,1,4,2,4,1,4,2,4,4,4, \
4,4,4,4,1,4,4,4,4,1,1,4,4,4,4,2,4,1,4,\
2,4,1,4,2,4,4,4,4,4,4,4,1,2,1,2,2,2,2,4,4, \
2,4,1,4,2,4,4,2,4,1,4,2,4,4,2,4,1,4,2,2};
  
void setup() {

  Serial.begin(9600);
  
  myservo.attach(9);

  pinMode(BUTTON1, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

}

void loop() {
  unsigned long currentMillis = millis();
  if (digitalRead(BUTTON1) == HIGH) {
    buttonPushedMillis = currentMillis;
    ledReady = true;
  }
  if (ledReady) {
    digitalWrite(led, HIGH);
    Music();
    Move();
    ledState = true;
    ledTurnedOnAt = currentMillis;
    ledReady = false;
  }
  if (ledState) {
    if ((unsigned long)(currentMillis - ledTurnedOnAt) >= turnOffAfter) {
      ledState = false;
      digitalWrite(led, LOW);
      Stop();
    }
  }
delay(20);
} 

void Move(){
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void Stop(){
  myservo.write(0);
}

void Music(){
  for (int thisNote = 0; thisNote < 20; thisNote++) { //20 for star wars
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}
