//
// Created by syue on 19-2-1.
//

#include "path_plan/path_plan.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}


int main(int argc, char** argv){

  ros::init(argc, argv, "path_plan_node");
//  tf::TransformListener tf(ros::Duration(10));
//
//  path_plan::PathPlan path_plan(/*tf*/);
//  ros::NodeHandle n("~");
//  n.subscribe("normal_clean", 1, &PathPlan::NormalCleanCb, this);

  path_plan::PathPlan path_plan;
//

//  //ros::MultiThreadedSpinner s;
  ros::spin();

  return(0);
}