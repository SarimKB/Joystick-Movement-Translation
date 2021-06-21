//Defining pins
#define SW_PIN 2
#define X_PIN 0
#define Y_PIN 1


//PROMISES:
//        - Returns an int value that corresponds to a direction/position on the analog joystick.
//        - The guide for the return values corresponding to the position of the joystick is as follows:
//            0 : Up Left
//            1 : Up
//            2 : Up Right
//            3 : Right
//            4 : Down Right
//            5 : Down
//            6 : Down Left
//            7 : Left
//            8 : Centre
//REQUIRES:
//        - The joystick is held in such a way that it is facing the user and the pins of the Arduino face the left.
//        - Two positive analog numbers within the range of approximately 0 to 1023.
int FindJoystickCoordinate(int x_c, int y_c){

  //If the joystick is pushed up in any way
  if(y_c >= 0 && y_c <= 100){
    if (x_c == 0){
      return 0;   //Up Left
    }
    else if (x_c > 250 && x_c < 525){
      return 1;   //Up
    }
    else{
      return 2;   //Up Right
    }
  }

  //If the joystick is pushed down in any way
  else if(y_c >= 900){
    if (x_c == 0){
      return 6;   //Down Left
    }
    else if (x_c > 250 && x_c < 525){
      return 5;   //Down
    }
    else{
      return 4;   //Down Right
    }
  }

  //If the joystick is pushed either left, right or is in the centre
  else{
    if (x_c == 0){
      return 7;   //Left
    }
    else if (x_c > 250 && x_c < 525){
      return 8;   //Centre
    }
    else{
      return 3;   //Right
    }
  }
  
}


void setup() {
  
  pinMode(SW_PIN, INPUT);
  digitalWrite(SW_PIN, HIGH);
  Serial.begin(9600);

}

void loop() {

  //Reading the joystick coordinates
  int X_val = analogRead(X_PIN);
  int Y_val = analogRead(Y_PIN);

  int InputCoor = FindJoystickCoordinate(X_val, Y_val);

  switch(InputCoor){
    case 0:
      Serial.print("Direction: ");
      Serial.print("Up Left\n\n");
      break;
    case 1:
      Serial.print("Direction: ");
      Serial.print("Up\n\n");
      break;
    case 2:
      Serial.print("Direction: ");
      Serial.print("Up Right\n\n");
      break;
    case 3:
      Serial.print("Direction: ");
      Serial.print("Right\n\n");
      break;
    case 4:
      Serial.print("Direction: ");
      Serial.print("Down Right\n\n");
      break;
    case 5:
      Serial.print("Direction: ");
      Serial.print("Down\n\n");
      break;
    case 6:
      Serial.print("Direction: ");
      Serial.print("Down Left\n\n");
      break;
    case 7:
      Serial.print("Direction: ");
      Serial.print("Left\n\n");
      break;
    case 8:
      Serial.print("Direction: ");
      Serial.print("Centre\n\n");
      break;
    
  }

  delay(1000);
  
}
