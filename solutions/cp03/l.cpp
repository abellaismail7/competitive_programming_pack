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
				int val = 0;
				for (int k = 0; k < this->m; k++) {
					val += (get(i, k) * b.get(k, j)) % mod;
					val %= mod;
				}
				res.set(i, j, val);
			}
		}
		return res;
	}

	Matrix binexp(Matrix n, int exp)
	{
		if (exp == 0)
	        return (Matrix(2,2, 1));
	    Matrix res = binexp(n, exp/2);
	    if (exp%2)
			return res * res * n;
	    else
			return res * res;
	}

	void set(int row, int col, int val)
	{
		this->arr[row][col] = val;
	}

	int get(int row, int col)
	{
		return arr[row][col];
	}

	void print()
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				std::cout << get(i, j) << ' ';
			}
			cout << '\n';
		}
	}
};

void get_matrix(Matrix &mat)
{
	for (int i = 0; i < mat.n; i++){
		for (int j = 0; j < mat.m; j++){
			int val;
			cin >> val;
			mat.set(i, j, val);
		}
	}
}

int main (int argc, char *argv[])
{
	int m,n, n1,q;

	cin >> m >> n;
	Matrix mat1(m, n);
	get_matrix(mat1);
	cin >> n1 >> q;
	Matrix mat2(n1, q);
	get_matrix(mat2);
	if (n != n1)
	{
		std::cout << "-1" << std::endl;
		return 0;
	}
	std::cout << m << " " << q << '\n';
 
	Matrix res = (mat1 * mat2);
	res.print();
	return 0;
}
