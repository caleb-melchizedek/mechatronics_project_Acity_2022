#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);


Adafruit_MLX90614 mlx = Adafruit_MLX90614();

Servo myservo1;  
int temp_obj;
int trigger = 2; 
int echo = 3; 
int buzzer = 4; 
int distance ; 
int timer; 
//int pos1,pos2;

void setup() {
  // Serial monitor initialisation 
  Serial.begin(9600);
  // Ultrasonic sensor initialisation
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);

  // LCD Initialisation
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Welcome to Acity");
  delay(5000);
  lcd.clear();

  // Servo Initialisation
  myservo1.attach(9);  
//  myservo2.attach(8); 
  //myservo1.write(90);
  //myservo2.write(90);

  // Infrared temperature sensor initialisation
  mlx.begin();  

}

void loop() {
  
  temp_obj = mlx.readObjectTempC();
  digitalWrite (trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite (trigger, LOW);
  timer = pulseIn (echo, HIGH);
  distance = (timer * 0.034) / 2;
  if (distance <= 10)
  {
    systemOn();
    tone(buzzer,5);
    delayMicroseconds(5);
    noTone(buzzer);
   }
   else {
    systemOff ();
    }

         // Serial.print(temp_obj);
          //Serial.print("\n");
          Serial.print(distance);
}
          
void systemOn(){
        
          if (temp_obj<37){
            myservo1.write(180);
            delay(5000);
            myservo1.write(0);
            lcd.print(temp_obj);
            lcd.setCursor(3,0);
            lcd.print((char)223);
            lcd.print("C");
            lcd.setCursor(1,1);
            lcd.print("Please Enter");
            delay(2000);
            lcd.clear();
                
          }

           if (temp_obj>38){
            myservo1.write(0);
            delay(500);
            digitalWrite(buzzer,HIGH);
            lcd.print(temp_obj);
            lcd.setCursor(3,0);
            lcd.print((char)223);
            lcd.setCursor(1,1);
            lcd.print("Sorry, Come back later");
            delay(2000);
            lcd.clear();
            
            
          }
}

void systemOff(){
   myservo1.write(0);
   lcd.print("system hibernating");
  }
