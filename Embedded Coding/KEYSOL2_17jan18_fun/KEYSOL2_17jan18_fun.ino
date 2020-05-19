//common code: entry&1 entry&2 entry&4 entry&8 entry&16 entry&32
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void keypad_sense(void);
void solenoid_test(void);
void Char_all(void);
int buttonStateAll();


int data=0;
int inByte=0;
int updatedata=data;
const char charac[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
const int charv[]={0b000001,0b000011,0b001001,0b011001,0b010001,0b001011,0b011011,0b010011,0b001010,0b011010,0b000101,0b000111,0b001101,0b011101,0b010101,0b001111,0b011111,0b010111,0b001110,0b011110,0b100101,0b100111,0b111010,0b101101,0b111101,0b110101};
const int reset=0;
const int dval= 1000;
const int b1 = A7;
const int b2 = A6;
const int b3 = A5;
const int b4 = A4;                                                                                     
const int b5 = A3;
const int b6 = A2;


// the number of the pushbutton printer
const int ledPin2 =  2; 
const int ledPin3 =  3;
const int ledPin4 =  4;
const int ledPin5 =  5;
const int ledPin6 =  6;
const int ledPin7 =  7;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0; 
int buttonState4 = 0;
int buttonState5 = 0;


void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(b1, INPUT);
   pinMode(ledPin3, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(b2, INPUT);
   pinMode(ledPin4, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(b3, INPUT);
   pinMode(ledPin5, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(b4, INPUT);
   pinMode(ledPin6, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(b5, INPUT);
   pinMode(ledPin7, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(b6, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println("Testing Started");
  delay(500);
  lcd.print("Select Auto:Training");
  lcd.setCursor(0,1);
  lcd.print("Select Key:pressing");
  }


void loop() {
  Serial.println("Select A or K");
  delay(500);
  lcd.clear();
    inByte = digitalRead(A1);
  
  if (inByte == 1){
     
    lcd.setCursor(0,1);
    lcd.print("Key Mode");
    delay(500);
    lcd.clear();
    //Char_all();
    keypad_sense();
  }
  else {
    // lcd.setCursor(0,1);
    lcd.print("Auto Mode");
    delay(500);
    lcd.clear();
    //solenoid_test();
    Char_all();
  }
}

void solenoid_test(void)
{
 // lcd.print("Edutainment kit");
 // Test each pin for actuation
 digitalWrite(ledPin2, 1);
 delay(500);
 digitalWrite(ledPin2, 0);
 delay(500);
 digitalWrite(ledPin3, 1);
 delay(500);
 digitalWrite(ledPin3, 0);
 delay(500);
 digitalWrite(ledPin4, 1);
 delay(500);
 digitalWrite(ledPin4, 0);
 delay(500);
 digitalWrite(ledPin5, 1);
 delay(500);
 digitalWrite(ledPin5, 0);
 delay(500);
 digitalWrite(ledPin6, 1);
 delay(500);
 digitalWrite(ledPin6, 0);
 delay(500);
 digitalWrite(ledPin7, 1);
 delay(500);
 digitalWrite(ledPin7, 0);
 delay(500);
 //pin testing complete
 //lcd.clear();
 
  digitalWrite(ledPin2, 1);
  digitalWrite(ledPin3, 1);  
  digitalWrite(ledPin4, 1);
  digitalWrite(ledPin5, 1);
  digitalWrite(ledPin6, 1);
  digitalWrite(ledPin7, 1);
  //lcd.print("All low");
  delay(500);
 }

void Char_all(void) //all characters
{
  for(int x=0;x<36;x++)
  {
    lcd.print(charac[x]);
    Serial.println(charac[x]);
//    digitalWrite(ledPin2, charv[x]&1);
//    digitalWrite(ledPin3, charv[x]&2);
//    digitalWrite(ledPin4, charv[x]&4);
//    digitalWrite(ledPin5, charv[x]&8);
//    digitalWrite(ledPin6, charv[x]&16);
//    digitalWrite(ledPin7, charv[x]&32);
//    delay(1000);
//    digitalWrite(ledPin2, HIGH);
//    digitalWrite(ledPin3, HIGH);
//    digitalWrite(ledPin4, HIGH);
//    digitalWrite(ledPin5, HIGH);
//    digitalWrite(ledPin6, HIGH);
//    digitalWrite(ledPin7, HIGH);
    delay(1000);
    lcd.clear();
    if (digitalRead(A1) == 1) break;
  }
}
int buttonStateAll()
{
  buttonState = digitalRead(b1);
 buttonState1 = digitalRead(b2);
 buttonState2 = digitalRead(b3);
 buttonState3 = digitalRead(b4);
 buttonState4 = digitalRead(b5);
 buttonState5 = digitalRead(b6);  
 Serial.println(buttonState);
 Serial.println(buttonState1);
 Serial.println(buttonState2);
 Serial.println(buttonState3);
 Serial.println(buttonState4);
 Serial.println(buttonState5);

  
  data=(buttonState)|(buttonState1<<1)|(buttonState2<<2)|(buttonState3<<3)|(buttonState4<<4)|(buttonState5<<5);
   
   return data;
 
}
void keypad_sense(void)
{
 lcd.print("key pressing");
 //lcd.clear();
 
  int buttonstate = buttonStateAll();
  
 
 Serial.write("data :  ");Serial.println(buttonstate);
 digitalWrite(ledPin2, data&1);
 digitalWrite(ledPin3, data&2);
 digitalWrite(ledPin4, data&4);
 digitalWrite(ledPin5, data&8);
 digitalWrite(ledPin6, data&16);
 digitalWrite(ledPin7, data&32);
 delay(dval);
 digitalWrite(ledPin2, LOW); 
 digitalWrite(ledPin3, LOW);
 digitalWrite(ledPin4, LOW);
 digitalWrite(ledPin5, LOW);
 digitalWrite(ledPin6, LOW);
 digitalWrite(ledPin7, LOW);
 delay(dval);
 lcd.clear();
 for(int x=0;x<26;x++)
     if (charv[x]==data)
     {
       lcd.print(charac[x]);
       Serial.println(charac[x]);
       break;
     }
     
}
