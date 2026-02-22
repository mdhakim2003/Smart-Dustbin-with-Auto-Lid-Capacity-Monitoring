#include <LiquidCrystal_I2C.h>
#include <NewPing.h>          //memanggil library ultrasonic
#include <SoftwareSerial.h>
#include <Servo.h>

#define TRIGGER_PIN   10       //pin trigger dihubungkan ke pin 8 arduino
#define ECHO_PIN      9   
#define MAX_DISTANCE 200 

#define TRIGGER_PIN2  13      //pin trigger dihubungkan ke pin 10 arduino
#define ECHO_PIN2     12       //pin echo dihubungkan ke pin 9 arduino     //batas jarak dari sensor
#define MAX_DISTANCE2 20      //batas jarak dari sensor

Servo myservo;

LiquidCrystal_I2C lcd(0x27, 16, 2);   //kalau masih tidak tampil, ganti menjadi 0x3f(alamat i2c)

NewPing sampah(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
NewPing kapasiti(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE2); //membuat variabel kapasitas

int pos = 0;    // variable to store the servo position

void setup() {

  Serial.begin(9600);

  lcd.init(); // Initialize the LCD 
  lcd.backlight(); // Turn on the backlight (if your LCD has one) 
  lcd.clear(); // Clear the display

  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
  myservo.write(180);
}

void loop() {

  delay(50);

  int US1 = sampah.ping_cm(300);
  int US2 = kapasiti.ping_cm()-20;   //nilai +70 di sesuaikan dengan tinggi tong sampah

  int remainingCapacity = (20 - US2) * 100 / 20 - 100;

  Serial.println(US1);
  delay(200);

  lcd.setCursor(0, 0); //set kolom dan baris
  lcd.print("Waste Dustbin");
  lcd.setCursor(0, 1); //set kolom dan baris
  lcd.print("Valume Level:");
  lcd.print(remainingCapacity);
  lcd.print("%");
  delay (50);


if(US1 <= 10){
    myservo.write(0);            //posisikan servo di 180 derajat
    delay (2000); //durasi disesuaikan dengan durasi musik
  }

  else{
    myservo.write(180);  //posisikan servo di 0 derajat
    delay(50);
  }  // waits 15ms for the servo to reach the position
}




