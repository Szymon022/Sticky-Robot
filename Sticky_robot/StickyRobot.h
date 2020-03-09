#ifndef MY_STICKY_H
#define MY_STICKY_H

#include <Arduino.h>

class Sticky{ 
    
    private:
        byte leftMotorForwardPin, leftMotorBackwardPin, leftMotorSpeedPin;
        byte rightMotorForwardPin, rightMotorBackwardPin, rightMotorSpeedPin; 
        byte triggerPin, echoPin;
        float distanceFromObstacle;
        float distanceThreshold;
        
    public:
        enum class Status{      
          NoObstacle,
          ObstacleDetected,
        }; 
        Sticky(
               byte leftMotorForwardPin, byte leftMotorBackwardPin, 
               byte rightMotorForwardPin, byte rightMotorBackwardPin,
               byte leftMotorSpeedPin, byte rightMotorSpeedPin,
               byte echoPin, byte triggerPin);
            
        void initialize();
        void distanceSettingCM(float distanceThreshold);
        Sticky::Status distance();
        void goForward();
        void goBackward();
        void goLeft();        //-//
        void goRight();       //-//
        void allStop();
        void avoidObstacleLeft();
        void avoidObstacleRight();
};

#endif
