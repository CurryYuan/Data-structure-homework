#ifndef RUNWAY_HPP
#define RUNWAY_HPP
#include "Plane.hpp"
#include <queue>
#include <stack>
#include <iomanip>
#include <cstdlib>
using namespace std;

enum Runway_activity { idle, land, forced_landing, takeoff };

class Runway {
public:
	Runway(int limit) {
		queue_limit = limit;
		num_land_requests = num_takeoff_requests = 0;
		num_landings = num_takeoffs = 0;
		num_land_refused = num_takeoff_refused = 0;
		num_land_accepted = num_takeoff_accepted = 0;
		land_wait = takeoff_wait = idle_time = 0;
	}
	bool can_land(const Plane &current) {
		bool result;
		if (landing.size() < queue_limit) {
			landing.push(current);
			result = true;
		}
		else
			result = false;
		num_land_requests++;
		if (result != true)
			num_land_refused++;
		else
			num_land_accepted++;
		return result;
	}
	bool can_depart(const Plane &current) {
		bool result;
		if (takingoff.size() < queue_limit) {
			takingoff.push(current);
			result = true;
		}
		else
			result = false;
		num_takeoff_requests++;
		if (result != true)
			num_takeoff_refused++;
		else
			num_takeoff_accepted++;
		return result;
	}
	Runway_activity activity(int time, Plane &moving) {
		Runway_activity in_progress;
		int numEmergencyPlane = 0;
		int position = 0;
		if (!landing.empty()) {
			iteration(numEmergencyPlane, position);
			if (numEmergencyPlane > 1) { cout << "The airport blow up because of the plane crash!!!!!" << endl; exit(0); }
			else if (numEmergencyPlane == 1) {
				moving = remove_plane(position);
				land_wait += time - moving.started();
				num_landings++;
				in_progress = forced_landing;
			}
			else if (numEmergencyPlane == 0) {
				moving = landing.front();
				land_wait += time - moving.started();
				num_landings++;
				in_progress = land;
				landing.pop();
			}
		}
		else if (!takingoff.empty()) {
			moving = takingoff.front();
			takeoff_wait += time - moving.started();
			num_takeoffs++;
			in_progress = takeoff;
			takingoff.pop();
		}
		else {
			idle_time++;
			in_progress = idle;
		}
		decrease_oil();
		return in_progress;
	}
	void shut_down(int time)const {
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "Simulation has conluded after " << time << " time units." << endl;
		cout << setw(60) << left << "Total number of planes processed:"
			<< (num_land_requests + num_takeoff_requests) << endl
			<< setw(60) << left << "Total number of planes asking to land:"
			<< num_land_requests << endl
			<< setw(60) << left << "Total number of planes asking to take off:"
			<< num_takeoff_requests << endl
			<< setw(60) << left << "Total number of planes accepted for landing:"
			<< num_land_accepted << endl
			<< setw(60) << left << "Total number of planes accepted for takeoff:"
			<< num_takeoff_accepted << endl
			<< setw(60) << left << "Total number of planes refused for landing:"
			<< num_land_refused << endl
			<< setw(60) << left << "Total number of planes refused for takeoff:"
			<< num_takeoff_refused << endl
			<< setw(60) << left << "Total number of planes that landed:"
			<< num_landings << endl
			<< setw(60) << left << "Total number of planes that took off:"
			<< num_takeoffs << endl
			<< setw(60) << left << "Total number of Planes left in landing queue:"
			<< landing.size() << endl
			<< setw(60) << left << "Total number of planes left in takeoff queue:"
			<< takingoff.size() << endl;
		cout << setw(60) << left << "Percentage of time runway idle:"
			<< 100.0 * ((float)idle_time) / ((float)time) << " % " << endl;
		cout << setw(60) << left << "Average wait in landing queue:"
			<< ((num_landings==0)?num_landings:(float)land_wait / (float)num_landings) << " time units" << endl
			<< setw(60) << left << "Average wait in takeoff queue:"
			<< (num_takeoffs==0?num_takeoffs:(float)takeoff_wait) / ((float)num_takeoffs)
			<< " time units" << endl;
		cout << setw(60) << left << "Average observed rate of planes wanting to land:"
			<< ((float)num_land_requests) / ((float)time)
			<< " time unit" << endl;
		cout << setw(60) << left << "Average observed rate of planes wanting to take off:"
			<< ((float)num_takeoff_requests) / ((float)time)
			<< " time unit" << endl;
	}
private:
	queue<Plane> landing;
	queue<Plane> takingoff;
	int queue_limit;			//max of the queue
	int num_takeoff_requests;   //number of planes asking to takeoff 
	int num_land_requests; 		//number of planes asking to land
	int num_landings;			//number of planes that have landed
	int num_takeoffs; 			//number of planes that have taken off
	int num_land_accepted;		//number of planes queued to land
	int num_takeoff_accepted;   //number of planes queued to take of 
	int num_land_refused;       //number of landing planes refused 
	int num_takeoff_refused;    //number of departing planes refused
	int land_wait;				//total time of planes waiting to land 
	int takeoff_wait;			//total time of planes waiting to take off
	int idle_time;				//total time runway is idle
	Plane remove_plane(int position) {
		queue<Plane> temp;
		Plane temp_plane;
		for (int i = 0; i<position; i++) {
			temp.push(landing.front());
			landing.pop();
		}
		temp_plane = landing.front();
		landing.pop();
		while(!landing.empty()){
			temp.push(landing.front());
			landing.pop();
		}
		while(!temp.empty()) {
			landing.push(temp.front());
			temp.pop();
		}
		return temp_plane;
	}
	void decrease_oil() {
		queue<Plane> temp;
		while(!landing.empty()) {
			landing.front().set_oil(landing.front().get_oil() - 1);
			temp.push(landing.front());
			landing.pop();
		}
		while(!temp.empty()) {
			landing.push(temp.front());
			temp.pop();
		}
	}
	void iteration(int& numEmergencyPlane, int &position) {
		queue<Plane> temp = landing;
		while(!temp.empty()){
			if (temp.front().get_oil() <= 1) {
				numEmergencyPlane++;
			}
			temp.pop();
		}
		temp = landing;
		while(!temp.empty()) {
			if (temp.front().get_oil() <= 1) {
				break;
			}
			position++;
			temp.pop();
		}
	}

};

#endif


