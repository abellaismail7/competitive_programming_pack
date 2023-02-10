#include <iomanip>
#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
typedef vector<double> vi;

double mod (1e9 + 7);

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
				double val = 0;
				for (int k = 0; k < this->m; k++) {
					val += std::fmod((get(i, k) * b.get(k, j)), mod);
					val = std::fmod(val, mod);
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

	void set(int row, int col, double val)
	{
		this->arr[row][col] = val;
	}

	double get(int row, int col)
	{
		return arr[row][col];
	}


	void print()
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
	}

};

long long binexp(long long n, long long exp, int mod)
{
	if (exp == 0)
		return 1;
	long long res = binexp(n, exp / 2, mod);
	if (exp % 2 == 0)
		return res * res % mod;
	return (((res * res) % mod) * n) % mod;
}


int main (int argc, char *argv[])
{
	ll n;
	double p;

	cin >> n >> p;
	
	Matrix r(2, 2);
	r.set(0,0, 1 - p);
	r.set(0,1, p);
	r.set(1,0, p);
	r.set(1,1, 1 - p);
	Matrix resu = r ^ n;

	cout << std::setprecision(10) << std::fixed << resu.get(0, 0) << endl;
}
