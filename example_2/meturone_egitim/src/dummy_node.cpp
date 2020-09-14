#include <ros/ros.h>
//library for our custom service
#include <meturone_egitim/RandomArray.h>
//helper function
#include "util/generate_random_array.hpp"
#include <vector> 

//service callback function
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
    ROS_INFO_STREAM("Hello, ROS!");
    ROS_INFO_STREAM("Advertising service RandomArray");
    ros::ServiceServer server = nh.advertiseService(
        "RandomArray",
         &getRandomArrayWithService
    );
    //don't forget to write spin when using callback functions.
    //either use ros::spin() or call ros::spinOnce() periodically.
    ros::spin();
    //this is never executed
    ROS_ERROR_STREAM("Loop is broken!");
    return 0;
}
