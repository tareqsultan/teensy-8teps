// Teensyduino MIDI Beat Clock Example
// by Sebastian Tomczak
// 29 August 2011
// 8 steps sync with DAW MIDI Clock Example for Teensy 3.2 / devaloped over Sebastian Tomczak code
// https://little-scale.blogspot.com/2011/08/how-to-deal-with-real-time-midi-beat.html
// made by Tareq sultan 
//13 sep 2024 
/////////////////////////8 Knobs/////////////////////////////////
const int buttonPin1 = 1; // Button connected to pin 1
const int buttonPin2 = 2; // Button connected to pin 2
const int buttonPin3 = 3; // Button connected to pin 3
const int buttonPin4 = 4; // Button connected to pin 4
const int buttonPin5 = 5; // Button connected to pin 5
const int buttonPin6 = 6; // Button connected to pin 6
const int buttonPin7 = 7; // Button connected to pin 7
const int buttonPin8 = 8; // Button connected to pin 8

const int potPin1 = A0;   // Potentiometer connected to analog pin A0
const int potPin2 = A1;   // Potentiometer connected to analog pin A1
const int potPin3 = A2;   // Potentiometer connected to analog pin A2
const int potPin4 = A3;   // Potentiometer connected to analog pin A3
const int potPin5 = A4;   // Potentiometer connected to analog pin A4
const int potPin6 = A5;   // Potentiometer connected to analog pin A5
const int potPin7 = A6;   // Potentiometer connected to analog pin A6
const int potPin8 = A7;   // Potentiometer connected to analog pin A7

int noteNumber1 = 0; // Initial note number
int noteNumber2 = 0; // Initial note number
int noteNumber3 = 0; // Initial note number
int noteNumber4 = 0; // Initial note number
int noteNumber5 = 0; // Initial note number
int noteNumber6 = 0; // Initial note number
int noteNumber7 = 0; // Initial note number
int noteNumber8 = 0; // Initial note number
///////////////////////Bounce button////////////////////////////
#include <Bounce.h>
Bounce button1 = Bounce(1, 5);
Bounce button2 = Bounce(2, 5);
Bounce button3 = Bounce(3, 5);
Bounce button4 = Bounce(4, 5);
Bounce button5 = Bounce(5, 5);
Bounce button6 = Bounce(6, 5);
Bounce button7 = Bounce(7, 5);
Bounce button8 = Bounce(8, 5);
////////////////////////
byte counter;
byte CLOCK = 252;//248
byte START = 250;
byte CONTINUE = 250;//251
byte STOP = 252;//252
const int channel = 1;
void setup() {
Serial.begin(31250);
//pinMode(11, OUTPUT);
//digitalWrite(11, HIGH);
//usbMIDI.sendNoteOn(60, 99, channel);
usbMIDI.setHandleRealTimeSystem(RealTimeSystem);
///////////////////////////
pinMode(1, INPUT_PULLUP);
pinMode(2, INPUT_PULLUP);
pinMode(3, INPUT_PULLUP);
pinMode(4, INPUT_PULLUP);
pinMode(5, INPUT_PULLUP);
pinMode(6, INPUT_PULLUP);
pinMode(7, INPUT_PULLUP);
pinMode(8, INPUT_PULLUP);
  ///////////////////////
}

