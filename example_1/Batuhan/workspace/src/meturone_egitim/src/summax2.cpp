#include <ros/ros.h>
#include <meturone_egitim/Dummy.h>
#include <meturone_egitim/answer.h> //???
#include <vector>

int max1;
int max2;
int sum;
int flag;

// maybe copying vector and processing under main function
// would be wiser choice

// garip bir şekilde pointer atıp, sanki 
// objeymiş gibi özelliklerini . ile kullanıyoruz why?
void process_publish(const meturone_egitim::Dummy& msg) {
    //find max two of elements
    //msg.n'i kullanaydık iyiydi verim olarak
    int index;
    max1 = msg.arr[0];
    for(int i = 0; i < msg.n; i++) {
        if(max1 < msg.arr[i]) {
            max1 = msg.arr[i];
            index = i;
        }
    }
    
    max2= msg.arr[0];
    for(int i=0; i<msg.n; i++) {
        if((max2 < msg.arr[i]) && (i!=index)) {
            max2 = msg.arr[i];
        }
    }
    
    sum = max1+max2;
    ROS_INFO_STREAM("Calculated the sum as : "
    << sum);
}

int main(int argc, char *argv[]) {
    //initialize the ros system and become node
    ros::init(argc, argv,  "sum_first_second_max");
    ros::NodeHandle nh;
    
    //create subscriber and publisher objects (1000 is the number of max msgs per second)
    ros::Subscriber sub = nh.subscribe("dummy_topic", 1000, &process_publish);
    ros::Publisher pub = nh.advertise<meturone_egitim::answer>("answer", 1000); //???
    
    
    meturone_egitim::answer msg;
    
     while(ros::ok()){
        msg.sum = sum;
        pub.publish(msg);
        ros::spinOnce();
    }
}





