#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int count_pos(int st, int n)
{
	int res = 0;
	if (n == 0)
		return 0;
	
	res += count_pos(st, n);

	return res + 1;
}

int main (int argc, char *argv[])
{
	int n;

	std::cin >> n;

	count_pos(6, 8);
	return 0;
}
	
//int main ()
//{
//	int n;
//	std::cin >> n;
//
//	while (n--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		long long abc =  (a + b + c);
//		int m = std::min({a, b , c});
//		if (abc > 9 && m < (abc / 9))
//		{
//			std::cout << "NO" << '\n';
//			continue;
//		}
//
//		if (abc % 9 == 0)
//			std::cout << "YES" << '\n';
//		else
//			std::cout << "NO" << '\n';
//
//	}
//
//	return 0;
//}
//
