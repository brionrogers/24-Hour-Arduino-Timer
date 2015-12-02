int MotorControl = 5;    // Digital Arduino Pin used to control the motor
int resetPin = 12;
unsigned long previousMillis = 0;

unsigned long interval = (unsigned long) 1000 * 60 * 60 * 20;
unsigned long interval24 = (unsigned long) 1000 * 60 * 60 * 24;
unsigned long interval20 = (unsigned long) 1000 * 60 * 60 * 20;
unsigned long interval4 = (unsigned long) 1000 * 60 * 60 * 4;
unsigned long intervalTwoMinute = (unsigned long) 1000 * 60 * 3;

void setup()
{
   //digitalWrite(resetPin, HIGH);
  // declare pin 5 to be an output:
  Serial.begin(9600);
  pinMode(MotorControl, OUTPUT);
  pinMode(resetPin, OUTPUT);
 
}

void loop()
{

  unsigned long currentMillis = millis();

  //Does its thing for 20 hours
  while ((currentMillis - previousMillis) < interval20)
  {
    currentMillis = millis();
    //Serial.println("Currently inside the on loop");
    delay(1000);
    if (digitalRead(MotorControl) == LOW)
    {
      Serial.println("You just turned the light ON");
      digitalWrite(MotorControl, HIGH);
    }


  }

  previousMillis = currentMillis;


  delay(1000);

  //Does its thing for 4 hours
  while ((currentMillis - previousMillis) < interval4)
  {
    currentMillis = millis();
    //Serial.println("Currently inside the off loop");
    delay(1000);
    if (digitalRead(MotorControl) == HIGH)
    {
      Serial.println("You just turned the light OFF");
      digitalWrite(MotorControl, LOW);
    }
  }

  previousMillis = currentMillis;
  
  //Serial.println("Fixing to print");
  delay(1000);
  //digitalWrite(resetPin, LOW);
  
  //interval20=interval20+interval20;
  //interval4 = interval4 + interval4;


}

void turnLightOn() {
  if (digitalRead(MotorControl) == LOW)
  {
    digitalWrite(MotorControl, HIGH);
  }
}

void turnLightOff() {
  if (digitalRead(MotorControl) == HIGH)
  {
    digitalWrite(MotorControl, LOW);
  }
}

void(* resetFunc) (void) = 0; //declare reset function @ address 0

boolean checkLight() {
  if (digitalRead(MotorControl) == HIGH)
  {
    return true;
  } else {
    return false;
  }
}

