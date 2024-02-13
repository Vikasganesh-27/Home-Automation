#include <Stepper.h>

#define BLYNK_TEMPLATE_ID "TMPL34HL-_VAo"
#define BLYNK_TEMPLATE_NAME "Home Automation Assignment"
#define BLYNK_AUTH_TOKEN "4yEFoFn2yaWCzeI_575VjUPe1gTVrudi"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>


char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Wokwi-GUEST";
char pass[] = "";


int ledPin = 12;
int ledbutton = 14;
int fanbutton = 25;
int stepsPerRevolution = 200;

Stepper myStepper(stepsPerRevolution,17,5,18,19);

void setup() {
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  myStepper.setSpeed(60);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  
  Blynk.run();
  int ledbuttonVal = digitalRead(ledbutton);
  int fanbuttonVal = digitalRead(fanbutton);

  if(ledbuttonVal==1)
  {
    digitalWrite(ledPin, HIGH);
  }
  if(fanbuttonVal==1)
  {
    myStepper.step(stepsPerRevolution);
  }
}


BLYNK_WRITE(V0) 
{
  
  int ledValue = param.asInt();

  
  if (ledValue == 1) 
  {
    digitalWrite(ledPin, HIGH);  // Turn on the LED
  } 
  else {
    digitalWrite(ledPin, LOW);   // Turn off the LED
  }
}

BLYNK_WRITE(V1) 
{
  
  int fanValue = param.asInt();


  if (fanValue == 1) 
  {
    myStepper.step(stepsPerRevolution);
  }
 
}
