#include <iostream>
#include <string>
#include <random>
#include <time.h> 
#include <math.h>
#include <climits>
#include <cstdlib>
using namespace std;

class Random {
private:


	double U_Random()   /* 2：2：|：2：＜???0~1????|━????：2：oy */
	{
		double f;
		f = (float)(rand() % 100);
		/* printf("%fn",f); */
		return f / 100;
	}
public:
	Random() {
		srand((unsigned)time(NULL));
	}
	int poisson(double mean)  /* 2：2：|：2：＜???2???：|?∴?2?|━????：2：oy?┷?Lamda?a?│：1：?????：＞：oy*/
	{
		double Lambda = mean, k = 0;
		long double p = 1.0;
		long double l = exp(-Lambda);  /* ?a：♂????：：?┷?2???′：＜??along double|━??┷?exp(-Lambda)：o??：??：10|━?D?：oy*/
		while (p >= l)
		{
			double u = U_Random();
			p *= u;
			k++;
		}
		return k - 1;
	}
};
