const int xInput = A0;
const int yInput = A1;
const int zInput = A2;

void setup() {
  analogReference(EXTERNAL);
  pinMode(xInput, INPUT);
  pinMode(yInput, INPUT);
  pinMode(zInput, INPUT);
  Serial.begin(9600);
}

void loop() {
  long xReading = analogRead(xInput);
  long yReading = analogRead(yInput);
  long zReading = analogRead(zInput);
  Serial.print("X Axis: ");
  Serial.print(xReading);
  Serial.print(" Y Axis: ");
  Serial.print(yReading);
  Serial.print(" Z Axis: ");
  Serial.println(zReading);
  delay(250); // makes reading the output easier.
  
}
