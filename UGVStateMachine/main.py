from time import sleep

class StateMachineTest:

    def __init__(self):
        print("State Machine has been initialised")
        #state registers:
        self.currentStateNumber = 0b00
        self.nextStateNumber = 0b00

        self.LEDLocationsisled1 = 0b01 #add back . between LEDLocationsisled1
        self.CommsTimeoutUAV = 0b0
        self.CommsTimeoutUGV = 0b0
        self.LEDDetected = 0b1
        self.FireSeverityIsDetected = 0b0
        self.UGV2to1Ack = 0b1
        self.UGV1Jump = 0b0
        self.GO = 0b1

    def StateMachine(self):

        #create local counter tUAV

        #This state = next state

        self.currentStateNumber = self.nextStateNumber

        #00000
            #state = "Idle"
            #description = "Idle"
            #UGV1to2Ack = None
            #Transition to 00001 if:
                #LEDDetected = 1 or CommsTimeoutUAV = 1

        if (self.currentStateNumber == 0b00000):
            self.state = "Idle"
            self.stateDescription = "Idle"
            if ((self.LEDLocationsisled1 == 0b1) or (self.CommsTimeoutUAV == 0b1)):
                self.nextStateNumber = 0b01
            else:
                self.nextStateNumber = self.currentStateNumber

        #00001
            #state = "Idle"
            #description = "Proposing Policy"
            #UGV1to2Ack = "Hey"
            #Transition to 01100 if:
                #CommsTimeoutUAV = 1
            #Transition to 00010 if:
                #LEDDetected = 1 and CommsTimeoutUAV = 0
            #Transition to 00000 if:
                #LEDDetected = 0 and CommsTimeoutUAV = 0

        elif (self.currentStateNumber == 0b00001):
            self.state = "Idle"
            self.stateDescription = "Proposing Policy"
            if ((self.LEDDetected == 1) and (self.CommsTimeoutUAV == 0)):
                self.nextStateNumber = 0b0010

            if ((self.LEDDetected == 0) and (self.CommsTimeoutUAV == 0)):
                self.nextStateNumber = 0b00000

            if (self.CommsTimeoutUAV == 0b1):
                self.nextStateNumber = 0b0
                
        
        #00010
            #State = "Idle"
            #Description = "Receiving Policy"
            #UGV1to2Ack = "Ack" 
            #Transition to 01100 if:
                #CommsTimeoutUAV= 1 or CommsTimeoutUGV = 1
            #Transition to 00011 if:
                #CommsTimeoutUAV = 0 and CommsTimeoutUGV = 0
        elif (self.currentStateNumber == 0b00010):
            self.state = "Idle"
            self.stateDescription = "Receiving Policy"

            if ((self.CommsTimeoutUGV == 1) and (self.CommsTimeoutUAV == 1)):
                self.nextStateNumber = 0b01100

            elif ((self.CommsTimeoutUGV == 0) or (self.CommsTimeoutUAV == 0)):
                self.nextStateNumber = 0b00011

        #00011
            #State = "Waiting"
            #Description = "Waiting for answer back from UGV2 (seeing if UGV2 Approves)"
            #UGV1to2Ack = None 
            #Transition to 00100:
                #Policy Accepted by UGV1
            #Transition to 01011:
                #Policy Rejected by UGV1 and self.UGV2to1Ack = yes
            #Transition to 00000:
                #LEDDetected = 0
        elif (self.currentStateNumber == 0b00011):
            self.state = "Waiting"
            self.stateDescription = "Waiting for answer back from UGV2 (seeing if UGV2 Approves)"
            acceptPolicy = 1

            #code block to determine if policy is approved
            if ((self.UGV2to1Ack == "Yes") and (self.LEDDetected == 1)):
                if(acceptPolicy == 1):
                    self.nextStateNumber = 0b00100
                if(acceptPolicy == 0):
                    self.nextStateNumber = 0b01011
            elif(self.LEDDetected == 0):
                self.nextStateNumber = self.currentStateNumber
            elif(self.UGV2to1Ack == "No"):
                self.nextStateNumber = 0b1
            else:
                self.nextStateNumber = self.currentStateNumber

        #00100
            #State = "Waiting"
            #Description = "Received policy and content"
            #UGV1to2Ack = "Yes" 
            #Transition to 00101:
                #self.UGV2to1Ack = Ack
            #Transition to 01110:
                #CommsTimeoutUGV=1

        elif (self.currentStateNumber == 0b00100):
            self.state = "Waiting"
            self.stateDescription = "Received policy and content"
            UGV1to2Ack = "Yes"
            if (self.UGV2to1Ack == "Ack"):
                self.nextStateNumber = 0b00101
            elif (self.CommsTimeoutUGV == 1):
                self.nextStateNumber = 0b01110

        #00101
            #State = "Transit"
            #Description = "Moving"
            #UGV1to2Ack = "Ack"
            #Transition to 00110:
                #UGV arrives at waypoint
            #Transition to 01111:
                #UGV1Jump = 1

        elif (self.currentStateNumber == 0b00101):
            self.state = "Transit"
            self.stateDescription = "Moving"
            UGV1to2Ack = "Ack"
            Atwaypoint = 1 #stand in variable for transit
            if (Atwaypoint == 1):
                self.nextStateNumber = 0b00110
            if (self.UGV1Jump == 1):
                self.nextStateNumber = 0b01111

        #00110
            #State = "Attending"
            #Description = "Reporting LED Intensity"
            #UGV1to2Ack = None 
            #Transition to 0111:
                #100ms delay
        
        elif (self.currentStateNumber == 0b00110):
            self.state = "Attending"
            self.stateDescription = "Reporting LED Intensity"
            sleep(0.1) # sleep for 100 ms
            self.nextStateNumber = 0b00111

            
        #00111
            #State = "Attending"
            #Description = "Receiving LED Intensity"
            #UGV1to2Ack = None
            #Transition to 01000:
                #Zone 1 Severity < Zone 2 Severity
            #Transition to 01001:
                #Zone 1 Severity > Zone 2 Severity
            #Transition to 01010:
                #GO = 0

        elif (self.currentStateNumber == 0b00111):
            self.state = "Attending"
            self.stateDescription = "Recieving LED Intensity"
            
            #Determine the higher severity
            HighestSeverity = 1 #either 0,1,2

            if (HighestSeverity == 2):
                self.nextStateNumber = 0b01000
            else:
                self.nextStateNumber = 0b01001
            
            if (self.GO == 0):
                self.nextStateNumber = 0b01010
            
        #01000
            #State = "Transit"
            #Description = "Going to the other fire"
            #UGV1to2Ack = None
            #Transition to 01010:
                #GO=0
            #Transition to 01001:
                #Fire is extinguished
        elif (self.currentStateNumber == 0b01000):
            self.state = "Transit"
            self.stateDescription - "Going to other fire"
            if (self.GO == 0):
                self.nextStateNumber = 0b01010
            if (self.FireSeverityIsDetected == 0):
                self.nextStateNumber = 0b01001
        
        #01001
            #State = "Attending"
            #Description = "Waiting in zone"
            #UGV1to2Ack = None
            #Transition to 01010:
                #GO = 0
        elif (self.currentStateNumber == 0b01001):
            self.state = "Attending"
            self.stateDescription = "Waiting in zone"
            #wait

            if (self.GO == 0):
                self.nextStateNumber = 0b01010
            else:
                self.nextStateNumber = 0b00110


        #01010
            #State = "Transit"
            #Description = "Return to centre"
            #UGV1to2Ack = None
            #transition to 000000
        elif (self.currentStateNumber == 0b01010):
            self.state = "Transit"
            self.stateDescription = "Return to centre"
            self.nextStateNumber = 0b0000

        #01100
            #State = "Attending"
            #Description = "Attend to the other zone if not responsive"
            #UGV1to2Ack = None
            #Transition to 01101:
                #each clock cycle
        elif (self.currentStateNumber == 0b01100):
            self.state = "Attending"
            self.stateDescription = "Attend to other zone if not responsive"
            self.nextStateNumber = 0b01101

        #01101
            #State = "Transit"
            #Description = "Check every zone"
            #UGV1to2Ack = None
            #Transition to 01110:
                #next clock cycle
        elif (self.currentStateNumber == 0b01101):
            self.state = "Transit"
            self.stateDescription = "Check every zone"
            self.nextStateNumber = 0b01110

        #01110:
            #State = "Idle"
            #Description = "Create two zone policy"
            #UGV1to2Ack = None
            #Transition to 00101:
                #Next clock cycle
        elif (self.currentStateNumber == 0b01110):
            self.state = "Idle"
            self.stateDescription = "Create two zone policy"
            self.nextStateNumber = 0b00101
            
        #01111:
        #State = "Attending"
        #Description = "Receive Message Interrupt"
        #UGV1to2Ack = None
        elif (self.currentStateNumber == 0b01111):
            self.state = "Attending"
            self.stateDescription = "Recieve Message Interrupt"

        #10000:
            #State = "DND"
            #Description = "DND"
        elif (self.currentStateNumber == 0b01000):
            self.state = "DND"
            self.stateDescription = "DND"

MIQ = StateMachineTest()

while(1==1):
    MIQ.StateMachine()
    MIQ.UGV2to1Ack = input("UGV2to1Ack?:")
    print("The state is: " + str(MIQ.state))
    print("With description: " + str(MIQ.stateDescription))
    print("The state number is: " + str(MIQ.currentStateNumber))
    print("The next state number is: " + str(MIQ.nextStateNumber))
    print("\n \n")