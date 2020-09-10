#include <ros/ros.h>
#include<turtlesim/Pose.h>
#include<iomanip>

void poseMessageReceived(const turtlesim::Pose& msg){
	ROS_INFO_STREAM(std::setprecision(2)<<std::fixed << "pos =" << msg.x
		<<","<<msg.y);
}
int main(int argc ,char **argv){
	ros :: init(argc,argv,"sub_to_pose");
	ros :: NodeHandle nh;

	ros :: Subscriber sub = nh.subscribe("turtle1/pose",1000,
		&poseMessageReceived);
	ros::spin();
}
