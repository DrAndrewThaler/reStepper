 /*
 
 Rotary encoder source code from bildr article: http://bildr.org/2012/08/rotary-encoder-arduino/
 
 LiquidCrystal pinout:
 
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 10
 * LCD D5 pin to digital pin 9
 * LCD D6 pin to digital pin 8
 * LCD D7 pin to digital pin 7
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay

 */

#include <LiquidCrystal.h> //LCD Library
#include <Servo.h> //Servo library

Servo myservo; //initiates servo

LiquidCrystal lcd(12, 11, 10, 9, 8, 7); //output pins for LCD

int pos = 0;    // variable to store the servo position

int encoderPin1 = 2; // pin 1 of the digital encoder
int encoderPin2 = 3; // pin 2 od the digital encoder
int encoderSwitchPin = 4; //push button switch for the digital encoder

volatile int lastEncoded = 0; //digital encoder variable
volatile long encoderValue = 0; //digital encoder variable
long lastencoderValue = 0; //digital encoder variable
int lastMSB = 0; //digital encoder variable
int lastLSB = 0; //digital encoder variable

int readPin = 6; //reads pin 6 for multiplier switch
int val; //value from read pin
int multiplier; //multiplier that converts calorie count to step count; use 11 for men, 16 for women

int calories; //calorie count variable
int steps; //step count variable

void setup() {

  Serial.begin (9600);

  pinMode(encoderPin1, INPUT);
  pinMode(encoderPin2, INPUT);

  pinMode(encoderSwitchPin, INPUT);

  digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
  digitalWrite(encoderPin2, HIGH); //turn pullup resistor on

  digitalWrite(encoderSwitchPin, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3)

  attachInterrupt(0, updateEncoder, CHANGE);
  attachInterrupt(1, updateEncoder, CHANGE);

  myservo.attach(5);  //attaches the servo on pin 9 to the servo object

  lcd.begin(16, 2);  //set up the LCD's number of columns and rows:

  pinMode(readPin, INPUT);
  
}

void loop(){

  val = digitalRead(readPin); //reads multiplier switch

  if(val == HIGH){ //sets multiplier female if cricuit is complete
    
    multiplier = 16;
    
  } else { //sets multiplier to male if circuit is grounded

    multiplier = 11;
    
  }

  if(encoderValue < 0) { //prevents calories count from being negative

    encoderValue = 0;
    
  } 
  
  calories = (encoderValue/4)*10; //converts encoder value to calories in units of 10


  lcd.clear();
  lcd.print("Calories: ");
  lcd.print(calories); //displays calories count on the LCD

  steps = calories*multiplier; //converts calorie count to number of swings
 

  if(digitalRead(encoderSwitchPin)){ //button is not being pushed, nothing happens

  }
  
  else{ //button is being pushed; all the servo action happens here

    while(steps > 0){

      for (pos = 0; pos <= 180; pos += 5) { // goes from 0 degrees to 180 degrees
  
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(20);                       // pause at crest of arc

      }
    
      for (pos = 180; pos >= 0; pos -= 5) { // goes from 180 degrees to 0 degrees
      
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(20);                       // pause at crest of arc
    
      }
      
      steps = steps - 2; //reduces step count by 2
      
      lcd.clear();
      lcd.print("Steps left: ");
      lcd.print(steps); //prints number of steps remaining

    }
    
  }
 
  delay(100);
  
}

void updateEncoder(){
  
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number 
  int sum = (lastEncoded << 2) | encoded; //adding it to the previous encoded value 
  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++; 
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --; 
  
  lastEncoded = encoded; //store this value for next time 

}
