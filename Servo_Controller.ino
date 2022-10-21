// Control six servos using toggle switches

const int button_1 = A0;
const int button_2 = A1;
const int button_3 = A2;
const int button_4 = A3;
const int button_5 = A4;
const int button_6 = A5;

int start1=25;
int stop1=65;
int pos = 0;    // variable to store the servo position

#include <Servo.h>

Servo myservo_1;  // create servo object to control a servo
Servo myservo_2;
Servo myservo_3;
Servo myservo_4;
Servo myservo_5;
Servo myservo_6;

void setup () {
  
Serial.begin(9600);
myservo_1.attach(3);
myservo_2.attach(5);
myservo_3.attach(6);
myservo_4.attach(9);
myservo_5.attach(10);
myservo_6.attach(11);
pinMode(13, OUTPUT);

}

 enum SWITCHSTATES
  {
    ST_OFF1,
    ST_OFF2,
    ST_STRAIGHT,
    ST_TURN,
  };
  
  SWITCHSTATES switchState_1 = ST_OFF1;
  SWITCHSTATES switchState_2 = ST_OFF1;
  SWITCHSTATES switchState_3 = ST_OFF1;
  SWITCHSTATES switchState_4 = ST_OFF1;
  SWITCHSTATES switchState_5 = ST_OFF1;
  SWITCHSTATES switchState_6 = ST_OFF1;


  void loop() {


   
    int buttonRead_1 = analogRead(button_1);
    int buttonRead_2 = analogRead(button_2);
    int buttonRead_3 = analogRead(button_3);
    int buttonRead_4 = analogRead(button_4);
    int buttonRead_5 = analogRead(button_5);
    int buttonRead_6 = analogRead(button_6);
    
    delay(20);
    
    switch (switchState_1)
    {
      case ST_OFF1:
        switchoff1_1(buttonRead_1); //sets up changes to ST_OFF1
        break;
      case ST_OFF2:
        switchoff2_1(buttonRead_1); //sets up changes to ST_OFF2
        break;
      case ST_STRAIGHT:
        switchstraight_1(buttonRead_1); //sets up changes to ST_STRAIGHT
        break;
      case ST_TURN:
        switchturn_1(buttonRead_1); // sets up changes to ST_TURN
        break;
    }
        
    switch (switchState_2)
    {
      case ST_OFF1:
        switchoff1_2(buttonRead_2); //sets up changes to ST_OFF1
        break;
      case ST_OFF2:
        switchoff2_2(buttonRead_2); //sets up changes to ST_OFF2
        break;
      case ST_STRAIGHT:
        switchstraight_2(buttonRead_2); //sets up changes to ST_STRAIGHT
        break;
      case ST_TURN:
        switchturn_2(buttonRead_2); // sets up changes to ST_TURN
        break;
    }

        
    switch (switchState_3)
    {
      case ST_OFF1:
        switchoff1_3(buttonRead_3); //sets up changes to ST_OFF1
        break;
      case ST_OFF2:
        switchoff2_3(buttonRead_3); //sets up changes to ST_OFF2
        break;
      case ST_STRAIGHT:
        switchstraight_3(buttonRead_3); //sets up changes to ST_STRAIGHT
        break;
      case ST_TURN:
        switchturn_3(buttonRead_3); // sets up changes to ST_TURN
        break;
    }

        
    switch (switchState_4)
    {
      case ST_OFF1:
        switchoff1_4(buttonRead_4); //sets up changes to ST_OFF1
        break;
      case ST_OFF2:
        switchoff2_4(buttonRead_4); //sets up changes to ST_OFF2
        break;
      case ST_STRAIGHT:
        switchstraight_4(buttonRead_4); //sets up changes to ST_STRAIGHT
        break;
      case ST_TURN:
        switchturn_4(buttonRead_4); // sets up changes to ST_TURN
        break;
    }

           
    switch (switchState_5)
    {
      case ST_OFF1:
        switchoff1_5(buttonRead_5); //sets up changes to ST_OFF1
        break;
      case ST_OFF2:
        switchoff2_5(buttonRead_5); //sets up changes to ST_OFF2
        break;
      case ST_STRAIGHT:
        switchstraight_5(buttonRead_5); //sets up changes to ST_STRAIGHT
        break;
      case ST_TURN:
        switchturn_5(buttonRead_5); // sets up changes to ST_TURN
        break;
    }

        
    switch (switchState_6)
    {
      case ST_OFF1:
        switchoff1_6(buttonRead_6); //sets up changes to ST_OFF1
        break;
      case ST_OFF2:
        switchoff2_6(buttonRead_6); //sets up changes to ST_OFF2
        break;
      case ST_STRAIGHT:
        switchstraight_6(buttonRead_6); //sets up changes to ST_STRAIGHT
        break;
      case ST_TURN:
        switchturn_6(buttonRead_6); // sets up changes to ST_TURN
        break;
    }



  }

