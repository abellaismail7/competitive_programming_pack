#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#include <deque>
#include <functional>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <string_view>
#include <set>

using namespace std;
#define ll long long
#define PQ priority_queue
#define V vector
#define S set
#define M map
#define O cout << 
#define I cin << 
#define SPL <<' '<<
#define endl '\n'


#define R1(x) cin >> x;
#define R2(x,y) cin >> x >> y;
#define R3(x,y,z) cin >> x >> y >> z

struct Patient {
	ll p;
	ll o;
	string s;

	Patient(ll p, ll o, string s)
	{
		this->p = p;
		this->o = o;
		this->s = s;
	}

};


struct by_name { 
    bool operator()(Patient const &a, Patient const &b) const { 
		if (a.p == b.p)
		{
			if (a.o == b.o)
				return a.s < b.s;
			return a.o < b.o;
		}
        return a.p > b.p;
    }
};

#include <map>
// #define MULTI_TEST_CASES
void solve()
{
	int n;
	vector<Patient> vec;

	R1(n);
	while (n--) {
		string s;
		ll p,o;
		R1(s);
		R2(p, o);
		vec.push_back(Patient(p, o, s));
	}
	sort(vec.begin(), vec.end(), by_name());
	for(auto p: vec)
	{
		cout << p.s << endl;
	}

}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;

#ifdef MULTI_TEST_CASES
	cin >> n;
#else
	n = 1;
#endif

	while (n--)
		solve();
	return 0;
}
