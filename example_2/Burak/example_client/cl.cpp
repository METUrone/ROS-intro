#include <stdlib.h>
#include <ros/ros.h>
#include "example_server/ex.h"
#include "meturone_egitim/Dummy.h"
#include <vector>

bool msg_received = 0;

int n;
std::vector<int> arr;

void get_data(const meturone_egitim::Dummy &msg)
{
    ROS_INFO_STREAM("msg received");
    msg_received = 1;

    n = msg.n;
    arr = msg.arr;
}

int main(int argc, char **argv)
{
    bool succ = 1;

    example_server::ex::Response res;
    example_server::ex::Request req;

    ros::init(argc, argv, "client_example");
    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<example_server::ex>("example");

    ros::Subscriber sub = nh.subscribe("dummy_topic", 1000, &get_data);

    while (ros::ok()) {
        ros::spinOnce();

        if (!msg_received)
            continue;

        req.n = n;
        req.arr = arr;

        ROS_INFO_STREAM("Sending request");
        succ = client.call(req, res);

        msg_received = 0;

        if (succ) {
            ROS_INFO_STREAM("Respond taken. diff:" << res.diff);
        } else {
            ROS_INFO_STREAM("Failed.");
        }
    }
}