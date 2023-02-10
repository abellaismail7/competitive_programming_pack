#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

class DSU
{
public:
	DSU(){

	}

	void make_set(vector<ll> &v)
	{
		vec = v;
	}

	void union_set(int a, int b)
	{
		int mn = min(a,b);
		int mx = max(a,b);

		vec[mx] = vec[mn];
	}

private:
	vector<ll> vec;
	ll size;
	
};
