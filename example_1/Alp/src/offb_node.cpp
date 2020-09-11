#include <ros/ros.h>

#include <meturone/answer.h>
#include <meturone_egitim/Dummy.h>
#include <vector>

int ans1=3;
int ans2=4;

void poseMessageReceived(const meturone_egitim::Dummy& msg) {
//ROS_INFO_STREAM(std::setprecision(2)<<std::fixed << "position=(" << msg.x << "," << msg.y << ")" << " direction=" << msg.theta);
	ans1 = msg.arr[0];
	ans2 = msg.arr[1];  
	ROS_INFO_STREAM("position=(" << ans1 << "," << ans2 << ")");
}


int main(int argc, char* argv[]){

    ros::init(argc, argv, "node1");
    ros::NodeHandle nh;

    //a publisher instance to publish the array
    ros::Publisher pub = nh.advertise<meturone::answer>(
        "/meturone/answer1",
        1000
    );
    
    ros::Subscriber sub = nh.subscribe("/dummy_topic",1000,&poseMessageReceived);

    ros::Rate rate(2);
    ROS_INFO_STREAM("Hello, ROS!");
    meturone::answer msg;
    
    
    while(ros::ok()){
        
        
        
        msg.n1 = ans1;
	msg.n2 = ans2;
        

        pub.publish(msg);
	ros::spinOnce();
    }
    return 0;
}

