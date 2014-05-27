/*
stair light fade controller for detecting pir inputs (or any input really) and softly fading lights on or off according to a countdown.

roughly based on arduino "fade" example code.

Created by; Marshall Scholz
 */

const int led = 5;           // the pin that the LED is attached to
const int sensor1 = A1;
const int sensor2 = A2;
const int sensorL = A0;

int brightness = 250;    // how bright the LED is
int lightgoal = 0;
int maxbrightness =252; 
const int upfadeAmount = 4;    // how many points to fade the LED by
const int dnfadeAmount = 2;    // how many points to fade the LED by

int timer = 100;




// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  
  pinMode(sensor1, INPUT); // declare sensorpins as inputs
  pinMode(sensor2, INPUT);
  
} 

// the loop routine runs over and over again forever:
void loop()  { 
  
  if (digitalRead(sensor1) == HIGH || digitalRead(sensor2) == HIGH) { // detect if either sensor triggered
    
    timer = 150; // every increment adds about a tenth of a second
    lightgoal = maxbrightness; // set lights to turn on
  //if (brightness == 0){ brightness = 1;}
    
  }
  
  /// light brightness / fading section
  if(brightness == lightgoal){ // is the brightness where we want it?
    
    if (timer == 0){
     lightgoal = 0;
    } 
    
    delay(100); // finctioning delay in timer, not very percise
    timer = timer - 1; //countdown the timer with every loop

  
  }else{
   
    if(brightness < lightgoal){ // is the brightness too low?

      // raise the brightness
      brightness = brightness + upfadeAmount;

    }else { // if the light isn't too low, it's too high
    
      // lower the brightness
      brightness = brightness - dnfadeAmount;
      
    }  
    
    // set the brightness (pwm duty cycle) of led
  analogWrite(led, brightness);  
  
  // wait for 30 milliseconds to see the dimming effect    
  delay(25); 
    
  }
  
}

