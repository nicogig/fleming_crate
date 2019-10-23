//Tutorial code for microphone
void setup() {
  //We must set our analogue pin to be an input
  pinMode(A0, INPUT);

  //Start the serial so we can print the output
  Serial.begin(9600); 
}

void loop() {
  //First we store the value from the microphone into a variable
  int soundLevel = analogRead(A0);

  //Finally we can print the microphone signal
  Serial.println(soundLevel);
  
  //Wait a bit before the next reading
  delay(250);  
}
