#include<ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc,char **argv){
	ros :: init (argc,argv,"sample_service");
	ros :: NodeHandle nh ;
	
	ros :: ServiceClient spawnClient
		=nh.serviceClient<turtlesim::Spawn>("spawn");
	turtlesim ::Spawn :: Request req ;
	turtlesim ::Spawn ::Response resp;
	
	req.x=2;
	req.y = 3;
	req.theta =3.14/2;
	req.name="leo";

	bool success = spawnClient.call(req,resp);
	if(success){
		ROS_INFO_STREAM("Succes");
	}
	else{
		ROS_INFO_STREAM("Failure");
	}
}
