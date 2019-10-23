/*Including libraries
 * The libraries include the code to make using the sensors easy!
 * By including them we can use the sensors with only a few lines of code. 
 */
 
#include <Wire.h>
#include "Adafruit_SI1145.h" //Include the library

//This line creates an object to represent the sensor.
//If we want to get information from the sensor we need to use this object.
//Have a look now through the rest of the code and see where you can find the uv
//object being used...
Adafruit_SI1145 uv = Adafruit_SI1145();

void setup() {
  Serial.begin(9600); //Start Serial communication  

  //Now we check to see if the UV sensor is there or not...
  if (! uv.begin()) {
    Serial.println("Didn't find Si1145");
    while (1);
  }
}

void loop() {

  //First we store the values of the sensors in variables
  int visibleLight = uv.readVisible();
  int IRLight = uv.readIR();
  float UVindex = uv.readUV();

  // the index is multiplied by 100 so to get the
  // integer index, divide by 100!
  UVindex = UVindex/100.0;  

  //Now we print the values that we have stored in out variables.
  Serial.println("===================");
  Serial.print("Vis: "); Serial.println(visibleLight);
  Serial.print("IR: "); Serial.println(IRLight);
  Serial.print("UV: ");  Serial.println(UVindex);

  //Wait for 1 sec. 
  delay(1000);
}
