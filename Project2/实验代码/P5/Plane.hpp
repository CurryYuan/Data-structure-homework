#ifndef PLANE_HPP
#define PLANE_HPP
#include <iostream>
#include <string>
using namespace std;

enum Plane_status { null, arriving, departing };

class Plane {
public:
	Plane() {
		flt_num = -1;
		clock_start = -1;
		oil = -1;
		state = null;
	}
	Plane(int flt, int time, int oil, Plane_status status) {
		flt_num = flt;
		clock_start = time;
		state = status;
		this->oil = oil;
		if (status == arriving) {
			cout << "Plane number: " << flt << " with " << oil
				<< ((oil == 1) ? " unit" : " units") << " is ready to ";
			cout << "land." << endl;
		}
		else {
			cout << "Plane number: " << flt << " is ready to ";
			cout << "take off." << endl;
		}
	}
	void refuse()const {
		cout << "Plane number: " << flt_num;
		if (state == arriving)
			cout << " directed to another ariport." << endl;
		else
			cout << " told to try takeoff again later." << endl;
	}
	void land(int time)const {
		int wait = time - clock_start;
		cout << "Plane number " << flt_num << " landed after "
			<< wait << " time unit" << ((wait == 1) ? "" : "s")
			<< " in the takeoff queue." << endl;
	}
	void fly(int time)const {
		int wait = time - clock_start;
		cout<< "Plane number " << flt_num << " took off after "
			<< wait << " time unit" << ((wait == 1) ? "" : "s")
			<< " in the takeoff queue." << endl;
	}
	int started()const {
		return clock_start;
	}
	void Forced_landing(int time) const{
		int wait = time - clock_start;
		cout << "Plane number: " << flt_num;
		cout << " landed immediately because of the limit of the oil." << endl;
	}
	int get_oil(){
		return oil;
	}
	void set_oil(int oil) {
		this->oil = oil;
	}
private:
	int flt_num;
	int clock_start;
	Plane_status state;
	int oil;
};

#endif


