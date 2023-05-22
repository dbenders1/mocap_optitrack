
#include <mocap_optitrack/optitrack_remap.h>

using namespace std::chrono;

OptitrackRemap::OptitrackRemap(std::shared_ptr<ros::NodeHandle> nh, const int frequency, const std::string topic_name) 
: _nh(nh), _loop_rate(frequency) {
    
    _pub_remap = _nh->advertise<geometry_msgs::PoseStamped>(topic_name, 10);

}

void OptitrackRemap::setup()
{
    _sub_pose = _nh->subscribe("/hovergames/pose", 10, &OptitrackRemap::callback_pose, this);

    ros::AsyncSpinner spinner(2);
    spinner.start();

    while(ros::ok())
    {
        if (_received_new)
        {
            _pub_remap.publish(_msg_remap);
        }

        ros::spinOnce;

        _loop_rate.sleep();
    }
}

void OptitrackRemap::callback_pose(const geometry_msgs::PoseStamped &msg) 
{
    if (_first_frame)
    {
        _offset_z = msg.pose.position.z;
        _first_frame = false;
        ROS_INFO_STREAM("data reset for z-axis offset :" << _offset_z);
    }
    _msg_remap = msg;
    _msg_remap.pose.position.z = _msg_remap.pose.position.z - _offset_z; 

    _received_new = true;  
}