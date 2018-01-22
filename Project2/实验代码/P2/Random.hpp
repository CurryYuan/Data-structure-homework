#include <iostream>
#include <string>
#include <random>
#include <ctime> 
#include <cmath>
#include <climits>
#include <cstdlib>
using namespace std;

class Random {
private:

	double U_Random()   /* 产生一个0~1之间的随机数 */
	{
		double f;
		f = (float)(rand() % 100);
		/* printf("%fn",f); */
		return f / 100;
	}
public:
	int poisson(double mean)  /* 产生一个泊松分布的随机数，Lamda为总体平均数*/
	{
		double Lambda = mean, k = 0;
		long double p = 1.0;
		long double l = exp(-Lambda);  /* 为了精度，才定义为long double的，exp(-Lambda)是接近0的小数*/
		while (p >= l)
		{
			double u = U_Random();
			p *= u;
			k++;
		}
		return k - 1;
	}
};

