import serial #Serial imported for Serial communication
import time #Required to use delay functions
import statistics as stat

ArduinoSerial = serial.Serial('com3',baudrate=1152000,timeout=50)

time.sleep(2)
ArduinoSerial.write('1'.encode('utf-8'))

while 1:
     if(ArduinoSerial.readline()):
          # print(ArduinoSerial.readline())
          m=str(ArduinoSerial.readline())
          m=m[2:3]
          print(m)
# initial_data1=[]
# initial_data2=[]

# initial_bool1=False
# initial_bool2=False

# median1=0
# median2=0

# m=0

# # ArduinoSerial.timeout(float(1000))
# while 1:
#      if(initial_bool1==0 and initial_bool2==0):
#           if(ArduinoSerial.readline()):
#                if(m%2):
#                     initial_data2.append(ArduinoSerial.readline())
#                     print((ArduinoSerial.readline()))
#                else:
#                     initial_data1.append(ArduinoSerial.readline())
#                     print((ArduinoSerial.readline()))
#                m+=1
#           print(m)

#           if(len(initial_data1)==100 and initial_bool2==False):
#                initial_data=[str(x) for x in initial_data1 ]
#                initial_data=[x.replace("b\'","") for x in initial_data]
#                initial_data=[x.replace("\\r\\n\'","") for x in initial_data]
#                for x in range(len(initial_data)):
#                     try:
#                          initial_data[x]=int(initial_data[x])
#                     except:
#                          initial_data[x]=0
#                median1=stat.median(initial_data)
#                print("Mean1",median1)
#                initial_bool2=True
#           # exit()
     
#           if(len(initial_data1)==100 and initial_bool1==False):
#                initial_data=[str(x) for x in initial_data2 ]
#                initial_data=[x.replace("b\'","") for x in initial_data]
#                initial_data=[x.replace("\\r\\n\'","") for x in initial_data]
          
#                for x in range(len(initial_data)):
#                     try:
#                          initial_data[x]=int(initial_data[x])
#                     except:
#                          initial_data[x]=0
#                median2=stat.median(initial_data)
#                print("Mean2",median2)
#                initial_bool1=True
#           # exit()
     
#      if(initial_bool1 and initial_bool2):
#           ArduinoSerial.write(str(median1).encode('utf-8'))
#           # sleep(1)
#           ArduinoSerial.write(str(median2).encode('utf-8'))
#           ArduinoSerial.flush()
#           if(ArduinoSerial.readline()):
#                print("m1",(ArduinoSerial.readline()))
          
#           # if(ArduinoSerial.readline()):
#           #      print("m2",(ArduinoSerial.readline()))
#           #      # exit()
          

     

