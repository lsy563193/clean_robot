//
// Created by syue on 19-2-1.
//

#include "path_plan/robot.h"

int main(int argc, char** argv){

  ros::init(argc, argv, "path_plan_node");
  Robot robot;
  ros::spin();

  return(0);
}