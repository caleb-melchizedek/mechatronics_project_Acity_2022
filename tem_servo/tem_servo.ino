#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

Servo myservo1;  
Servo myservo2; 
int temp_obj;
int pos1,pos2;

void setup() {
  Serial.begin(9600);
 
  myservo1.attach(9);  
  myservo2.attach(8); 
  //myservo1.write(90);
  //myservo2.write(90);
  mlx.begin();  

}

void loop() {
  temp_obj = mlx.readObjectTempC();
          kaiguan();  
          
          Serial.print(temp_obj);
          Serial.print("\n");
}
          
void kaiguan(){
  

          if (temp_obj<31){
            myservo1.write(0);
            delay(500);
                
          }

           if (temp_obj>31 && temp_obj<38){
            myservo1.write(180);
            delay(1500);
            myservo1.write(0);
            
          }

           if (temp_obj>38){
            myservo1.write(0);
            delay(500);
             
          }
//          if(temp_obj > 30 && temp_obj <38){
//           
//           for(pos1 = 90; pos1 <= 180; pos1 += 1)
//          {                                 
//            myservo1.write(180);
//                 
//            delay(1500);
//          }
//            delay(5000);
//
//           for(pos1 = 180; pos1>=90; pos1 -=1)
//           {
//            myservo1.write(180);
//                 
//            delay(1500);                     
//           }
//          } 
//            if(temp_obj>37){
//            myservo1.write(0);
  //}
}     
