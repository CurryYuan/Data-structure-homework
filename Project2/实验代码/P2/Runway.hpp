#ifndef RUNWAY_HPP
#define RUNWAY_HPP
#include "Plane.hpp"
#include <queue>
#include <iomanip>
using namespace std;

enum Runway_activity { idle, land, takeoff };

class Runway {
public:
	Runway(int limit);
	bool can_land(const Plane &current);
	bool can_depart(const Plane &current);
	Runway_activity activity(int time, Plane &moving);
	static void shut_down(int time);
	void shut();
private:
	queue<Plane> landing;
	queue<Plane> takingoff;
	int queue_limit;			        //max of the queue
	int number;
	static int runway_number;
	static int num_takeoff_requests;    //number of planes asking to takeoff 
	static int num_land_requests; 		//number of planes asking to land
	static int num_landings;			//number of planes that have landed
	static int num_takeoffs; 			//number of planes that have taken off
	static int num_land_accepted;		//number of planes queued to land
	static int num_takeoff_accepted;    //number of planes queued to take of 
	static int num_land_refused;        //number of landing planes refused 
	static int num_takeoff_refused;     //number of departing planes refused
	static int land_wait;				//total time of planes waiting to land 
	static int takeoff_wait;			//total time of planes waiting to take off
	static int idle_time;				//total time runway is idle
	static int landing_size;
	static int takingoff_size;
};

#endif
