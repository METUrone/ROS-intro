#include<ros/ros.h>
#include <costum_msgs/hw1.h>
#include<iostream>
#include<costum_msgs/hw1answer.h>
int out=0;
void Message(const costum_msgs::hw1 &msg){
        int min=msg.arr[0];
	int max=msg.arr[0];
	for (int i=1;i<msg.n;i++){
		if(msg.arr[i]>max)
			max=msg.arr[i];
		if(msg.arr[i]<min)
			min=msg.arr[i];
	}
	out=max+min;
	ROS_INFO_STREAM("arr[0]= "<<msg.arr[0]);
}
int main(int argc ,char **argv){
	ros :: init(argc,argv,"hw1_publisher");
	ros :: NodeHandle nh;

	ros :: Subscriber sub= nh.subscribe("dummy_topic",1000,&Message);
	ros :: Publisher pub =nh.advertise<costum_msgs::hw1answer>("answer",1000);
	costum_msgs::hw1answer msg;
	while (ros::ok()){
		msg.n=out;
		pub.publish(msg);
		ros::spinOnce();
	}
}
