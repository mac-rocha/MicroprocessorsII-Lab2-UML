const int xPin = 0; // analog pin connected to X output
const int yPin = 1; // analog pin connected to Y output
  
void setup() {
  Serial.begin(9600);
}

void loop() {
  int horizontal=map((analogRead(xPin)+18), 0, 1023, -5, +5); // X position
  int vertical=map((analogRead(yPin)+18), 0, 1023, -5, +5); // Y position

  // display hotizontal and vertical positions on serial monitor according to movement with analog joystick
  Serial.print("X-axis: ");
  Serial.print(horizontal);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.print(vertical);
  Serial.print("\n\n");
  delay(1000);

  // initial position of joystick is X=0 Y=0

  // if X position is less than 0, joystick moved left
  if (horizontal < 0) {
    Serial.println("left");
    delay(150); // add a delay
  }

  // if X position is greater than 0, joystick moved right
  else if (horizontal > 0) {
     Serial.println("right");
     delay(150); // add a delay
  }

  // if Y position is less than 0, joystick moved up
  else if (vertical < 0) {
     Serial.println("up");
     delay(150); // add a delay
  }

  // if Y position is greater than 0, joystick moved down
  else if (vertical > 0) {
    Serial.println("down");
    delay(150); // add a delay
  }
}
