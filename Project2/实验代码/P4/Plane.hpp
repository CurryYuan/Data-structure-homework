#ifndef PLANE_HPP
#define PLANE_HPP
#include <iostream>
#include <string>
using namespace std;

enum Plane_status { null, arriving, departing };

class Plane {
public:
	Plane();
	Plane(int flt, int time, Plane_status status);
	void refuse()const;
	void land(int time, int num)const;
	void fly(int time, int num)const;
	int started()const;

private:
	int flt_num;
	int clock_start;
	Plane_status state;
};

#endif

