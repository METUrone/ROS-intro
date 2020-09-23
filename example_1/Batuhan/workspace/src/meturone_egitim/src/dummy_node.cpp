#include <ros/ros.h>
//library for our custom message.
#include <meturone_egitim/Dummy.h>
//helper function
#include "util/generate_random_array.hpp"
#include <vector>

int main(int argc, char* argv[]){
    //next 2 lines are standard for every roscpp node
    ros::init(argc, argv, "dummy_node");
    ros::NodeHandle nh;

    //a publisher instance to publish the array
    ros::Publisher pub = nh.advertise<meturone_egitim::Dummy>(
        "dummy_topic",
        1000
    );
    
    //publish a new array twice a second
    ros::Rate rate(2);
    ROS_INFO_STREAM("Hello, ROS!");
    
    //while roscore is running or this node is not terminated
    while(ros::ok()){
        //this is executed once
        ROS_WARN_STREAM_ONCE("Incoming arrays!!");
        
        //our custom message instance
        meturone_egitim::Dummy msg;
        
        std::vector<int> arr;
        //fill the array randomly 
        //(see util/generate_random_array.hpp) for details
        generate_random_array(arr);

        msg.n = arr.size();
        msg.arr = arr;
        pub.publish(msg);
    }
    ROS_ERROR_STREAM("Loop is broken!");
    return 0;
}