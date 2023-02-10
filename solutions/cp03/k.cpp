#include <iomanip>
#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
typedef vector<ll> vi;

int mod (1e9 + 7);


int solve()
{
	ll str, intl, exp;

	cin >> str >> intl >> exp;
	if (intl >= str + exp)
			return 0;

	ll diff = 0;
	if (intl >= str)
	{
		diff = intl - str + 1;
		str += diff;
		exp -= diff;
	}


	ll l,r;

	l = exp;
	r = 0;
	while (1)
	{
		ll mid = (l + r) / 2;
		ll rest = exp - mid;
		if (str + rest > intl + mid)
		{
			if (str + rest - 1 <= intl + mid + 1)
				return exp - rest + 1;
			r = mid;
		}
		else
			l = mid;
	}
	return 1;
}

int main ()
{
	ll test_case;

	std::cin >> test_case;

	while (test_case--)
	{
		std::cout << solve() << std::endl;
	}
	
	return 0;
}
