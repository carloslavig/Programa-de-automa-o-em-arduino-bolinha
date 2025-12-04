// note: for my beam to be horizontal, Servo Motor angle should be 135 degrees.

#include <Servo.h> 

 

Servo meuServo; 

int pos;

 


 


#include <Servo.h>

#include <hcsr04.h>


#define TRIG 12

#define ECHO 13






HCSR04 ultrassom(TRIG, ECHO, 40, 400);


void setup()

 {



    meuServo.attach(6); 

    meuServo.write(0);


  Serial.begin(9600);



  Serial.print("setup\n");

}


void loop() {

while (dist_mm != 126) {

    if (dist_mm < 126) {
    pos += 1;
     meuServo.write(pos); 
    delay(10);
    }
    else if (dist_mm > 126) {
        pos -= 1;
        meuServo.write(pos); 

        delay(15);
    }
    else if (dist_mm == 126) {
         meuServo.write(pos); 
        break;
    }
}


  int dist_mm = ultrassom.distanceInMillimeters();

  if (dist_mm >= 300) {return;}

  if (dist_mm<40) {dist_mm=40;}

  Serial.println(dist_mm);

  delay(10);

}