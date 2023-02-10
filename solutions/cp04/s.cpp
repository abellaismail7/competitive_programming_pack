#include <iostream>
#include <vector>

#define ll long long

using namespace std;

struct Res
{
	ll sum;
	bool is_sum;
};

Res &rescmp(Res &a, Res &b)
{
	if (a.sum >  b.sum)
		return a;
	return b;
}

Res build(vector<Res> &t, int begin[], int end[], int index)
{
	t[index - 1].is_sum = 1;
	if (end == begin)
	{
		t[index - 1].sum = begin[0];
		t[index - 1].is_sum = begin[0] >= 0;
		return t[index - 1];
	}
	int diff = end - begin;
	Res left = build(t, begin, begin + diff/2, index * 2);
	Res right = build(t, begin + 1 + diff / 2, end, index * 2 + 1);
	if (left.is_sum && right.is_sum)
		t[index - 1].sum =  left.sum + right.sum;
	else
	{
		Res max = rescmp(left, right);
 		t[index - 1] = max;
		t[index-1].is_sum = !left.is_sum && right.is_sum && &right ==  &max;
	}
	return t[index - 1];
}

Res mx(vector<Res> &t, int pos, int tl, int tr, int l, int r)
{
	Res res{-10000000, 0};
	if (l > r)
		return res;
	if (tl == l && tr == r)
		return t[pos - 1];
	int half = (tl+tr)/2;
	Res left = mx(t, pos*2, tl, half, l, min(r, half));
	Res right = mx(t, pos*2+1, half+1, tr, max(l, half +1) , r);
	if (!left.is_sum || !right.is_sum)
		return rescmp(left, right);
	res.sum = left.sum + right.sum;
	res.is_sum =  1;
	return res;
}

Res update(vector<Res> &t, int pos, int tl, int tr, int pup, int val)
{
	if (pup > tr || pup < tl)
		return t[pos - 1];
	if (tl == tr)
		return (t[pos -1 ] = Res{val, val >= 0}, t[pos - 1]);
	int half = (tl+tr)/2;
	Res left = update(t, pos*2, tl, half, pup, val);
	Res right = update(t, pos*2+1, half+1, tr, pup, val);
	if (left.is_sum && right.is_sum)
		t[pos -1] = Res{left.sum + right.sum, 1};
	else{
		Res max = rescmp(left, right);
 		t[pos - 1] = max;
		t[pos - 1].is_sum = !left.is_sum && right.is_sum && &right ==  &max;
	}
	return t[pos -1];
}

int main (int argc, char *argv[])
{
	int n,q;

	std::cin >> n;

	vector<Res> t(4*n);
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
	std::cout << "===" << std::endl;
	for (auto e:t) {
		std::cout << e.sum << '(' << e.is_sum << ')' << std::endl;
	}
	return 0;
}
