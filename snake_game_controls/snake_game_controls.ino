const int xPin = 0; // analog pin connected to X output
const int yPin = 1; // analog pin connected to Y output
  
void setup() {
  Serial.begin(9600);
}

void loop() {
  int horizontal=map((analogRead(xPin)+18), 0, 1023, -5, +5); // X position
  int vertical=map((analogRead(yPin)+18), 0, 1023, -5, +5); // Y position
  
  Serial.print("X-axis: ");
  Serial.print(horizontal);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.print(vertical);
  Serial.print("\n\n");
  delay(1000);

  if (horizontal < 0) {
    Serial.println("left");
    delay(150);
  }
  
  else if (horizontal > 0) {
     Serial.println("right");
     delay(150);
  }

  else if (vertical < 0) {
     Serial.println("up");
     delay(150);
  }

  else if (vertical > 0) {
    Serial.println("down");
    delay(150);
  }
}
