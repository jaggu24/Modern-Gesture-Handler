import serial #Serial imported for Serial communication
import time #Required to use delay functions
import statistics as stat
import regression as r

ArduinoSerial = serial.Serial('com3',baudrate=1152000,timeout=50)

time.sleep(2)
ArduinoSerial.write('1'.encode('utf-8'))
data1=[]
data2=[]

time1=[0,0]
t1=0
time2=[0,0]
m=1

while 1:
     if(ArduinoSerial.readline()):
          # print(ArduinoSerial.readline().decode('utf-8'))
          m=list(ArduinoSerial.readline().decode('utf-8'))
          sonarnum=-1
          distance=''
          sonarnum=m[len(m)-3]
          distance=m[:len(m)-3]
          if(len(distance)>1):
               distance=int(distance[0]+distance[1])
          else:
               distance=int(distance[0])
          if(sonarnum):
               data1.append(distance)
               if(time1[0]==0):
                    time1[0]=int(round(time.time() *100))
          else:
               data2.append(distance)
               if(time2[0]==0):
                    time2[0]=int(round(time.time() *100))
     if(len(data1)==10):
          r.prediction(data1)
          time.sleep(2)
          data1=[]
     if(len(data2)==10):
          
          r.prediction(data2)
          time.sleep(2)
          data2=[]
     
     # time1[1]=int(round(time.time() *100))
     
     # if(time1[0]!=0):
     #      if(time1[1]-time1[0]> 1000 and len(data1)>5 ):
     #           r.prediction(data1)
     #           time1[0]=0
     #      if(time1[1]-time2[0]>1000 and len(data2)>5):
     #           r.prediction(data2)
     #           time2[0]=0
     # # if(time1[0]==0):
     #      if(time2[0]==0):
     #           pass
     #      else:
     #           time2[0]=0
     #           print(str(time1[1]-time2[0]),"time2")
               
     
     # else:
     #      if(time2[0]==0):
     #           time2[0]=0
     #           print(str(time1[1]-time1[0]),"time1")
               
     #      else:
     #           time1[0]=0
     #           time2[0]=0
     #           print('shit')
               

