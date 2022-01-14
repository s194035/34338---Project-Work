//include libraries
#include "DHT.h"

//define pins
#define stepper1 2
#define stepper2 3
#define stepper3 4
#define stepper4 5
#define DHTPIN_in 6
#define DHTPIN_out 7
#define relay 8
#define butPin 9
#define ACPin 10
bool windowClosed = true;


//setup for stepper and temperature sensor
#define DHTTYPE DHT11
#define NUMBER_OF_STEPS_PER_REV 512
DHT dht_in(DHTPIN_in, DHTTYPE);
DHT dht_out(DHTPIN_out, DHTTYPE);


void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("System ON");
  
  //initalize temperature sensors
  dht_in.begin();
  dht_out.begin();
  
  //define pin modes for stepper and AC pin
  pinMode(stepper1, OUTPUT);
  pinMode(stepper2, OUTPUT);
  pinMode(stepper3, OUTPUT);
  pinMode(stepper4, OUTPUT);
  pinMode(ACPin, OUTPUT);
}




void loop() {

  //State 1: Warmer outside + 3 degrees then inside. AC off, fan on, windows open
  if (temp__in() < temp__out() + 3) {
    AC_off(); 
    relay_high(); //relay to control fan
    
    if (windowClosed == true) { //checking if the windows are already closed or not
      windowClosed = false;    
      for (int i = 0; i < 512; i++) { //512 is the number of steps. Would need to be adjusted for each window.
        onestep_cw(); //turning window stepper motor clockwise
      }
    }
  }
  delay(500);

  //State 2: Warmer inside than outside + 3 degrees. AC on, fan off, windows closed
  else if (temp__in() > temp__out() + 3) {
    AC_on();
    relay_low();
    if (windowClosed == false) {
      windowClose = true;
      for (int i = 0; i < 512; i++) {
        onestep_ccw();
      }
    }
  }
  delay(500);

  //State 3: 

  
  
}
