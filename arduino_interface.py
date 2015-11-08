import serial

connected = False

ser = serial.Serial("COM5", 9600)

while not connected:
    serial = ser.read()
    connected = True

while connected:
    print ser.readline()
    
ser.close()