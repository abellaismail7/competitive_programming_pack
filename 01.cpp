#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fix(vector<long long> &v)
{
	int changed = 0;
	for (size_t i = 0; i < v.size() - 1; i++) {
		if (i < v.size() - 2 && (v[i] + v[i + 1] > v[i + 1] + v[i + 2]))
			continue;
		if (v[i] >= 0 && v[i + 1] >= 0)
			continue;
		if (v[i] + v[i + 1] >= 0)
			continue;
		changed = 1;
		v[i] = -v[i];
		v[i + 1] = -v[i + 1];
	}
	return changed;
}

int solve()
{
	int n;
	cin >> n;
	vector<long long> v;
	v.reserve(n);
	int neg = 0;
	while (n--)
	{
		long long a;
		cin >> a;
		v.push_back(a);	
		neg += (a < 0);
	}
	sort(v.begin(), v.end());
	size_t i = 0;
	while(i < v.size()) {
		if (i < neg - (neg % 2 == 1))
			v[i] = -v[i];
		else
		{
			if (i == neg - 1 && v[i] + v[i+1] < 0)
			{
				v[i] = -v[i];
				v[i+1] = -v[i+1];
			}
		}
		i++;
	}
	long long res = 0;
	for (auto n : v)
     	res += n;
	return res;
}

int main (int argc, char *argv[])
{
	int n;

	std::cin >> n;
	while (n--)
	{
		cout << solve() << "\n";
	}
	return 0;
}
