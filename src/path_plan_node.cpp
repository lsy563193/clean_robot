//
// Created by syue on 19-2-1.
//

#include "path_plan/robot.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}


int main(int argc, char** argv){

  ros::init(argc, argv, "path_plan_node");
//  tf::TransformListener tf(ros::Duration(10));
//
//  robot::Robot robot(/*tf*/);
//  ros::NodeHandle n("~");
//  n.subscribe("normal_clean", 1, &Robot::KeyCb, this);

  Robot robot;
//

//  //ros::MultiThreadedSpinner s;
  ros::spin();

  return(0);
}