#include <ros/ros.h>
int main(int argc ,char ** argv){
	ros :: init (argc,argv,"count_and_log");
	ros ::NodeHandle nh;
	ros :: Rate rate(10);
	for(int i=1;ros ::ok();i++){
		ROS_DEBUG_STREAM("Debug");
		if(i%3==0) ROS_INFO_STREAM("Info");
		if(i%5==0) ROS_WARN_STREAM("Warn");
		if(i%10==0) ROS_ERROR_STREAM("Error");
		if(i%20==0) ROS_FATAL_STREAM("FATAL");
		rate.sleep();
	}
}
