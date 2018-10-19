const int stepPin1 = 5; //SLIDER EVEN
const int dirPin1 = 6; 
const int enPin1 = 7;

const int stepPin2 = 23; //SLIDER ODD
const int dirPin2 = 25; 
const int enPin2 = 27;

const int stepPin3 = 22; //180 ROTATE STEPPER
const int dirPin3 = 24; 
const int enPin3 = 26;

const int stepPin4 = 2; //BIG MOTOR 
const int dirPin4 = 3; 
const int enPin4 = 4;

#include <Keypad.h>
#include <Stepper.h> 
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

/*-------------------------------KEYPAD---------------------------------------*/
const byte numRows= 8; //number of rows on the keypad
const byte numCols= 8; //number of columns on the keypad
char keypressed;
char keymap[numRows][numCols]=
{
{'1','2','3','A','E','I','M','Q'},
{'4','5','6','B','F','J','N','R'},
{'7','8','9','C','G','K','O','S'},
{'*','0','#','D','H','L','P','T'},
{'U','Y','c','g','k','o','s','w'},
{'V','Z','d','h','l','p','t','x'},
{'W','a','e','i','m','q','u','y'},
{'X','b','f','j','n','r','v','z'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = { 69, 68, 67, 66,61, 60, 59, 58};//Rows 0 to 3
byte colPins[numCols] = {65, 64, 63, 62,57, 56, 55, 54 };//Columns 0 to 3             
//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup() {
 // put your setup code here, to run once:
Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print(" Smart Parking ");
  // Sets the two pins as Outputs
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  pinMode(enPin1,OUTPUT);
  digitalWrite(enPin1,LOW);

  pinMode(stepPin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);
  pinMode(enPin2,OUTPUT);
  digitalWrite(enPin2,LOW);

  pinMode(stepPin3,OUTPUT); 
  pinMode(dirPin3,OUTPUT);
  pinMode(enPin3,OUTPUT);
  digitalWrite(enPin3,LOW);

  pinMode(stepPin4,OUTPUT); 
  pinMode(dirPin4,OUTPUT);
  pinMode(enPin4,OUTPUT);
  digitalWrite(enPin4,LOW);

}

void loop() {


   keypressed = myKeypad.getKey();   //Read pressed keys
      if ( keypressed == '1'  )
      {
        park1();
      }
      if ( keypressed == '2'  )
      {
        park2();
      }
       if ( keypressed == '3'  )
      {
        park3();
     }
       if ( keypressed == 'A'  )
       {
      park4();
       }
       if ( keypressed == '4'  )
      {
        park5();
      }
       if ( keypressed == '5'  )
      {
        park6();
      }
       if ( keypressed == '6'  )
      {
        park7();
      }
       if ( keypressed == 'B'  )
      {
        park8();
      }
          if ( keypressed == '7'  )
      {
        park9();
      }
      if ( keypressed == '8'  )
      {
        park10();
      }
       if ( keypressed == '9'  )
      {
        park11();
     }
       if ( keypressed == 'C'  )
       {
      park12();
       }
       if ( keypressed == '*'  )
      {
        park13();
      }
       if ( keypressed == '0'  )
      {
        park14();
      }
       if ( keypressed == '#'  )
      {
        park15();
      }
       if ( keypressed == 'D'  )
      {
        park16();
      }
      //////////////////////////////////////////
      if ( keypressed == 'k'  )
      {
        get1();
      }
      if ( keypressed == 'o'  )
      {
        get2();
      }
       if ( keypressed == 's'  )
      {
        get3();
      }
      if ( keypressed == 'w'  )
      {
        get4();
      }
      if ( keypressed == 'l'  )
      {
        get5();
      }
      if ( keypressed == 'p'  )
      {
        get6();
      }
      if ( keypressed == 't'  )
      {
        get7();
      }
      if ( keypressed == 'x'  )
      {
        get8();
      }
 if ( keypressed == 'm'  )
      {
        get9();
      }
      if ( keypressed == 'q'  )
      {
        get10();
      }
       if ( keypressed == 'u'  )
      {
        get11();
      }
      if ( keypressed == 'y'  )
      {
        get12();
      }
      if ( keypressed == 'n'  )
      {
        get13();
      }
      if ( keypressed == 'r'  )
      {
        get14();
      }
      if ( keypressed == 'v'  )
      {
        get15();
      }
      if ( keypressed == 'z'  )
      {
        get16();
      }

       
}
/////////////////////////////////////////////ODD cell parking///////////////////////////////////////11111111111111111111111///////////////
void park1()
{
  //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 11000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in
digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 850; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Nice namo
digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Slide out
   digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 850; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo
 digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 9000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
  lcd.setCursor(0, 1);
  lcd.print("Park at 1st cell");
}

void get1()
{
  //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 9000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in
   digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 850; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//Slide out
   digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 85o0o0; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 11000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  lcd.setCursor(0, 1);
  lcd.print("Geting from 1st");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////333333333333333333333///////////////////////////
void park3()
{
  //rotate koro

   digitalWrite(dirPin3,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
   //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 11000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in
   digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Nice namo
  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Slide out
   digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo
  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 9000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
    //rotate koro
   digitalWrite(dirPin3,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

    lcd.setCursor(0, 1);
  lcd.print("Park at 3rd cell");

}
void get3()
{
  //rotate koro

   digitalWrite(dirPin3,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
   //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 9000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

   //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//Slide out
   digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 11000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

    //rotate koro
   digitalWrite(dirPin3,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  lcd.setCursor(0, 1);
  lcd.print("Geting from 3rd");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////55555555555555555
void park5()
{
   //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 22000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Slide out
   digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 20000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay 

    lcd.setCursor(0, 1);
  lcd.print("Park at 5th cell");
}
void get5()
{
    //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 20000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//Slide out
   digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 22000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  lcd.setCursor(0, 1);
  lcd.print("Geting from 5th");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7777777777777777777777777777777777777777
void park7()
{
   //rotate koro

   digitalWrite(dirPin3,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
   //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 22000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Slide out
   digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 20000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

    //rotate koro
   digitalWrite(dirPin3,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

    lcd.setCursor(0, 1);
  lcd.print("Park at 7th cell");
}
void get7()
{
  //rotate koro

   digitalWrite(dirPin3,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
   //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 20000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

   //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//Slide out
   digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 22000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

    //rotate koro
   digitalWrite(dirPin3,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay 

  lcd.setCursor(0, 1);
  lcd.print("Geting from 7th");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////999999999999999999999999999999999999
void park9()
{
   //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 33000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Slide out
   digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 31000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
    
    lcd.setCursor(0, 1);
  lcd.print("Park at 9th cell");

}
void get9()
{
   //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 31000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//Slide out
   digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 33000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  lcd.setCursor(0, 1);
  lcd.print("Geting from 9th");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////11///////////11////////////////11////////////////11////////
void park11()
{
   //rotate koro

   digitalWrite(dirPin3,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
   //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 33000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in
   digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Nice namo
  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Slide out
   digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo
  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 31000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
    //rotate koro
   digitalWrite(dirPin3,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

    lcd.setCursor(0, 1);
  lcd.print("Park 11th cell");
}
void get11()
{
  //rotate koro

   digitalWrite(dirPin3,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
   //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 31000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

   //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//Slide out
   digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 33000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

    //rotate koro
   digitalWrite(dirPin3,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay 

  lcd.setCursor(0, 1);
  lcd.print("Geting from 11th");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////13////////////////13////////////////13/////////////13
void park13()
{
   //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 44000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Slide out
   digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo
   digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 42000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
    
    lcd.setCursor(0, 1);
  lcd.print("Park 13th cell");
 
}

void get13()
{
  //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 42000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//Slide out
   digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 44000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay 

  lcd.setCursor(0, 1);
  lcd.print("Geting from 13th");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////15////////15///////////////15///////////////////15////////////15
void park15()
{
   //rotate koro

   digitalWrite(dirPin3,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
   //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 44000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in
   digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Nice namo
  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Slide out
   digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo
  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 42000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
    //rotate koro
   digitalWrite(dirPin3,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

    lcd.setCursor(0, 1);
  lcd.print("Park 15th cell");
 
}
void get15()
{
   //rotate koro

   digitalWrite(dirPin3,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
   //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 42000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
   //upore utho
   digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//Slide out
   digitalWrite(dirPin1,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 44000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

    //rotate koro
   digitalWrite(dirPin3,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  lcd.setCursor(0, 1);
  lcd.print("Geting from 15th");
}

////////////////////////////////////////////////EVEN cell parking  ///////////////////////////////2//2//2//2//2222222222/////////////////////////222222222222222
void park2()
{
  //upore utho
     digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 11000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin2,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Slide out
   digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 9000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

    lcd.setCursor(0, 1);
  lcd.print("Park at 2nd cell");

}

void get2()
{
    //upore utho
     digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 9000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin2,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//upore utho
     digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//Slide out
   digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 11000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  lcd.setCursor(0, 1);
  lcd.print("Geting from 2nd");
}
//////////////////////////////////////////////////////////////////////////////////////444//////////////44///////////4////////4/////////////4//444444444
void park4()
{
    //rotate koro

   digitalWrite(dirPin3,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
    //upore utho
    digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 11000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);



//slide in

   digitalWrite(dirPin2,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay


//Nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Slide out
   digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 9000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
   
    //rotate koro

   digitalWrite(dirPin3,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
   
    lcd.setCursor(0, 1);
  lcd.print("Park at 4th cell");
 
}
void get4()
{
  //rotate koro

   digitalWrite(dirPin3,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
    //upore utho
    digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 9000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin2,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay


 //upore utho
    digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//Slide out
   digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 11000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
   
    //rotate koro

   digitalWrite(dirPin3,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  lcd.setCursor(0, 1);
  lcd.print("Geting from 4th");
}
////////////////////////////////////////////////////////////////////////////////6///6/////////6//////////6//////////6///////////////6////////////
void park6()
{
    //upore utho
     digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 22000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin2,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Slide out
   digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 20000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

    lcd.setCursor(0, 1);
  lcd.print("Park at 6th cell");
}
void get6()
{
   //upore utho
     digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 20000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin2,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//upore utho
     digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//Slide out
   digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 22000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  lcd.setCursor(0, 1);
  lcd.print("Geting from 6th");
}
/////////////////////////////////////////////8/////////////////////8///////////////////8/////////////////8///////////////////8///////////
void park8()
{
  //rotate koro

   digitalWrite(dirPin3,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
    //upore utho
    digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 22000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin2,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay


//Nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Slide out
   digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 20000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
   
    //rotate koro

   digitalWrite(dirPin3,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

    lcd.setCursor(0, 1);
  lcd.print("Park at 8th cell");
}
void get8()
{
   //rotate koro

   digitalWrite(dirPin3,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
    //upore utho
    digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 20000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin2,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay


 //upore utho
    digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//Slide out
   digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 22000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
   
    //rotate koro

   digitalWrite(dirPin3,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  lcd.setCursor(0, 1);
  lcd.print("Geting from 8th");
}
///////////////////////////////////////////////////////////////////////////10//////////////////////////10////////10///////////////////////10////////10
void park10()
{
    //upore utho
     digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 33000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin2,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500);  
  }
  delay(1000); // One second delay

//Slide out
   digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 31000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

    lcd.setCursor(0, 1);
  lcd.print("Park 10th cell");
}
void get10()
{
   //upore utho
     digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 31000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin2,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//upore utho
     digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//Slide out
   digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 33000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  lcd.setCursor(0, 1);
  lcd.print("Geting from 10th");
}
////////////////////////////////////////////////////////////////12///////////////////12//////////////////12//////////////12/////////////////////12
void park12()
{
  //rotate koro

   digitalWrite(dirPin3,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
    //upore utho
    digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 33000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);



//slide in

   digitalWrite(dirPin2,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay


//Nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Slide out
   digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 31000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
   
    //rotate koro

   digitalWrite(dirPin3,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

    lcd.setCursor(0, 1);
  lcd.print("Park 12th cell");
}
void get12()
{
   //rotate koro

   digitalWrite(dirPin3,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
    //upore utho
    digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 31000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin2,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay


 //upore utho
    digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//Slide out
   digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 33000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
   
    //rotate koro

   digitalWrite(dirPin3,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  lcd.setCursor(0, 1);
  lcd.print("Geting from 12th");
}
/////////////////////////////////////////////////////14//////////////////////14/////////////////////14///////////14////////////////////////14
void park14()
{
    //upore utho
     digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 44000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin2,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Slide out
   digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 42000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

    lcd.setCursor(0, 1);
  lcd.print("Park 14th cell");

}
void get14()
{
   //upore utho
     digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 42000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin2,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//upore utho
     digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//Slide out
   digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 44000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  lcd.setCursor(0, 1);
  lcd.print("Geting from 14th");
}
////////////////////////////////////////////////////16///////////////////////16/////////////////////////16////////////////////////16///////////////16
void park16()
{
  //rotate koro

   digitalWrite(dirPin3,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
    //upore utho
    digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 44000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin2,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay


//Nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Slide out
   digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 42000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
   
    //rotate koro

   digitalWrite(dirPin3,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

    lcd.setCursor(0, 1);
  lcd.print("Park 16th cell");
}
void get16()
{
   //rotate koro

   digitalWrite(dirPin3,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
    //upore utho
    digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 42000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//slide in

   digitalWrite(dirPin2,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay


 //upore utho
    digitalWrite(dirPin4,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin4,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

//Slide out
   digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 800; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

//Ekdom nice namo

  digitalWrite(dirPin4,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 44000; x++) {
    digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
   
    //rotate koro

   digitalWrite(dirPin3,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4400; x++) {
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  lcd.setCursor(0, 1);
  lcd.print("Geting from 16th");
}
