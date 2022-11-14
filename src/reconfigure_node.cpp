#include <ros/ros.h>
#include <stdlib.h>
#include "params_reconfig/reconfigureMsg.h"
#include <std_msgs/String.h>
#include <sstream>

void reconfigCallback(const params_reconfig::reconfigureMsg::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->value.c_str());

    std::string node = msg->node_name;

    std::string param = msg->param_name;

    std::string value = msg->value;

    std::stringstream ss;

    ss << "rosrun dynamic_reconfigure dynparam set" << " " << node << " " << param << " " << value;

    ROS_INFO(ss.str().c_str());

    system(ss.str().c_str());
}

void reconfigCallbackTest(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "reconfigure_node");

    ROS_INFO("Reconfigure node started");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("reconfig_cmd", 1000, reconfigCallback);

    ros::Subscriber sub_test = n.subscribe("reconfig_cmd_test", 1000, reconfigCallbackTest);

    ros::spin();

    return 0;
}
