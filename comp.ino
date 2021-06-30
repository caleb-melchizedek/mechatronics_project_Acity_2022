#include <Servo.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal_I2C.h>


Adafruit_MLX90614 mlx = Adafruit_MLX90614();
LiquidCrystal_I2C lcd(0x27, 16 ,2); //


#define S0 3
#define S1 4
#define S2 6
#define S3 5
#define sensorOut 7

//ultra
int trigger = 2; 
int echo = 1; 
int buzzer = 12; 
int red= 11;
int green= 10;

int maskcol;

//color
int redfrequency = 0;
int grefreq= 0;
int blfreq= 0;
bool mask;


int distance ; 
int timer; 

//temperature
int temp_obj;
bool enter_temp;
Servo myservo1; 

void setup() {

   myservo1.attach(13);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
   pinMode(buzzer, OUTPUT);
   pinMode(red, OUTPUT);
   pinMode(green, OUTPUT);
   
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  mlx.begin(); 

  lcd.begin();
lcd.backlight();//Power on the back light
lcd.print("Welcome to ACity");// Power off the back light

}

void loop() {



  digitalWrite (trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite (trigger, LOW);
  timer = pulseIn (echo, HIGH);
  distance = (timer * 0.034) / 2;

  
  
    if (distance <= 20)
  {

     digitalWrite(red, LOW);
    //digitalWrite(green, HIGH);
     tone(buzzer,5);
    delay(1500);
    noTone(buzzer);
    check();
    digitalWrite(red, LOW);
    //digitalWrite(green, HIGH);
    
    temp_obj = mlx.readObjectTempC();
   }
   else {
    
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    }

  
}
void check(){
  readmask();
  readtemp();

  if ((mask== 1) && (enter_temp==1)){
    
//    myservo1.write(-180);
//            delay(1500);
//            myservo1.write(0);
//           lcd.clear();//Clean the screen
//    lcd.setCursor(0,0);
//    lcd.print(" Come on In"); 

    digitalWrite(green, HIGH);
    delay(1500);
    digitalWrite(green, LOW); }

  else{
    lcd.clear();//Clean the screen
lcd.setCursor(0,0);
lcd.print(" Sorry come ");
lcd.setCursor(0,1);
lcd.print(" again Later");
}

}

void readmask(){
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  redfrequency = pulseIn(sensorOut, LOW);
  delay(100);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  grefreq = pulseIn(sensorOut, LOW);
  delay(100);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  blfreq = pulseIn(sensorOut, LOW);
  delay(100);

  maskcheck();

}

void maskcheck(){
////checking the colors

    //black
    //find a way to control black
    //if(redfrequency> 280 && redfrequency< 318 && blfreq> 296 && blfreq< 325 && grefreq > 370 && grefreq < 410){
//    if((redfrequency> 280 && redfrequency< 300 && blfreq> 290 && blfreq< 310 && grefreq > 355 && grefreq < 380)|| (redfrequency> 260 && redfrequency< 280 && blfreq> 270 && blfreq< 290 && grefreq > 330 && grefreq < 360)){
//     mask= true;
//   myservo1.write(180);
//    delay(1500);
//    myservo1.write(0);
//    }

//blue
    //else if(redfrequency> 250 && redfrequency< 280 && blfreq> 250 && blfreq< 300 && grefreq > 310 && grefreq < 370){
       if(redfrequency> 210 && redfrequency< 250 && blfreq> 200 && blfreq< 240 && grefreq > 250 && grefreq < 290){
    mask= true;  
    }

 //white
    //else if(redfrequency> 230 && redfrequency< 270 && blfreq> 230 && blfreq< 290 && grefreq > 300 && grefreq < 380){
    else if(redfrequency> 210 && redfrequency< 230 && blfreq> 210 && blfreq< 230 && grefreq > 260 && grefreq < 280){
    mask= true;
    }

    else{
    mask= false; 
    }

  
    
}

void readtemp(){

           if (temp_obj>30 && temp_obj<38){
            enter_temp= true;
            
          }

           if (temp_obj>38){
            enter_temp= false;

           }
          }
