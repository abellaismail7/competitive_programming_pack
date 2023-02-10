#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll build(vector<ll> &t, int begin[], int end[], int index)
{
	if (end == begin)
	{
		t[index - 1] = begin[0];
		return t[index - 1];
	}
	int diff = end - begin;
	t[index - 1] += min(build(t, begin, begin + diff/2, index * 2), build(t, begin + 1 + diff / 2, end, index * 2 + 1));
	return t[index - 1];
}

ll mn(vector<ll> &t, int pos, int tl, int tr, int l, int r)
{
	if (l > r)
		return 1e18;
	if (tl == l && tr == r)
		return t[pos - 1];
	int half = (tl+tr)/2;
	return min(mn(t, pos*2, tl, half, l, min(r, half)), mn(t, pos*2+1, half+1, tr, max(l, half +1) , r));
}

ll update(vector<ll> &t, int pos, int tl, int tr, int pup, int val)
{
	if (pup > tr || pup < tl)
		return t[pos - 1];
	if (tl == tr)
		return (t[pos - 1] = val, val);
	int half = (tl+tr)/2;
	t[pos -1] = min(update(t, pos*2, tl, half, pup, val), update(t, pos*2+1, half+1, tr, pup, val));
	return t[pos -1];
}

int main (int argc, char *argv[])
{
	int n,q;

	std::cin >> n >> q;

	vector<long long>  t(4*n, 0);
	int arr[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	build(t, arr, arr + n - 1, 1);
	int query, x, y;
	while (q--)
	{
		std::cin >> query >> x >> y;
		x--;
		if (query == 1)
		{
			update(t, 1, 0, n - 1, x, y);
			continue;
		}
		y--;
		std::cout << mn(t, 1, 0, n - 1, x, y) << std::endl;
	}
	//std::cout << "===" << std::endl;
	//for (auto e:t) {
	//	std::cout << e << std::endl;
	//}
	return 0;
}
