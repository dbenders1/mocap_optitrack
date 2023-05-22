

#include <geometry_msgs/PoseStamped.h>
#include <ros/ros.h>
#include <chrono>
#include <time.h>

using namespace std::chrono;

class OptitrackRemap
{
    public:
        OptitrackRemap(std::shared_ptr<ros::NodeHandle> nh, const int frequency, const std::string topic_name);

        void setup();

        void callback_pose(const geometry_msgs::PoseStamped &msg);

    private:
        /// Global node handler
        std::shared_ptr<ros::NodeHandle> _nh;

        // Period between remapping
        ros::Rate _loop_rate;

        // Publisher for the mavros topic
        ros::Publisher _pub_remap;

        // Subscriber for the IMU pose and Reset
        ros::Subscriber _sub_pose;

        // Beginning time of period (Timer<milliseconds, steady_clock>)
        geometry_msgs::PoseStamped _msg_remap;

        // Store z offset
        double _offset_z;

        // If first frame is received for storing offset
        bool _first_frame = true;

        // If new state is received
        bool _received_new = false;

};
