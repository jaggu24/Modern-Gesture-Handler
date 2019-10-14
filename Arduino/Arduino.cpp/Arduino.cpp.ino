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


int mean1=0,mean2=0;
String m1,m2;
bool initial=false,flag=false;
int i=0,o=0;
long duration1;
long duration2;
int distance1;
int distance2;
int start=-1;
int Data_array1[100],Data_array2[100];

void setup(){

pinMode(trigPin1, OUTPUT); // Sets the trigPin1 as an Output
pinMode(trigPin2, OUTPUT); // Sets the trigPin2 as an Output
pinMode(13, OUTPUT); 
pinMode(echoPin1, INPUT); // Sets the echoPin1 as an Input
pinMode(echoPin2, INPUT); // Sets the echoPin2 as an Input
Serial.begin(115200); // Starts the serial communication

}

void startfun(){
  if (Serial.available() > 0 ) {    //Start the Data input 
    start = Serial.read()-48;
    digitalWrite(13,HIGH);
  }
}
void meancal(){
  if(mean1&&mean2){
       mean1=(m1[0]-48)*10+(m1[1]-48);
       mean2=(m2[0]-48)*10+(m2[1]-48);
//       Serial.println("knkjnj"+m1);
  //     delay(1000);
//       Serial.println("knkddsds"+m2);
       
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

void normaldata(){
  
      if(distance1<mean1){
        Data_array1[i]=distance1;    
        if(distance2<mean2){
          Data_array2[i]=distance2;
        }
        else{
          Data_array2[i]=0;
        }
      }
      else{
        Data_array2[i]=distance2;
        Data_array1[i]=0;
      }   
    
}

void initialdata(){
  
       digitalWrite(13,HIGH);
       for(int m=0;m<i;m++){
         delay(10);
         Serial.println(Data_array1[m]);
         delay(10);
         Serial.println(Data_array2[m]);
       }
      i=0;
      o++;
      if(o==3){
        initial=true;
      
    }
}

void meanreceive(){
  if (Serial.available() > 0 && !mean1 && !mean2) {    //Start the Data input 
        digitalWrite(13,HIGH);
        m1 = Serial.read();
        mean1=1;
        delay(1);
        m2 = Serial.read(); 
         mean2=1;
         if(mean1)
         initial=false;
      }
          
}
void loop(){
  
  if(!initial&&!mean1&&!mean2){
    startfun();
  }
  
  if(start==1){
    distancecal();
    if(mean1&&mean2&&!flag){
      digitalWrite(13,LOW);
      Serial.println(m1+m2+"hfkjdhfjdsgj");
//      meancal();
//      flag=true;
//     Serial.println(m1+"ljkfjklj"+m2+"kjgfjhvjh");
    }
    
    if(!mean1&&!mean2){

      Data_array1[i]=distance1;
      Data_array2[i]=distance2;
      i++;
    }
    
    

    if(i>100&&!mean1&&!mean2){
     initialdata();   
    }
    
    if(initial){
       meanreceive();
    }
  }
}
  
