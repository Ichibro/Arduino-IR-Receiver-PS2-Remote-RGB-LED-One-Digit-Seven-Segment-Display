// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>

// Define sensor pin
const int RECV_PIN = 4;

// Define LED pin constants
int E = 8;
int D = 9;
int C = 12;
int DP = 13;
int B = 7;
int A = 11;
int F = 3;
int G = 2;
int redPinCC = 10;
int greenPinCC = 5;
int bluePinCC = 6;
// Define integer to remember toggle state
int togglestate = 0;
int digit = 20;
int digistate = 0;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;



void zero() {
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digit = 0;

}


void one() {
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digit = 1;

}

void two() {
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(DP, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digit = 2;

}

void three() {
  digitalWrite(E, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digit = 3;
}

void four() {
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digit = 4;
}

void five() {
  digitalWrite(E, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digit = 5;
}

void six() {
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digit = 6;
}

void seven() {
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digit = 7;
}

void eight() {
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digit = 8;
}

void nine() {
  digitalWrite(E, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digit = 9;
}

void low() {
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, LOW);
  digitalWrite(DP, LOW);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);

}

void setup() {
  // Enable the IR Receiver
  irrecv.enableIRIn();
  Serial.begin(9600);
  // Set LED pins as Outputs
  pinMode(redPinCC, OUTPUT);
  pinMode(greenPinCC, OUTPUT);
  pinMode(bluePinCC, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(DP, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  setColor(0, 0, 0);
}


void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPinCC, redValue);
  analogWrite(greenPinCC, greenValue);
  analogWrite(bluePinCC, blueValue);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    switch (results.value) {
      case 0x7AB5B: //Red Keypad Button
        // Turn on LED for 2 Seconds
        if (togglestate == 0) {
          setColor(0, 0, 255);
          togglestate = 1;
        }
        else {
          setColor(0, 0, 0);
          togglestate = 0;
        }
        break;

      case 0xBAB5B: //Yellow Keypad Button
        // Toggle LED On or Off
        if (togglestate == 0) {
          setColor(255, 0, 0);
          togglestate = 1;
        }
        else {
          setColor(0, 0, 0);
          togglestate = 0;
        }
        break;


      case 0x90B92: //Yellow Keypad Button
        // Toggle LED On or Off
        if (togglestate == 0) {
          zero();
          togglestate = 1;
          digistate = 1;
        }
        else {
          low();
          togglestate = 0;
          digistate = 0;
          digit = 20;
        }
        break;

      case 0xB92: //Yellow Keypad Button
        // Toggle LED On or Off
        if (togglestate == 0) {
          one();
          togglestate = 1;
          digistate = 2;
        }
        else {
          low();
          togglestate = 0;
          digistate = 0;
          digit = 20;
        }
        break;

      case 0x80B92: //Yellow Keypad Button
        // Toggle LED On or Off
        if (togglestate == 0) {
          two();
          togglestate = 1;
          digistate = 3;
        }
        else {
          low();
          togglestate = 0;
          digistate = 0;
          digit = 20;
        }
        break;

      case 0x40B92: //Yellow Keypad Button
        // Toggle LED On or Off
        if (togglestate == 0) {
          three();
          togglestate = 1;
          digistate = 4;
        }
        else {
          low();
          digistate = 0;
          togglestate = 0;
          digit = 20;
        }
        break;

      case 0xC0B92: //Yellow Keypad Button
        // Toggle LED On or Off
        if (togglestate == 0) {
          four();
          togglestate = 1;
          digistate = 5;
        }
        else {
          low();
          digistate = 0;
          togglestate = 0;
          digit = 20;
        }
        break;

      case 0x20B92: //Yellow Keypad Button
        // Toggle LED On or Off
        if (togglestate == 0) {
          five();
          togglestate = 1;
          digistate = 6;
        }
        else {
          low();
          togglestate = 0;
          digistate = 0;
          digit = 20;
        }
        break;

      case 0xA0B92: //Yellow Keypad Button
        // Toggle LED On or Off
        if (togglestate == 0) {
          six();
          togglestate = 1;
          digistate = 7;
        }
        else {
          low();
          digit = 20;
          digistate = 0;
          togglestate = 0;
        }
        break;

      case 0x60B92: //Yellow Keypad Button
        // Toggle LED On or Off
        if (togglestate == 0) {
          seven();
          togglestate = 1;
          digistate = 8;
        }
        else {
          low();
          digistate = 0;
          digit = 20;
          togglestate = 0;
        }
        break;

      case 0xE0B92: //Yellow Keypad Button
        // Toggle LED On or Off
        if (togglestate == 0) {
          eight();
          togglestate = 1;
          digistate = 9;
        }
        else {
          low();
          digistate = 0;
          digit = 20;
          togglestate = 0;
        }
        break;

      case 0x10B92: //Yellow Keypad Button
        // Toggle LED On or Off
        if (togglestate == 0) {
          nine();
          togglestate = 1;
          digistate = 10;
        }
        else {
          low();
          digit = 20;
          digistate = 0;
          togglestate = 0;
        }
        break;

      case 0xFAB5B: //RGB Keypad Button
        // Toggle LED On or Off
        if (togglestate == 0) {
          setColor(148, 0, 211);
          togglestate = 1;
        }
        else {
          setColor(0, 0, 0);
          togglestate = 0;
        }
        break;


      case 0xD0B92: //RGB Keypad Button
        // Toggle LED On or Off
        if (digistate == 1 && digit == 0) {
          setColor(102, 0, 204);
          digistate = 0;
        }
        else if (digistate == 2 && digit == 1) {
          setColor(0, 225, 0);
          digistate = 0;
        }
        else if (digistate == 3 && digit == 2) {
          setColor(225, 10, 0);
          digistate = 0;
        }
        else if (digistate == 4 && digit == 3) {
          setColor(0, 100, 100);
          digistate = 0;
        }
        else if (digistate == 5 && digit == 4) {
          setColor(255, 20, 100);
          digistate = 0;
        }
        else if (digistate == 6 && digit == 5) {
          setColor(225, 220, 225);
          digistate = 0;
        }
        else if (digistate == 7 && digit == 6) {
          setColor(255, 50, 0);
          digistate = 0;
        }
        else if (digistate == 8 && digit == 7) {
          setColor(225, 0, 0);
          digistate = 0;
        }
        else if (digistate == 9 && digit == 8) {
          setColor(0, 0, 225);
          digistate = 0;
        }
        else if (digistate == 10 && digit == 9) {

          unsigned int rgbColour[3];

          // Start off with red.
          rgbColour[0] = 255;
          rgbColour[1] = 0;
          rgbColour[2] = 0;

          // Choose the colours to increment and decrement.
          for (int decColour = 0; decColour < 3; decColour += 1) {
            int incColour = decColour == 2 ? 0 : decColour + 1;

            // cross-fade the two colours.
            for (int i = 0; i < 255; i += 1) {
              rgbColour[decColour] -= 1;
              rgbColour[incColour] += 1;

              setColor(rgbColour[0], rgbColour[1], rgbColour[2]);
              delay(10);
              digistate = 0;
            }
          }
        }
        else {
          setColor(0, 0, 0);
        }

        break;


      case 0x3AB5B: //Yellow Keypad Button
        // Toggle LED On or Off
        if (togglestate == 0) {
          setColor(0, 255, 0);
          togglestate = 1;
        }
        else {
          setColor(0, 0, 0);
          togglestate = 0;
        }
        break;
    }
    irrecv.resume();
  }

}
