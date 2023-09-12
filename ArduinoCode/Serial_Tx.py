import serial
from time import sleep

# Define the serial port and baud rate
ser = serial.Serial('COM5', 9600)  # Replace '/dev/ttyS0' with the appropriate serial port

try:
    # Send the number 1 as a byte
    ser.write(b'1')
    print("Sent '1' over serial")
except Exception as e:
    print(f"An error occurred: {e}")
finally:
    # Close the serial port
    pass
received_data = ser.readline().decode('utf-8').strip()
print(recieved_data)


