
#include <mocap_optitrack/optitrack_remap.h>
#include <ros/ros.h>

int main(int argc, char **argv) {

    
    //double frequency = 40;

    ros::init(argc, argv, "optitrack_remap");

    auto nh = std::make_shared<ros::NodeHandle>("~");

    double frequency;
    if(nh->hasParam("remap/frequency"))
    {
        nh->getParam("remap/frequency", frequency);
        ROS_INFO_STREAM("[MOCAP] Frequency is set to " << frequency);
    } else {
        ROS_ERROR_STREAM("[MOCAP] No remap value specified in the config");
    }
    
    std::string topic_name;
    if(nh->hasParam("remap/topic_name"))
    {
        nh->getParam("remap/topic_name", topic_name);
        ROS_INFO_STREAM("[MOCAP] Topic name is set to " << topic_name);
    } else {
        ROS_ERROR_STREAM("[MOCAP] No topic name specified in the config");
    }

    OptitrackRemap remapper(nh,frequency,topic_name);

    remapper.setup();

    return 0;
}