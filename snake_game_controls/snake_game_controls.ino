const int xPin = 0; // analog pin connected to X output
const int yPin = 1; // analog pin connected to Y output
int buzzer = 12; // buzzer connected to pin 6
int incomingByte = 0;

void setup() {
  Serial.begin(9600); // initialize serial communication at 9600 bps
  pinMode(buzzer, OUTPUT);
}

void loop() {
  gameControls(); // call gameControls function

  // read bytes if the number of bytes at serial port > 0
  if (Serial.available() > 0) {
    incomingByte = Serial.read();

    // if score increased by 10, beep buzzer
    if (incomingByte == 'E') {
      appleEaten(400);
    }
  }
}

void gameControls() {
  int horizontal = map((analogRead(xPin) + 18), 0, 1023, -5, +5); // X position, starts at X=0
  int vertical = map((analogRead(yPin) + 18), 0, 1023, -5, +5); // Y position, starts at Y=0

  // if X position is -5, move left
  if (horizontal == -5) {
    Serial.write("a"); // write control 'a' to serial port
    delay(50); // add a delay
  }

  // if X position is 5, move right
  else if (horizontal == 5) {
    Serial.write("d"); // write control 'd' to serial port
    delay(50); // add a delay
  }

  // if Y position is -5, move up
  else if (vertical == -5) {
    Serial.write("s"); // write control 'w' to serial port
    delay(50); // add a delay
  }

  // if Y position is 5, move down
  else if (vertical == 5) {
    Serial.write("w"); // write control 's' to serial port
    delay(50); // add a delay
  }
}

// function for turning buzzer to beep when an apple is eaten
void appleEaten(int buzzerLength) {
  int i;

  // output a frequency
  for (i = 0; i < buzzerLength / 2; i++)
  {
    digitalWrite(buzzer, HIGH); // turn buzzer on
    delay(1);// wait for 1 ms
    digitalWrite(buzzer, LOW); // turn buzzer off
    delay(1);// wait for 1 ms
    }
  }
