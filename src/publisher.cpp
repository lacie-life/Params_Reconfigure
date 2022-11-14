#include <ros/ros.h>
#include "params_reconfig/reconfigureMsg.h"

#include <sstream>
#include <string>
#include <std_msgs/String.h>


int main(int argc, char **argv)
{
    ros::init(argc, argv, "publisher");

    ros::NodeHandle n;

    ros::Publisher m_pub = n.advertise<params_reconfig::reconfigureMsg>("reconfig_cmd", 1000);

    ros::Publisher m_pub_test = n.advertise<std_msgs::String>("reconfig_cmd_test", 1000);

    ros::Rate rate(1.0);

    int count = 0;

    while (n.ok())
    {

        count++;

        params_reconfig::reconfigureMsg msg;
        msg.node_name = "dynamic_tutorials";
        msg.param_name = "str_param";
        msg.value = std::to_string(count);

        ROS_INFO(msg.node_name.c_str());
        ROS_INFO(msg.param_name.c_str());
        ROS_INFO(msg.value.c_str());
    
        m_pub.publish(msg);

        std_msgs::String msg_test;

        msg_test.data = "Test";

        m_pub_test.publish(msg_test);

        ros::spinOnce();

        rate.sleep();

    }
    
    return 0;
}