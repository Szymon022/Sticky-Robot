#ifndef MY_STICKY_H
#define MY_STICKY_H

#include <Arduino.h>

class Sticky{
    enum class Status{
      GoingForward,
      GoingBackward,
      Stop,
      NoObstacle,
      ObstacleDetected,
      
    };   
    
    private:
        byte leftMotorForwardPin, leftMotorBackwardPin, leftMotorSpeedPin;
        byte rightMotorForwardPin, rightMotorBackwardPin, rightMotorSpeedPin; 
        byte triggerPin, echoPin;
        float distanaceFromObstacle;
        float distanceMargain;
        
    public:
        Sticky(
            byte leftMotorForwardPin, byte leftMotorBackwardPin, byte leftMotorSpeedPin,
            byte rightMotorForwardPin, byte rightMotorBackwardPin, byte rightMotorSpeedPin,
            byte echoPin, byte triggerPin);
            
        void initialize();
        void goForward();
        void goBackward();
        void goLeft();
        void goRight();
        void allStop();
        Sticky::Status distance(float& distanceFromObstacle);
};

#endif
