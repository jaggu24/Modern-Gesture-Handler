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
    median1=median2=40;
}

void initialdata(){
  
       digitalWrite(13,HIGH);

       median1=kthSmallest(Data_array1, 0, 100, 50);

       median2=kthSmallest(Data_array2, 0, 100, 50);
       
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
        Serial.println(String(distance1)+String('1'));
        delay(10);  
        Serial.flush();
      }
      if(distance2<median2){
        //Transmit data
        Serial.println(String(distance2)+String('2'));
//        delay(10);
        Serial.flush();
        
      }
    }
  }
}

void merge(int arr[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1+ j];
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = l; // Initial index of merged subarray
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int m = l+(r-l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    merge(arr, l, m, r);
  }
}

int partition(int arr[], int l, int r, int k);
int findMedian(int arr[], int n)
{
  mergeSort(arr,0,n-1);
  return arr[n/2];
}
int kthSmallest(int arr[], int l, int r, int k)
{
  if (k > 0 && k <= r - l + 1)
  {
    int n = r-l+1;
    int i, median[(n+4)/5];
    for (i=0; i<n/5; i++)
      median[i] = findMedian(arr+l+i*5, 5);
    if (i*5 < n)
    {
      median[i] = findMedian(arr+l+i*5, n%5);
      i++;
    }
    int medOfMed = (i == 1)? median[i-1]:
                kthSmallest(median, 0, i-1, i/2);
    int pos = partition(arr, l, r, medOfMed);
    if (pos-l == k-1)
      return arr[pos];
    if (pos-l > k-1)
      return kthSmallest(arr, l, pos-1, k);
    return kthSmallest(arr, pos+1, r, k-pos+l-1);
  }
  return 1000000;
}
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
int partition(int arr[], int l, int r, int x)
{
    int i;
  for (i=l; i<r; i++)
    if (arr[i] == x)
    break;
  swap(&arr[i], &arr[r]);
  i = l;
  for (int j = l; j <= r - 1; j++)
  {
    if (arr[j] <= x)
    {
      swap(&arr[i], &arr[j]);
      i++;
    }
  }
  swap(&arr[i], &arr[r]);
  return i;
}

  
