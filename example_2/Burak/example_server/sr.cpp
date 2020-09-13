#include <ros/ros.h>
#include "example_server/ex.h"
#include "meturone_egitim/Dummy.h"
#include <vector>

int n1 = 0;
int n2 = 0;

void assign_min(int n, std::vector<int> arr)
{
	int i;

	if (arr[0] < arr[1]) {
		n1 = arr[0];
		n2 = arr[1];
	} else {
		n2 = arr[0];
		n1 = arr[1];
	}

	for (i = 2; i < n - 1; i += 1)
	{
		if (n1 > arr[i]) {
			n2 = n1;
			n1 = arr[i];
		}
		if (n1 > arr[i + 1]) {
			n2 = n1;
			n1 = arr[i + 1];
		}
		if (n1 != arr[i] && n2 > arr[i])
			n2 = arr[i];
		if (n1 != arr[i + 1] && n2 > arr[i + 1])
			n2 = arr[i + 1];
	}
}

bool srv_callback(example_server::ex::Request &req, example_server::ex::Response &resp)
{
	ROS_INFO_STREAM("Request received. Responding...");
    
	assign_min(req.n, req.arr);
    resp.diff = n2-n1;

	return 1;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "server_example");
    ros::NodeHandle nh;

	ROS_INFO_STREAM("Server online. Waiting for request...");

    ros::ServiceServer server = nh.advertiseService("example", &srv_callback);
    ros::spin();
}