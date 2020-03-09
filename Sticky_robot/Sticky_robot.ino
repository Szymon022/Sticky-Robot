#include "StickyRobot.h"

Sticky robot(2,3,4,5,9,10,11,12);

void setup() {
  robot.distanceSettingCM(20);
  
}

void loop() {
  if(robot.distance() == Sticky::Status::ObstacleDetected){
    robot.avoidObstacleLeft();
  }
  else{
    robot.goForward();
  }
}
