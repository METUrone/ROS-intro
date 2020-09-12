#include <ros/ros.h>
//library for our custom message.
#include <meturone_egitim/Dummy.h>
//library for our custom service
#include <meturone_egitim/RandomArray.h>
//helper function
#include "util/generate_random_array.hpp"
#include <vector> 

bool getRandomArrayWithService(
    meturone_egitim::RandomArray::Request &req,
    meturone_egitim::RandomArray::Response &res
) {
    ROS_WARN_STREAM("RandomArray service is called");
    std::vector<int> arr;
    generate_random_array(arr);
    res.arr = arr;
    res.n = arr.size();
    return true;
}

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
    ROS_INFO_STREAM("Advertising service RandomArray");
    ros::ServiceServer server = nh.advertiseService(
        "RandomArray",
         &getRandomArrayWithService
    );
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

        ros::spinOnce();
    }
    ROS_ERROR_STREAM("Loop is broken!");
    return 0;
}