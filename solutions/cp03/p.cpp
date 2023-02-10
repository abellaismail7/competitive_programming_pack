#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <float.h>

double binexp(double n, int exp)
{
	if (exp == 0)
		return 1;
	double res = binexp(n, exp / 2);
	if (exp % 2 == 0)
		return res * res;
	return res * res * n;
}

int main ()
{
	int a,b,c;
	double d;
	std::cin >> a >> b >> c >> d;
	d = -d;

	double l = 0, r = d;
	while (1)
	{
		double mid = l + (r - l) / 2.0;
		double mid2 = mid * mid;
		double res = a * mid * mid2 + b * mid2 + c * mid;

		if (res == d)
		{
			std::cout << res << std::endl;
			printf("%.6f\n", mid);
			break;
		}
		else if (res > d)
			r = mid;
		else
			l = mid;
	}

	return 0;
}
