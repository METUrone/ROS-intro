#include <ros/ros.h>
#include "dummy/answ.h"
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

void msg_callback(const meturone_egitim::Dummy &msg)
{
	int i;

	ROS_INFO_STREAM("msg recieved:");
	
	assign_min(msg.n, msg.arr);
	
	ROS_INFO_STREAM("n1:" << n1 << " n2:" << n2);
	ROS_INFO_STREAM("Diff:" << n2 - n1);


	ros::NodeHandle nh;	
	ros::Publisher pub = nh.advertise<dummy::answ>("answer", 1000);

	dummy::answ ms;
	ms.diff = n1 - n2;

	pub.publish(ms);
	ROS_INFO_STREAM("Message Sent!");
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "dummy");
	ros::NodeHandle nh;

	ros::Rate rate(2);
	ROS_INFO_STREAM("Started!");

	ros::Subscriber sb = nh.subscribe("dummy_topic", 1000, &msg_callback);
	ros::spin();
}
