#include <ros/ros.h>
#include <std_msgs/Int64.h>

int counter = 0;
ros::Publisher pub;

void callback_receive_data(const std_msgs::Int64& msg){

    ROS_INFO("Message received : %li", msg.data);
    std_msgs::Int64 count;
    counter += msg.data;
    count.data =  counter;
    pub.publish(count);

}

int main (int argc, char **argv){
    ros::init(argc, argv, "number_counter");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/number", 1, callback_receive_data);
    pub = nh.advertise<std_msgs::Int64>("/number_count", 1);

    ros::spin();

}