//
// Four states for Servo 1
//
  void switchoff1_1(int buttonRead) {
    myservo_1.write(start1);
    if (buttonRead > 500) {
      switchState_1 = ST_TURN; //switches to different state
    }
  }
  void switchturn_1(int buttonRead) {
    for (pos = start1; pos <= stop1; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo_1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    switchState_1 = ST_OFF2; //chages to ST_OFF2
  }
  void switchoff2_1(int buttonRead) {
    myservo_1.write(stop1);
    if (buttonRead < 500) {
      switchState_1 = ST_STRAIGHT; //switches to Straight
    }
  }
  void switchstraight_1(int buttonRead) {
    for (pos = stop1; pos >= start1; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo_1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
      switchState_1 = ST_OFF1; //chages to ST_OFF1
    }
  }

 
//
// Four states for Servo 2
//
  void switchoff1_2(int buttonRead) {
    myservo_2.write(start1);
    if (buttonRead > 500) {
      switchState_2 = ST_TURN; //switches to different state
    }
  }
  void switchturn_2(int buttonRead) {
    for (pos = start1; pos <= stop1; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo_2.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    switchState_2 = ST_OFF2; //chages to ST_OFF2
  }
  void switchoff2_2(int buttonRead) {
    myservo_2.write(stop1);
    if (buttonRead < 500) {
      switchState_2 = ST_STRAIGHT; //switches to Straight
    }
  }
  void switchstraight_2(int buttonRead) {
    for (pos = stop1; pos >= start1; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo_2.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
      switchState_2 = ST_OFF1; //chages to ST_OFF1
    }
  }

//
// Four states for Servo 3
//
  void switchoff1_3(int buttonRead) {
    myservo_3.write(start1);
    if (buttonRead > 500) {
      switchState_3 = ST_TURN; //switches to different state
    }
  }
  void switchturn_3(int buttonRead) {
    for (pos = start1; pos <= stop1; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo_3.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    switchState_3 = ST_OFF2; //chages to ST_OFF2
  }
  void switchoff2_3(int buttonRead) {
    myservo_3.write(stop1);
    if (buttonRead < 500) {
      switchState_3 = ST_STRAIGHT; //switches to Straight
    }
  }
  void switchstraight_3(int buttonRead) {
    for (pos = stop1; pos >= start1; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo_3.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
      switchState_3 = ST_OFF1; //chages to ST_OFF1
    }
  }

//
// Four states for Servo 4
//
  void switchoff1_4(int buttonRead) {
    myservo_4.write(start1);
    if (buttonRead > 500) {
      switchState_4 = ST_TURN; //switches to different state
    }
  }
  void switchturn_4(int buttonRead) {
    for (pos = start1; pos <= stop1; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo_4.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    switchState_4 = ST_OFF2; //chages to ST_OFF2
  }
  void switchoff2_4(int buttonRead) {
    myservo_4.write(stop1);
    if (buttonRead < 500) {
      switchState_4 = ST_STRAIGHT; //switches to Straight
    }
  }
  void switchstraight_4(int buttonRead) {
    for (pos = stop1; pos >= start1; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo_4.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
      switchState_4 = ST_OFF1; //chages to ST_OFF1
    }
  }

 //
// Four states for Servo 5
//
  void switchoff1_5(int buttonRead) {
    myservo_5.write(start1);
    if (buttonRead > 500) {
      switchState_5 = ST_TURN; //switches to different state
    }
  }
  void switchturn_5(int buttonRead) {
    for (pos = start1; pos <= stop1; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo_5.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    switchState_5 = ST_OFF2; //chages to ST_OFF2
  }
  void switchoff2_5(int buttonRead) {
    myservo_5.write(stop1);
    if (buttonRead < 500) {
      switchState_5 = ST_STRAIGHT; //switches to Straight
    }
  }
  void switchstraight_5(int buttonRead) {
    for (pos = stop1; pos >= start1; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo_5.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
      switchState_5 = ST_OFF1; //chages to ST_OFF1
    }
  }

//
// Four states for Servo 6
//
  void switchoff1_6(int buttonRead) {
    myservo_6.write(start1);
    if (buttonRead > 500) {
      switchState_6 = ST_TURN; //switches to different state
    }
  }
  void switchturn_6(int buttonRead) {
    for (pos = start1; pos <= stop1; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo_6.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    switchState_6 = ST_OFF2; //chages to ST_OFF2
  }
  void switchoff2_6(int buttonRead) {
    myservo_6.write(stop1);
    if (buttonRead < 500) {
      switchState_6 = ST_STRAIGHT; //switches to Straight
    }
  }
  void switchstraight_6(int buttonRead) {
    for (pos = stop1; pos >= start1; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo_6.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
      switchState_6 = ST_OFF1; //chages to ST_OFF1
    }
  }
