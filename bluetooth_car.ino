char t;
 #include <Servo.h>  //include servo.h library
Servo myservo;

int pos = 0;   
boolean fire = false;

#define Left 9      // left sensor
#define Right 10    // right sensor
#define Forward 8   //front sensor

#define LM1 2       // left motor
#define LM2 3       // left motor
#define RM1 4       // right motor
#define RM2 5       // right motor
#define pump 6
#define buzzer 49   //buzzer
void setup() {
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(Forward, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(buzzer, OUTPUT);
  myservo.attach(11);
  myservo.write(90);
Serial.begin(9600);
}

void put_off_fire()
{
    delay (500);
    digitalWrite(buzzer, HIGH);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    delay(100);
   digitalWrite(pump, HIGH);
   delay(500);
   
    for (pos = 50; pos <= 130; pos += 1) {
    myservo.write(pos);
    delay(10); 
  }
  for (pos = 130; pos >= 50; pos -= 1) {
    myservo.write(pos);
    delay(10);
  }
 
  digitalWrite(pump,LOW);
  digitalWrite(buzzer,LOW);
  myservo.write(90);
 
  fire=false;

 
}
 
void loop() 

{  


   myservo.write(90); //Sweep_Servo(); 

    if (digitalRead(Left) ==1 && digitalRead(Right)==1 && digitalRead(Forward) ==1)
    {
   
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    }
   
    else if (digitalRead(Forward) ==0)
    {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    fire = true;
    }
   
    else if (digitalRead(Left) ==0)
    {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    }
   
    else if (digitalRead(Right) ==0)
    {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    }
   
delay(10);//change this value to increase the distance

     while (fire == true)
     {
      put_off_fire();
     }
  


{
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
  Serial.print(t);
}
 
else if(t == 'F'){      //move reverse (all motors rotate in reverse direction)

    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);

}
 
else if(t == 'R'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)

    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
 
}
 
else if(t == 'L'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)

    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);

}

 
else if(t == 'S'){      //STOP (all motors stop)
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
}

else if(t == 'X'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,HIGH);
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,HIGH);
}

else if(t == 'T'){      //pump water
    digitalWrite(pump, HIGH);
    digitalWrite(buzzer,HIGH);
}

else if(t == 'O'){      //stop water
    digitalWrite(pump, LOW);
    digitalWrite(buzzer,LOW);
}
delay(100);
}
}
