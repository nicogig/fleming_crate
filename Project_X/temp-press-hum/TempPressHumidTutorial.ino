/*Including libraries
 * The libraries include the code to make using the sensors easy!
 * By including them we can use the sensors with only a few lines of code. 
 */
#include <Adafruit_BME280.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

//These are settings for the board. 
//We will not changes these. 
#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

//This line creates an object to represent the sensor.
//If we want to get information from the sensor we need to use this object.
//Have a look now through the rest of the code and see where you can find the bme
//object being used...
Adafruit_BME280 bme; // I2C

void setup() {
    Serial.begin(9600);//Start the serial communication

    //Check whether the sensor is connected correctly
    if (!bme.begin()) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1);
    }

    Serial.println();
}


void loop() { 
  //We start by storing the sensor values in variables
  float temp = bme.readTemperature();
  float pressure = bme.readPressure()/100.0;
  float humidity = bme.readHumidity();

  //Now we will print each of the values that we have read
  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" hPa");
  
  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.println();
  //Wait one second
  delay(1000);
}
