//
// Created by syue on 19-2-1.
//

#include "path_plan/path_plan.h"

int main(int argc, char** argv){
  ros::init(argc, argv, "move_base_node");
//  tf::TransformListener tf(ros::Duration(10));
//
  path_plan::PathPlan path_plan();
//
//  //ros::MultiThreadedSpinner s;
//  ros::spin();

  return(0);
}