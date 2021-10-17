#include <MPU9250_asukiaaa.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bme; // I2C
MPU9250_asukiaaa mySensor;
float aX, aY, aZ, aSqrt, gX, gY, gZ, mDirection, mX, mY, mZ;

void setup() {
  Serial.begin(9600);
  while (!Serial);

#ifdef _ESP32_HAL_I2C_H_ // For ESP32
  //Wire.begin(SDA_PIN, SCL_PIN);
  Wire.begin(SDA_PIN, SCL_PIN);
  mySensor.setWire(&Wire);
#endif

  bme.begin();
  mySensor.beginAccel();
  mySensor.beginGyro();
  mySensor.beginMag();

  // You can set your own offset for mag values
  // mySensor.magXOffset = -50;
  // mySensor.magYOffset = -55;
  // mySensor.magZOffset = -10;
}


float readData( String sensor ){
    int pin = 0;
    bool analog = true;
    switch(toupper( sensor[0] )){
      case 'N':   //NTC
        pin = 0;
        break;
      case 'M':    //MPX4115
        pin = 1;
        break;
      case 'L':    //LM335 (Needs a different conversation factor?)
        pin = 5;
        break;
    }
    /*
    Serial.print( "pin: " );
    Serial.print( pin );
    Serial.print( " " );
    */
    if (analog){
      return (float)analogRead( pin )*5/1023;
    }
}

void loop() {

  //Serial.print( millis() );
  //delay( 1000 );
  if (mySensor.accelUpdate() == 0) {

    Serial.print( millis() );
    Serial.print(" ");
    Serial.print( readData( "NTC" ));
    Serial.print(" ");
    Serial.print( readData( "MPX4115" ));
    Serial.print(" ");
    Serial.print( readData( "L" ));
    Serial.print(" ");

    aX = mySensor.accelX();
    aY = mySensor.accelY();
    aZ = mySensor.accelZ();
    Serial.print(aX);
  Serial.print(" ");
    Serial.print(aY);
  Serial.print(" ");
    Serial.print(aZ);
  Serial.println(" ");
  
  }
/*
  if (mySensor.gyroUpdate() == 0) {
    gX = mySensor.gyroX();
    gY = mySensor.gyroY();
    gZ = mySensor.gyroZ();
    Serial.print("\tgyroX: " + String(gX));
    Serial.print("\tgyroY: " + String(gY));
    Serial.print("\tgyroZ: " + String(gZ));
  }

  if (mySensor.magUpdate() == 0) {
    mX = mySensor.magX();
    mY = mySensor.magY();
    mZ = mySensor.magZ();
    mDirection = mySensor.magHorizDirection();
    Serial.print("\tmagX: " + String(mX));
    Serial.print("\tmaxY: " + String(mY));
    Serial.print("\tmagZ: " + String(mZ));
    Serial.print("\thorizontalDirection: " + String(mDirection));
  }

  Serial.print("\tTemperature(*C): ");
  Serial.print(bme.readTemperature());

  Serial.print("\tPressure(Inches(Hg)): ");
  Serial.print(bme.readPressure()/3377);


  Serial.print("\tApproxAltitude(m): ");
  Serial.print(bme.readAltitude(1013.25)); // this should be adjusted to your local forcase

*/
  
  }
