#include <ros/ros.h>
#include <stdlib.h>
#include "params_reconfig/reconfigureMsg.h"

void reconfigCallback(const params_reconfig::reconfigureMsg::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->value.c_str());

    // system("rosrun dynamic_reconfigure dynparam set /dynamic_tutorials str_param A_du");
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "reconfigure_node");

    ROS_INFO("Reconfigure node started");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("reconfig_cmd", 1000, reconfigCallback);

    ros::spin();

    return 0;
}
