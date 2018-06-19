/*  Copyright (C)  2018  Anith Patel and Sohil Patel.
    Permission is granted to copy, distribute and/or modify this document
    under the terms of the GNU Free Documentation License, Version 1.3
    or any later version published by the Free Software Foundation;
    with no Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts.
    A copy of the license is included in the section entitled "GNU
    Free Documentation License". */



#include<BlynkSimpleCurieBLE.h>
#include<CurieBLE.h>

#define BLYNK_SERIAL Print //writing data for blynk

byte PWM_PIN = 3;
int pwm_value;
int LED1 = A0;

char auth[] = "Auth key"; //paste auth key of Blynk

BLEPeripheral blePeripheral;


void setup() 
{
  blePeripheral.setLocalName("Airowl");     //setting BLE for blynk
  blePeripheral.setDeviceName("Airowl");
  blePeripheral.setAppearance(384);
  Blynk.begin(blePeripheral, auth);
  blePeripheral.begin();
  Serial1.begin(9600);                      //initialization of uart communication 
  Serial.begin(9600);
                     //led setup
  pinMode(PWM_PIN, INPUT);  
  pinMode(LED1, OUTPUT);  
}


void loop() 
{
 Blynk.run();                               //calls blynk
 blePeripheral.poll();
 delay(500);
 WriteDataco2(); 
 for(i=0; i<=256; i++){
 analogWrite(LED1, i);
 delay(100);    
 }
 for(i=256; i>=0; i--){
 analogWrite(LED1, i);
 delay(100);
 }   
                                //calls writedata function
}

void LedColor(int red, int blue, int green){
  analogWrite(PIN1, red);
  analogWrite(PIN2, blue);
  analogWrite(PIN3, green);
  }


void sensorDataPWM()
{
    pwm_value = pulseIn(PWM_PIN, HIGH);
    co_2 = (pwm_value*100-5)*155/9+450;
}



void WriteDataco2()
{
sensorDataPWM();    
Blynk.virtualWrite(V4, co_2);
delay(1000);    
}

