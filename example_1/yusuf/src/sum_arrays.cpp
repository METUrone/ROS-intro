#include <ros/ros.h>
#include <meturone_egitim/Dummy.h>
#include <meturone_egitim/answer.h>
#include <vector>


unsigned long long int sum;

void callBack(const meturone_egitim::Dummy& msg){
    sum = 0;

    for(int i=0, n = msg.n; i < n; i++){
        sum = msg.arr[i];
    }
}

int main(int argc, char** argv){

    ros::init(argc, argv, "sum_arrays");
    ros::NodeHandle nh;

    //subscribe to dummy_topic
    ros::Subscriber sub = nh.subscribe("dummy_topic", 1000, callBack);

    //Create a publisher object
    ros::Publisher pub = nh.advertise<meturone_egitim::answer>("answer", 1000);

    meturone_egitim::answer msg;


    ros::Rate rate(2);

    while(ros::ok()){
        ros::spinOnce();

        msg.n = sum;

        pub.publish(msg);

        ROS_INFO_STREAM("sum of this array is =" << sum);

    }




    return 0;
}
