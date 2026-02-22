#include <LiquidCrystal_I2C.h>
#include <NewPing.h>          // include ultrasonic library
#include <SoftwareSerial.h>
#include <Servo.h>

#define TRIGGER_PIN   10       // trigger pin connected to Arduino pin 10
#define ECHO_PIN      9   
#define MAX_DISTANCE 200 

#define TRIGGER_PIN2  13       // trigger pin connected to Arduino pin 13
#define ECHO_PIN2     12       // echo pin connected to Arduino pin 12
#define MAX_DISTANCE2 20       // maximum distance for sensor 2

Servo myservo;

LiquidCrystal_I2C lcd(0x27, 16, 2);   // if display does not show, change to 0x3f (I2C address)

NewPing sampah(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
NewPing kapasiti(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE2); // create variable for capacity

int pos = 0;    // variable to store the servo position

void setup() {

  Serial.begin(9600);

  lcd.init(); // Initialize the LCD 
  lcd.backlight(); // Turn on the backlight (if your LCD has one) 
  lcd.clear(); // Clear the display

  myservo.attach(3);  // attach the servo to pin 3
  myservo.write(180); // start with lid closed
}

void loop() {

  delay(50);

  int US1 = sampah.ping_cm(300);   // ultrasonic sensor 1 reading
  int US2 = kapasiti.ping_cm()-20; // adjust value based on bin height

  int remainingCapacity = (20 - US2) * 100 / 20 - 100;

  Serial.println(US1);
  delay(200);

  lcd.setCursor(0, 0); // set column and row
  lcd.print("Waste Dustbin");
  lcd.setCursor(0, 1); // set column and row
  lcd.print("Volume Level:");
  lcd.print(remainingCapacity);
  lcd.print("%");
  delay (50);

  if(US1 <= 10){
    myservo.write(0);            // move servo to open lid
    delay (2000);                // duration adjusted as needed
  }
  else{
    myservo.write(180);          // move servo to close lid
    delay(50);
  }
}
