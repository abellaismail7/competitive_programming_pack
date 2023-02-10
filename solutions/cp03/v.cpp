#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
typedef vector<ll> vi;

ll mod (1e9 + 7);

struct Matrix {
	vector<vi> arr;
	int m;
	int n;
	
	Matrix(vector<vi> arr, int n, int m)
	{
		this->arr = arr;
		this->m = m;
		this->n = n;
	}

	Matrix(int n, int m) : Matrix(n, m, 0) { }

	Matrix(int n, int m, int type)
	{
		arr.assign(n, vi(m, 0));
		if (type == 1)
		{
			if (m != n)
				abort();
			for (int i = 0; i < m; i++) {
				set(i, i, 1);
			}	
		}
		this->m = m;
		this->n = n;
	}

	Matrix operator * (Matrix b)
	{
		Matrix res(this->n, b.m);
		for (int i = 0; i < this->n; i++) {
			for (int j = 0; j < b.m; j++) {
				ll val = 0;
				for (int k = 0; k < this->m; k++) {
					val += (get(i, k) * b.get(k, j)) % mod;
					val %= mod;
				}
				res.set(i, j, val);
			}
		}
		return res;
	}

	Matrix operator ^ (const ll &p)
    {
        return binexp(*this,p);
    }

	Matrix binexp(Matrix mat, ll exp)
	{
		if (exp == 0)
	        return (Matrix(mat.n, mat.n, 1));
	    Matrix res = binexp(mat, exp/2);
	    if (exp%2)
			return res * res * mat;
	    else
			return res * res;
	}

	void set(int row, int col, ll val)
	{
		this->arr[row][col] = val;
	}

	ll get(int row, int col)
	{
		return arr[row][col];
	}

	void print()
	{
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++) {
				std::cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
	}
};

int main (int argc, char *argv[])
{
	ll n;
	Matrix fib6(6, 1);
	fib6.set(0, 0, 32);
	fib6.set(1, 0, 16);
	fib6.set(2, 0, 8);
	fib6.set(3, 0, 4);
	fib6.set(4, 0, 2);
	fib6.set(5, 0, 1);

	cin >> n;
	if (n < 6)
	{
		std::cout << fib6.get(6 - n, 0) << std::endl;
		return 0;
	}
	 n -= 6;
	
	Matrix m1(6, 6);
	m1.set(0, 0, 1);
	m1.set(0, 1, 1);
	m1.set(0, 2, 1);
	m1.set(0, 3, 1);
	m1.set(0, 4, 1);
	m1.set(0, 5, 1);

	m1.set(1, 0, 1);

	m1.set(2, 1, 1);
	m1.set(3, 2, 1);
	m1.set(4, 3, 1);
	m1.set(5, 4, 1);


	Matrix res = (m1 ^ n) * fib6;
	cout << res.get(0, 0) << endl;
}

