#include "StickyRobot.h"

Sticky::Sticky(byte leftMotorForwardPin, byte leftMotorBackwardPin, 
               byte rightMotorForwardPin, byte rightMotorBackwardPin,
               byte leftMotorSpeedPin, byte rightMotorSpeedPin,
               byte echoPin, byte triggerPin){
                  this->leftMotorForwardPin = leftMotorForwardPin;
                  this->leftMotorBackwardPin = leftMotorBackwardPin;
                  this->leftMotorSpeedPin = leftMotorSpeedPin;
                  
                  this->rightMotorForwardPin = rightMotorForwardPin;
                  this->rightMotorBackwardPin = rightMotorBackwardPin;
                  this->rightMotorSpeedPin = rightMotorSpeedPin;
                  
                  this->echoPin = echoPin;
                  this->triggerPin = triggerPin;
                  initialize();                
              }
void Sticky::initialize(){
   pinMode(leftMotorForwardPin, OUTPUT);
   pinMode(leftMotorBackwardPin, OUTPUT);
   pinMode(leftMotorSpeedPin, OUTPUT);
   pinMode(rightMotorForwardPin, OUTPUT);
   pinMode(rightMotorBackwardPin, OUTPUT);
   pinMode(rightMotorSpeedPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(triggerPin, OUTPUT);
}

void Sticky::distanceSettingCM(float distanceThreshold){
  this->distanceThreshold = distanceThreshold;
}

Sticky::Status Sticky::distance(){
  unsigned long echoTime;

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  echoTime = pulseIn(echoPin, HIGH);
  distanceFromObstacle = echoTime/58.0;

  if(distanceFromObstacle > distanceThreshold){
    return Sticky::Status::NoObstacle;
  }
  else{
    return Sticky::Status::ObstacleDetected;
  }
}

void Sticky::goForward(){
  analogWrite(leftMotorSpeedPin, 255);
  analogWrite(rightMotorSpeedPin, 255);
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, HIGH);
  digitalWrite(rightMotorBackwardPin,LOW);
  delay(10);  
}

void Sticky::goBackward(){
  analogWrite(leftMotorSpeedPin, 255);
  analogWrite(rightMotorSpeedPin, 255);
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, HIGH);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, HIGH);
  delay(10);   
}

void Sticky::allStop(){
  analogWrite(leftMotorSpeedPin, 0);
  analogWrite(rightMotorSpeedPin, 0);   
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, LOW); 
  delay(10);  
}

void Sticky::goLeft(){
  delay(300);
  analogWrite(leftMotorSpeedPin, 255);
  analogWrite(rightMotorSpeedPin, 255);   
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, HIGH);
  digitalWrite(rightMotorForwardPin, HIGH);
  digitalWrite(rightMotorBackwardPin, LOW);    
}

void Sticky::goRight(){
  delay(300);
  analogWrite(leftMotorSpeedPin, 255);
  analogWrite(rightMotorSpeedPin, 255);   
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, HIGH);     
}

void Sticky::avoidObstacleLeft(){
  allStop();
  delay(300);  
  while(distance() == Sticky::Status::ObstacleDetected){
    goLeft();
  }
  delay(500);  
}

void Sticky::avoidObstacleRight(){
  allStop();
  delay(300);  
  while(distance() == Sticky::Status::ObstacleDetected){
    goRight();
  }
  delay(500);  
}
