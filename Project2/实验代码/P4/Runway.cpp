#include "Runway.hpp"

int Runway::num_land_requests = 0;
int Runway::num_takeoff_requests = 0;
int Runway::num_landings = 0;
int Runway::num_takeoffs = 0;
int Runway::num_land_refused = 0;
int Runway::num_takeoff_refused = 0;
int Runway::num_land_accepted = 0;
int Runway::num_takeoff_accepted = 0;
int Runway::land_wait = 0;
int Runway::takeoff_wait = 0;
int Runway::idle_time = 0;
int Runway::runway_number = 0;
int Runway::landing_size = 0;
int Runway::takingoff_size = 0;

Runway::Runway(int limit) {
	runway_number++;
	number = runway_number;
	queue_limit = limit;
}
bool Runway::can_land(const Plane &current) {
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
bool Runway::can_depart(const Plane &current) {
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
Runway_activity Runway::activity(int time, Plane &moving) {
	Runway_activity in_progress;
	if (!landing.empty()) {
		moving = landing.front();
		land_wait += time - moving.started();
		num_landings++;
		in_progress = land;
		landing.pop();
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
	return in_progress;
}

void Runway::shut_down(int time) {
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
		<< landing_size << endl
		<< setw(60) << left << "Total number of planes left in takeoff queue:"
		<< takingoff_size << endl;
	cout << setw(60) << left << "Percentage of time runway idle:"
		<< 100.0 * ((float)idle_time) / ((float)time * 2) << " % " << endl;
	cout << setw(60) << left << "Average wait in landing queue:"
		<< ((num_landings == 0) ? num_landings : (float)land_wait / (float)num_landings) << " time units" << endl
		<< setw(60) << left << "Average wait in takeoff queue:"
		<< (num_takeoffs == 0 ? num_takeoffs : (float)takeoff_wait) / ((float)num_takeoffs) << " time units" << endl;
	cout << setw(60) << left << "Average observed rate of planes wanting to land:"
		<< ((float)num_land_requests) / ((float)time)
		<< " time unit" << endl;
	cout << setw(60) << left << "Average observed rate of planes wanting to take off:"
		<< ((float)num_takeoff_requests) / ((float)time)
		<< " time unit" << endl;
}

void Runway::shut()
{
	landing_size += landing.size();
	takingoff_size += takingoff.size();
}

void Runway::run_idle()
{
	cout << "Runway " << number << " is idle. " << endl;
}

int Runway::landing_Size()
{
	return landing.size();
}

int Runway::takingoff_Size()
{
	return takingoff.size();
}
