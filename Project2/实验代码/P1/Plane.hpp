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
		state = null;
	}
	Plane(int flt, int time, Plane_status status) {
		flt_num = flt;
		clock_start = time;
		state = status;
		cout << "Plane number:" << flt << " ready to ";
		if (status == arriving)
			cout << "land." << endl;
		else
			cout << "take off." << endl;
	}
	void refuse()const {
		cout << "Plane number:" << flt_num;
		if (state == arriving)
			cout << " directed to another ariport." << endl;
		else
			cout << " told to try takeoff again later." << endl;
	}
	void land(int time)const {
		int wait = time - clock_start;
		cout << "Time: " << time << endl;
		cout << "Plane number " << flt_num << " landed after "
			<< wait << " time unit" << ((wait == 1) ? "" : "s")
			<< " in the takeoff queue." << endl;
	}
	void fly(int time)const {
		int wait = time - clock_start;
		cout << "Time: "<<time << endl;
		cout<< "Plane number " << flt_num << " took off after "
			<< wait << " time unit" << ((wait == 1) ? "" : "s")
			<< " in the takeoff queue." << endl;
	}
	int started()const {
		return clock_start;
	}

private:
	int flt_num;
	int clock_start;
	Plane_status state;
};

#endif
