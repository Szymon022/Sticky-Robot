#include "StickyRobot.h"

Sticky::Sticky(byte leftMotorForwardPin, byte leftMotorBackwardPin, byte leftMotorSpeedPin,
               byte rightMotorForwardPin, byte rightMotorBackwardPin, byte rightMotorSpeedPin,
               byte echoPin, byte triggerPin){
                  this->leftMotorForwardPin = leftMotorForwardPin;
                  this->leftMotorBackwardPin = leftMotorBackwardPin;
                  this->leftMotorSpeedPin = leftMotorSpeedPin;
                  
                  this->rightMotorForwardPin = rightMotorSpeedPin;
                  this->rightMotorBackwardPin = rightMotorBackwardPin;
                  this->rightMotorSpeedPin = rightMotorSpeedPin;
                  
                  this->echoPin = echoPin;
                  this->triggerPin = triggerPin;                
              }
void Sticky::initialize(){
  
}