void loop() {
  //////////////////////////pot map Value //////////////////////
   int potValue1 = analogRead(potPin1); // Read potentiometer value
  noteNumber1 = map(potValue1, 0, 1023, 48, 80); // Map pot value to note number range (0-127)
int potValue2 = analogRead(potPin2); // Read potentiometer value
  noteNumber2 = map(potValue2, 0, 1023, 48, 80);
  int potValue3 = analogRead(potPin3); // Read potentiometer value
  noteNumber3 = map(potValue3, 0, 1023, 48, 80);
  int potValue4 = analogRead(potPin4); // Read potentiometer value
  noteNumber4 = map(potValue4, 0, 1023, 48, 80);
  int potValue5 = analogRead(potPin5); // Read potentiometer value
  noteNumber5 = map(potValue5, 0, 1023, 48, 80);
  int potValue6 = analogRead(potPin6); // Read potentiometer value
  noteNumber6 = map(potValue6, 0, 1023, 48, 80);
  int potValue7 = analogRead(potPin7); // Read potentiometer value
  noteNumber7 = map(potValue7, 0, 1023, 48, 80);
  int potValue8 = analogRead(potPin8); // Read potentiometer value
  noteNumber8 = map(potValue8, 0, 1023, 48, 80);
  //////////////////////////////////////////////////////////
button1.update();
button2.update();
button3.update();
button4.update();
button5.update();
button6.update();
button7.update();
button8.update();

if (button1.fallingEdge()) {
    usbMIDI.sendNoteOn(noteNumber1, 99, channel);  // 60 = C4
}
    if (button1.risingEdge()) {
    usbMIDI.sendNoteOff(noteNumber1, 0, channel);  // 60 = C4
  }

  if (button2.fallingEdge()) {
    usbMIDI.sendNoteOn(noteNumber2, 99, channel);  // 60 = C4
}
    if (button2.risingEdge()) {
    usbMIDI.sendNoteOff(noteNumber2, 0, channel);  // 60 = C4
  }
  if (button3.fallingEdge()) {
    usbMIDI.sendNoteOn(noteNumber3, 99, channel);  // 60 = C4
}
    if (button3.risingEdge()) {
    usbMIDI.sendNoteOff(noteNumber3, 0, channel);  // 60 = C4
  }

  if (button4.fallingEdge()) {
    usbMIDI.sendNoteOn(noteNumber4, 99, channel);  // 60 = C4
}
    if (button4.risingEdge()) {
    usbMIDI.sendNoteOff(noteNumber4, 0, channel);  // 60 = C4
  }
  if (button5.fallingEdge()) {
    usbMIDI.sendNoteOn(noteNumber5, 99, channel);  // 60 = C4
}
    if (button5.risingEdge()) {
    usbMIDI.sendNoteOff(noteNumber5, 0, channel);  // 60 = C4
  }
  if (button6.fallingEdge()) {
    usbMIDI.sendNoteOn(noteNumber6, 99, channel);  // 60 = C4
}
    if (button6.risingEdge()) {
    usbMIDI.sendNoteOff(noteNumber6, 0, channel);  // 60 = C4
  }
  if (button7.fallingEdge()) {
    usbMIDI.sendNoteOn(noteNumber7, 99, channel);  // 60 = C4
}
    if (button7.risingEdge()) {
    usbMIDI.sendNoteOff(noteNumber7, 0, channel);  // 60 = C4
  }
  if (button8.fallingEdge()) {
    usbMIDI.sendNoteOn(noteNumber8, 99, channel);  // 60 = C4
}
    if (button8.risingEdge()) {
    usbMIDI.sendNoteOff(noteNumber8, 0, channel);  // 60 = C4
  }
  //////////////////////////////////////////////////////////
  
usbMIDI.read();

}

