#include<Wire.h>

const int xPin = 0; // analog pin connected to X output
const int yPin = 1; // analog pin connected to Y output
int buzzer = 12; // buzzer connected to pin 6
int incomingByte = 0; // incoming bytes at serial port
const int MPU6050_addr=0x68; // MPU6050 address
int16_t GyroX,GyroY,GyroZ; // gyro X, Y, Z variables

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600); // initialize serial communication at 9600 bps
  pinMode(buzzer, OUTPUT); 
}

void loop() {
  joystickControls(); // call joystickControls() function to play the game with joystick

  gyroControls(); // call gyroControls() function to play game with gyro

  // read bytes if the number of bytes at serial port > 0
  if (Serial.available() > 0) {
    incomingByte = Serial.read();

    // if score increased by 10, beep buzzer
    if (incomingByte == 'E') {
      appleEaten(400);
    }
  }
}

void joystickControls() {
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
    Serial.write("w"); // write control 'w' to serial port
    delay(50); // add a delay
  }

  // if Y position is 5, move down
  else if (vertical == 5) {
    Serial.write("s"); // write control 's' to serial port
    delay(50); // add a delay
  }
}

void gyroControls() {
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr,14,true);
  
  GyroX = (Wire.read() << 8 | Wire.read()) / 131.0; // X position of gyro
  GyroY = (Wire.read() << 8 | Wire.read()) / 131.0; // Y position of gyro
  GyroZ = (Wire.read() << 8 | Wire.read()) / 131.0; // Z position of gyro

  // if X position is greater than 45, move left
  if (GyroX > 45) {
    Serial.write("a"); // write control 'a' to serial port
    delay(30); // add a delay
  }

  // if X position is less than -45, move right
  else if (GyroX < -45) {
    Serial.write("d"); // write control 'd' to serial port
    delay(30); // add a delay
  }

  // if Y position is less than -45, move up
  else if (GyroY < -45) {
    Serial.write("w"); // write control 'w' to serial port
    delay(30); // add a delay
  }

  // if Y position is greater than 45, move down
  else if (GyroY > 45) {
    Serial.write("s"); // write control 's' to serial port
    delay(30); // add a delay
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
