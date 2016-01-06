import serial   #library to interact with serial port.. very similar to arduino version
import time     #for delays
import msvcrt   #to detect key presses
from array import *

print "Initalizing Serial port...\n"
arduino = serial.Serial(3,115200,timeout = 1) # 2=Com3 on windows always a good idea to sepcify a timeout incase we send bad data
time.sleep(2) #wait for initialize
noLimbs = 4
motorState = array('i', [0] * noLimbs)
print "States Initalized...\n"
print "Ready for Input...\n"

while 1: # Like Arduino for loop makes the program loop forever

     if msvcrt.kbhit():                  #if there was a keyboard press
        print "Something was pressed \n"
        keypressed = ord(msvcrt.getch())
        print "Keypressed is %d" % keypressed
#CW
        if keypressed == 49:  # if the key pressed = '1'
             motorState[0] = 1
        if keypressed == 50:  # if the key pressed = '2'
             motorState[1] = 1
        if keypressed == 51:  # if the key pressed = '3'
             motorState[2] = 1
        if keypressed == 52:  # if the key pressed = '4'
             motorState[3] = 1
# CCW
        if keypressed == 55:  # if the key pressed = '7'
            motorState[3] = 2
        if keypressed == 56:  # if the key pressed = '8'
            motorState[2] = 2
        if keypressed == 57:  # if the key pressed = '9'
            motorState[1] = 2
        if keypressed == 48:  # if the key pressed = '0'
            motorState[0] = 2
#OFF
        if keypressed == 113: # if the key pressed = 'Q'
             motorState[0] = 0     
        if keypressed == 119: # if the key pressed = 'W'
             motorState[1] = 0
        if keypressed == 101: # if the key pressed = 'E'
             motorState[2] = 0  
        if keypressed == 114: # if the key pressed = 'R'
             motorState[3] = 0  
#BREAK
        if keypressed == 32:  # if the key pressed = 'SPACE' 
             motorState = array('i', [0] * noLimbs)
             print "LS%dS%dS%dS%d" %(motorState[0],motorState[1],motorState[2],motorState[3])
             break             
        if keypressed == 9:
         print "LS%dS%dS%dS%d" %(motorState[0],motorState[1],motorState[2],motorState[3])
     
     else:
          command = "LS%dS%dS%dS%d" %(motorState[0],motorState[1],motorState[2],motorState[3])
          arduino.write(command) 

