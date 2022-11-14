#include <ros/ros.h>
#include "params_reconfig/reconfigureMsg.h"

#include <sstream>
#include <string>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "publisher");

    ros::NodeHandle n;

    ros::Publisher m_pub = n.advertise<params_reconfig::reconfigureMsg>("reconfig_cmd", 1000);

    params_reconfig::reconfigureMsg msg;

    msg.node_name = "dynamic_tutorials";
    msg.param_name = "str_param";
    msg.value = std::string(argv[1]);

    std::cout << std::string(argv[1]) << std::endl;
    
    m_pub.publish(msg);

    ros::spinOnce();

    return 0;
}