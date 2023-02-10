#include <iostream>
#include <vector>

#define ll long long

using namespace std;

struct Res
{
	ll sum;
	bool is_signed;
};

ll build(vector<ll> &t, int begin[], int end[], int index)
{
	if (end == begin)
	{
		t[index - 1] = begin[0];
		return t[index - 1];
	}
	int diff = end - begin;
	t[index - 1] = build(t, begin, begin + diff/2, index * 2) + build(t, begin + 1 + diff / 2, end, index * 2 + 1);
	return t[index - 1];
}

Res mx(vector<ll> &t, int pos, int tl, int tr, int l, int r)
{
	Res res;
	res.sum  = -1e18;
	if (l > r)
		return res;
	if (tl == l && tr == r)
	{
		res.is_signed = tl < 0;
		res.sum = t[pos - 1];
		return res;
	}
	int half = (tl+tr)/2;
	Res left = mx(t, pos*2, tl, half, l, min(r, half));
	Res right = mx(t, pos*2+1, half+1, tr, max(l, half +1) , r);
	if (left.is_signed || right.is_signed)
	{
		res.is_signed = 1;
		res.sum = max(left.sum, left.sum);
		return res;
	}
	res.sum = left.sum + right.sum;
	res.is_signed = 0;
	return res;
}

ll update(vector<ll> &t, int pos, int tl, int tr, int pup, int val)
{
	if (pup > tr || pup < tl)
		return t[pos - 1];
	if (tl == tr)
		return (t[pos - 1] = val, val);
	int half = (tl+tr)/2;
	t[pos -1] = update(t, pos*2, tl, half, pup, val) + update(t, pos*2+1, half+1, tr, pup, val);
	return t[pos -1];
}

int main (int argc, char *argv[])
{
	int n,q;

	std::cin >> n;

	vector<long long>  t(4*n, 0);
	int arr[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	build(t, arr, arr + n - 1, 1);
	int op, x, y;
	std::cin >> q;
	while (q--)
	{
		std::cin >> op >> x >> y;
		x--;
		if (op == 0)
		{
			update(t, 1, 0, n - 1, x, y);
			continue;
		}
		y--;
		std::cout << mx(t, 1, 0, n - 1, x, y).sum << std::endl;
	}
	//std::cout << "===" << std::endl;
	//for (auto e:t) {
	//	std::cout << e << std::endl;
	//}
	return 0;
}
