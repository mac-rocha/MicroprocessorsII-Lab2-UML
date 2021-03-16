# pyserial-test.py
# test serial communication with Arduino
#
# require pip install pyserial
#
# Usage: python3 pyserial-test.py
#
# yluo
#
import serial 

# serial port dev file name
# need to change based on the particular host machine
# serialDevFile = '/dev/tty.usbmodem14601'
serialDevFile = 'COM4'
ser=serial.Serial(serialDevFile, 9600, timeout=0.1)

i = 0
while True:
    direction = ser.readline()
    direction = direction.decode()
    if direction != '':
        arduinoInput = direction
        print(arduinoInput)



    if i % 100 == 0:
        ser.write(b'E')
    i += 1