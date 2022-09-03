#include <SPI.h>
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position
const int red = A3;   //define red led
const int grn = A2;  //define green led
const int ir = A0; //pir sensor is sonnected at pin A0
 
#define SS_PIN 10
#define RST_PIN 9

 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  pinMode(ir,INPUT); //pir output pin is connected to A0 pin of an Arduino
  pinMode(red, OUTPUT); 
  pinMode(grn, OUTPUT);
  digitalWrite(red, HIGH); // turn the LED on 
  digitalWrite(grn, LOW); // turn the LED off 
  
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);  
}
void loop() 
{
  // Look for new cards

  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "1A";
  byte letter;
  //Read card
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "1A") //change here the UID of the card/cards that you want to give access
  {
    
    myservo.write(90);
    digitalWrite(red, LOW); // turn the LED on 
    digitalWrite(grn, HIGH); // turn the LED off 
    
    Serial.println("Authorized access");
    Serial.println();
    //val = digitalRead(pir);    // read sensor value
    while (digitalRead(ir)==HIGH);
    delay(300);
    while (digitalRead(ir)==LOW);
    delay(500);
    
    
    digitalWrite(red, HIGH); // turn the LED on 
    digitalWrite(grn, LOW); // turn the LED off 
    myservo.write(0);
    
  }
 
  else   
  {
    Serial.println(" Access denied");
    delay(3000);
  }
} 