void RealTimeSystem(byte realtimebyte) {
if(realtimebyte == 248) {
counter++;
//1-0-0-0-0-0-0-0
if(counter == 96) {
counter = 0;
//digitalWrite(11, HIGH);
usbMIDI.sendNoteOn(noteNumber1, 99, channel);
usbMIDI.sendNoteOff(noteNumber2, 0, channel);
usbMIDI.sendNoteOff(noteNumber3, 0, channel);
usbMIDI.sendNoteOff(noteNumber4, 0, channel);
usbMIDI.sendNoteOff(noteNumber5, 0, channel);
usbMIDI.sendNoteOff(noteNumber6, 0, channel);
usbMIDI.sendNoteOff(noteNumber7, 0, channel);
usbMIDI.sendNoteOff(noteNumber8, 0, channel);
}
}
// 0-1-0-0-0-0-0-0
if(counter == 12) {
//digitalWrite(11, LOW);
usbMIDI.sendNoteOff(noteNumber1, 0, channel);
usbMIDI.sendNoteOn(noteNumber2, 99, channel);
usbMIDI.sendNoteOff(noteNumber3, 0, channel);
usbMIDI.sendNoteOff(noteNumber4, 0, channel);
usbMIDI.sendNoteOff(noteNumber5, 0, channel);
usbMIDI.sendNoteOff(noteNumber6, 0, channel);
usbMIDI.sendNoteOff(noteNumber7, 0, channel);
usbMIDI.sendNoteOff(noteNumber8, 0, channel);
}
// 0-0-1-0-0-0-0-0
if(counter == 24) {
//digitalWrite(11, LOW);
usbMIDI.sendNoteOff(noteNumber1, 0, channel);
usbMIDI.sendNoteOff(noteNumber2, 0, channel);
usbMIDI.sendNoteOn(noteNumber3, 99, channel);
usbMIDI.sendNoteOff(noteNumber4, 0, channel);
usbMIDI.sendNoteOff(noteNumber5, 0, channel);
usbMIDI.sendNoteOff(noteNumber6, 0, channel);
usbMIDI.sendNoteOff(noteNumber7, 0, channel);
usbMIDI.sendNoteOff(noteNumber8, 0, channel);
}
// 0-0-0-1-0-0-0-0
if(counter == 36) {
//digitalWrite(11, LOW);
usbMIDI.sendNoteOff(noteNumber1, 0, channel);
usbMIDI.sendNoteOff(noteNumber2, 0, channel);
usbMIDI.sendNoteOff(noteNumber3, 0, channel);
usbMIDI.sendNoteOn(noteNumber4, 99, channel);
usbMIDI.sendNoteOff(noteNumber5, 0, channel);
usbMIDI.sendNoteOff(noteNumber6, 0, channel);
usbMIDI.sendNoteOff(noteNumber7, 0, channel);
usbMIDI.sendNoteOff(noteNumber8, 0, channel);
}
// 0-0-0-0-1-0-0-0
if(counter == 48) {
//digitalWrite(11, LOW);
usbMIDI.sendNoteOff(noteNumber1, 0, channel);
usbMIDI.sendNoteOff(noteNumber2, 0, channel);
usbMIDI.sendNoteOff(noteNumber3, 0, channel);
usbMIDI.sendNoteOff(noteNumber4, 0, channel);
usbMIDI.sendNoteOn(noteNumber5, 99, channel);
usbMIDI.sendNoteOff(noteNumber6, 0, channel);
usbMIDI.sendNoteOff(noteNumber7, 0, channel);
usbMIDI.sendNoteOff(noteNumber8, 0, channel);
}
// 0-0-0-0-0-1-0-0
if(counter == 60) {
//digitalWrite(11, LOW);
usbMIDI.sendNoteOff(noteNumber1, 0, channel);
usbMIDI.sendNoteOff(noteNumber2, 0, channel);
usbMIDI.sendNoteOff(noteNumber3, 0, channel);
usbMIDI.sendNoteOff(noteNumber4, 0, channel);
usbMIDI.sendNoteOff(noteNumber5, 0, channel);
usbMIDI.sendNoteOn(noteNumber6, 99, channel);
usbMIDI.sendNoteOff(noteNumber7, 0, channel);
usbMIDI.sendNoteOff(noteNumber8, 0, channel);
}
// 0-0-0-0-0-0-1-0
if(counter == 72) {
//digitalWrite(11, LOW);
usbMIDI.sendNoteOff(noteNumber1, 0, channel);
usbMIDI.sendNoteOff(noteNumber2, 0, channel);
usbMIDI.sendNoteOff(noteNumber3, 0, channel);
usbMIDI.sendNoteOff(noteNumber4, 0, channel);
usbMIDI.sendNoteOff(noteNumber5, 0, channel);
usbMIDI.sendNoteOff(noteNumber6, 0, channel);
usbMIDI.sendNoteOn(noteNumber7, 99, channel);
usbMIDI.sendNoteOff(noteNumber8, 0, channel);
}
// 0-0-0-0-0-0-0-1
if(counter == 84) {
//digitalWrite(11, LOW);
usbMIDI.sendNoteOff(noteNumber1, 0, channel);
usbMIDI.sendNoteOff(noteNumber2, 0, channel);
usbMIDI.sendNoteOff(noteNumber3, 0, channel);
usbMIDI.sendNoteOff(noteNumber4, 0, channel);
usbMIDI.sendNoteOff(noteNumber5, 0, channel);
usbMIDI.sendNoteOff(noteNumber6, 0, channel);
usbMIDI.sendNoteOff(noteNumber7, 0, channel);
usbMIDI.sendNoteOn(noteNumber8, 99, channel);
}

if(realtimebyte == START || realtimebyte == CONTINUE) {
counter = 0;
//digitalWrite(11, HIGH);
usbMIDI.sendNoteOn(noteNumber1, 99, channel);
usbMIDI.sendNoteOff(noteNumber2, 0, channel);
usbMIDI.sendNoteOff(noteNumber3, 0, channel);
usbMIDI.sendNoteOff(noteNumber4, 0, channel);
usbMIDI.sendNoteOff(noteNumber5, 0, channel);
usbMIDI.sendNoteOff(noteNumber6, 0, channel);
usbMIDI.sendNoteOff(noteNumber7, 0, channel);
usbMIDI.sendNoteOff(noteNumber8, 0, channel);
}


if(realtimebyte == STOP) {
//digitalWrite(11, LOW);
usbMIDI.sendNoteOff(noteNumber1, 0, channel);
usbMIDI.sendNoteOff(noteNumber2, 0, channel);
usbMIDI.sendNoteOff(noteNumber3, 0, channel);
usbMIDI.sendNoteOff(noteNumber4, 0, channel);
usbMIDI.sendNoteOff(noteNumber5, 0, channel);
usbMIDI.sendNoteOff(noteNumber6, 0, channel);
usbMIDI.sendNoteOff(noteNumber7, 0, channel);
usbMIDI.sendNoteOff(noteNumber8, 0, channel);
}
}
