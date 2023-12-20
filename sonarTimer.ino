// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//distance sensor setup
const int trigPin = 9;  
const int echoPin = 10; 
float duration, distance;
//button setup
const int buttonPin = 7;
int buttonState = 0;  // variable for reading the pushbutton status
byte customChar[8] = {
	0b00000,
	0b10010,
	0b10010,
	0b10010,
	0b10010,
	0b11110,
	0b10000,
	0b10000
};


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
	Serial.begin(9600);  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.createChar(0, customChar); // create a new custom character
  lcd.setCursor(0, 0); // move cursor to (8, 0)
  lcd.print("Bounce ");
  lcd.write((byte)0);  // print the custom char at (8, 0)
  lcd.print("S");
}

void Bounce() {
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of micro-seconds for bounce:
  lcd.print(duration);
  Serial.println(duration);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    Bounce();
    delay(500);
  }
}
