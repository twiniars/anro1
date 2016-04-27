#include "ros/ros.h"
#include "std_msgs/String.h"
#include "anro1/accessPoint.h"
#include "anro1/direction.h"
#include "anro1/mapNode.h"
#include "anro1/mapNodeMessage.h"
#include "anro1/mapRoute.h"
#include "anro1/mapRouteMessage.h"
#include "anro1/node.h"
#include "anro1/nodeMessage.h"
#include "anro1/point.h"
#include "anro1/route.h"
#include "anro1/routemsg.h"
#include "anro1/side.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <sstream>
#include <list>
#include <queue>
using namespace std;

void process(const anro1::nodeMessage::ConstPtr& msg){
    vector<anro1::node> nodes = msg->nodes;
    //				

//ROS_INFO("begin");
for(int i=0;i<nodes.size();i++){
	ROS_INFO("count");


																																														
    anro1::node node = nodes[i];
	vector<anro1::accessPoint> aps = node.n;
	for(int j=0;j<aps.size();j++){
	ROS_INFO("count2");
		anro1::accessPoint ap = aps[j];
		vector<anro1::point> points = ap.straight;
		for(int m=0;m<points.size();m++){
			anro1::point p= points[m];
			if(p.x==1){
				ROS_INFO("OK");
}
			else {
				ROS_INFO("NIEOK");
				}	
			
}

}

    }
ROS_INFO("END");
   // ROS_INFO("Turn recieved %d %d", (int)p.x, (int)p.y);   																					
}
int main(int argc, char **argv)
{
																																		


    ros::init(argc, argv, "Turns");

	
    ros::NodeHandle n;
//ros::Publisher chatter2 = n.advertise<anro1::direction>("test",10);
   // ros::Publisher chatter_pub = n.advertise<anro1::turnsVector>("turns_info", 10);
    ros::Subscriber sub = n.subscribe("nodes_info", 20, process);
    ros::Rate loop_rate(10);
    //anro1::turn turnmsg;
   // anro1::turnsVector turnVector;

  // ROS_INFO("INIT");

    while (ros::ok())
    {
        ros::spinOnce();
        /*if(!ready){
            continue;
        }
        anro1::turnsVector turnVector;
        turnVector.size = 0;

        for (list<Turn>::iterator it = turns.giveList()->begin(); it != turns.giveList()->end(); it++)
        {
            anro1::turn turnmsg;
            turnmsg.x = (*it).x;
            turnmsg.y = (*it).y;
            turnmsg.NS = (*it).north;
            turnmsg.WE = (*it).west;
            turnVector.turns.push_back(turnmsg);
            turnVector.size++;
        }

        chatter_pub.publish(turnVector);
*/

        loop_rate.sleep();

    }

    return 0;
}
