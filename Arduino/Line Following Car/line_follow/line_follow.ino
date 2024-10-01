#define IRl 4  //red wala sensor
#define IRr 2  //green wala sensor
bool irR,irL;

//Motor A
const int inputPin1  = 7;     //  INR3
const int inputPin2  = 6;     //  INR4 

//Motor B
const int inputPin3  = 9;     //  INR1
const int inputPin4  = 8;     //  INR2

#define EN1  5
#define EN2  3
    
/*
//Motor A
#define inputPin1  D7;     //  INR3
#define inputPin2  D6;     //  INR4 

//Motor B
#define inputPin3  D9;     //  INR1
#define inputPin4  D8;     //  INR2

#define EN1  D10                 
#define EN2  D5    
*/
void setup()
{
    pinMode(EN1, OUTPUT);   // where the motor is connected to
    pinMode(EN2, OUTPUT);   // where the motor is connected to
    pinMode(inputPin1, OUTPUT);
    pinMode(inputPin2, OUTPUT);
    pinMode(inputPin3, OUTPUT);
    pinMode(inputPin4, OUTPUT);  
    pinMode(IRl,INPUT);
    pinMode(IRr,INPUT);
    int speed =81;
    analogWrite(EN1, speed);//sets the motors speed
    analogWrite(EN2, speed);//sets the motors speed
    Serial.begin(9600);
}

void loop()
{
    irL = digitalRead(IRl);
    irR = digitalRead(IRr);

    if (irL==1 && irR==1){
      stop();
      Serial.println("rukkk bete");
    }
    else if (irL==1 && irR==0){
      right();
      Serial.println("dayne mudle bete");
    }
    else if (irL==0 && irR==1){
      left();
      Serial.println("bayne mudlee bete");
    }
    else if (irL==0 && irR==0){
      forward();
      Serial.println("chl bete");
    }    
}

void left(void)
{
    digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, LOW);
    digitalWrite(inputPin3, HIGH);
    digitalWrite(inputPin4, LOW);  
}

void right(void)
{
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, HIGH);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, HIGH); 
}

void stop(void)
{ 
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, LOW);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, LOW); 
}

void backward(void)
{   
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, HIGH);
    digitalWrite(inputPin3, HIGH);
    digitalWrite(inputPin4, LOW); 
}

void forward(void)
{ 
    digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, LOW);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, HIGH); 
}
