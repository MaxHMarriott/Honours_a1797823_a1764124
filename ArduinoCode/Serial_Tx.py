import serial
from random import random
import time

# Define the serial port and baud rate
#serial_port = '/dev/serial/by-id/usb-1a86_USB2.0-Serial-if00-port0'
serial_port = '/dev/serial/by-id/usb-1a86_USB2.0-Serial-if00-port0'
  # Replace with the correct COM port for your Arduino
baud_rate = 9600  # This should match the baud rate set in your Arduino sketch

# Create a serial connection
ser = serial.Serial(serial_port, baud_rate,timeout=1)
print("This has run")

serialin = '1\n'

#ser.write(serialin.encode('utf-8'))

print("We have written: " + str(serialin))

try:
    while True:
        # Read data from Arduino
        a = int(random()*4)
        ser.write(f'{a}\n'.encode('utf-8'))
        data = ser.readline().decode('utf-8').strip()
        print(f'Received: {data}')
        time.sleep(1)
        # You can send data back to the Arduino if needed
except KeyboardInterrupt:
    print("KeyboardInterrupt: Stopping the script.")
finally:
    # Close the serial connection when done
    ser.close()
