//Mordern Gesture Handler

#define trigPin1 2
#define echoPin1 3
#define trigPin2 7
#define echoPin2 8

////Combinations
//Left and Right stop for a short time -2
//Left and Right forward motion        -2
//Left and Right backward motion       -2
//Left and Right stop for a long time  -2
//Left to Right motion                 -1
//Right to Left motion                 -1
//Both hands short time                -1
//Both hands long time                 -1
//Both hands forward and backward      -2

//                                      =14
int median1=0,median2=0;  //median of data
bool initial=false;  //initial start condition
int i=0; //array assignment
long duration1;   
long duration2;
int distance1;
int distance2;
int start=-1;
int Data_array1[100],Data_array2[100];



void startfun(){
  if (Serial.available() > 0 ) {    //Start the Data input 
    start = Serial.read()-48;
    digitalWrite(13,HIGH);
    initial=true;
  }
}

void distancecal(){
  // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin1, HIGH);
    
    delay(10);
    
    digitalWrite(trigPin1, LOW);

    duration1 = pulseIn(echoPin1, HIGH);
    
    digitalWrite(trigPin2, HIGH);
  
    delay(10);
    
    digitalWrite(trigPin2, LOW);
  
  //// Reads the echoPin, returns the sound wave travel time in microseconds
    
    duration2 = pulseIn(echoPin2, HIGH);
  
  //// Calculating the distance
    distance1= duration1*0.034/2;
    distance2= duration2*0.034/2;
}
//
//void normaldata(){
//  
//      if(distance1<median1){
//        Data_array1[i]=distance1;    
//        if(distance2<mean2){
//          Data_array2[i]=distance2;
//        }
//        else{
//          Data_array2[i]=0;
//        }
//      }
//      else{
//        Data_array2[i]=distance2;
//        Data_array1[i]=0;
//      }   
//    
//}

void initialdata(){
  
       digitalWrite(13,HIGH);
       //Median finding algo
       median1=20;
       median2=20;
}

void setup(){

pinMode(trigPin1, OUTPUT); // Sets the trigPin1 as an Output
pinMode(trigPin2, OUTPUT); // Sets the trigPin2 as an Output
pinMode(13, OUTPUT); 
pinMode(echoPin1, INPUT); // Sets the echoPin1 as an Input
pinMode(echoPin2, INPUT); // Sets the echoPin2 as an Input
Serial.begin(1152000); // Starts the serial communication

}

void loop(){
  
  if(!initial){
    startfun();
  }
  if(start!=-1){
    Serial.setTimeout(50);
    distancecal();
  
    if(!median1&&!median2){
      Data_array1[i]=distance1;
      Data_array2[i]=distance2;
      i++;
      
      if(i>100){
        initialdata();  
        i=0; 
      }
    }
    
    else{
      digitalWrite(13,LOW);
      if(distance1<median1){
        //Transmit data
        Serial.println(String(distance1)+'1'+String(i));
        delay(10);  
        i++;
      }
      if(distance2<median2){
        //Transmit data
        Serial.println(String(distance2)+'2'+String(i));
        delay(10);
        i++;
      }
    }
  }
}


  
