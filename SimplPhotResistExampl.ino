  #define PR  A5  //PR- Photo resistor
  int Pi = 0;    //PI- Photo index
  #define R_L  7   //Red led, number refers to connected pin
  #define Y_L  6   //Yellow led
  #define G_L  5   //Green led
  int T = 0;     //just to count loops
  int Td = 0;    //another one
void setup() {
  // put your setup code here, to run once:


  Serial.begin(2400); 
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A5, INPUT);
  pinMode(R_L, OUTPUT);
  pinMode(Y_L, OUTPUT);
  pinMode(G_L, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Pi = analogRead(A5);
  Td = T % 2; //next part will run each 2nd loop, change number to increase or decrease frequency
  if(Td == 0){
// 
    if(Pi<= 1000){digitalWrite(LED_BUILTIN, HIGH);} //decrease values to increase level of light needed to light these leds
    else{digitalWrite(LED_BUILTIN, LOW);}
    if(Pi<= 960){digitalWrite(R_L, HIGH);}
    else{digitalWrite(R_L, LOW);}
    if(Pi<= 945){digitalWrite(Y_L, HIGH);}
    else{digitalWrite(Y_L, LOW);}
    if(Pi<= 930){digitalWrite(G_L,HIGH);}
    else{digitalWrite(G_L, LOW);}

  }
  Serial.println(Pi); //this shows us level of light in serial monitor, 1024 refers to minimal light level(dark), 0 refers to maximal light level
  //delay(500); //delay between loops, divide by 'number in 25th string' your needed delay and write here 
  T+=1; //this is here to count loops / used in 25th string
}
