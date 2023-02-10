#include <iomanip>
#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>
#include <complex>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;


#define ll long long
typedef vector<ll> vi;

const int mod = (int)1e9 + 7;
class Matrix{
    int n,m;
    vector<vi > mat;
    public:
    Matrix(int n,int m, int type)
    {
        this->n=n;
        this->m=m;
        mat.assign(n,vi(m,0));
        if(type==1)
        {
            for(int i = 0;i < n;i++)
                mat[i][i]=1;
        }
        if(type==2)
        {
            for(int i = 0;i < n;i++)
                for(int j = 0;j < i;j++)
                mat[i][j]=1;
        }
        if (type == 3)
        {
           for(int j = 0;j < n;j++)
                mat[0][j]=1;
            for(int i = 1;i < n;i++)
                mat[i][i-1]=1;
        }
    }
    Matrix(vector<vi> inp)
    {
        this->n = inp.size();
        this->m = inp[0].size();
        mat = inp;
    }
    Matrix operator + (const Matrix &b)
    {
        class Matrix out = Matrix(this->n,this->m,0);
        for(int i = 0; i < this->n;i++)
            for(int j = 0;j < this->m; j++)
            out.mat[i][j] = (this->mat[i][j]+b.mat[i][j])%mod;
        return out;
    }
    Matrix operator - (const Matrix &b)
    {
        class Matrix out = Matrix(this->n,this->m,0);
        for(int i = 0; i < this->n;i++)
            for(int j = 0;j < this->m; j++)
            out.mat[i][j] = (this->mat[i][j]-b.mat[i][j]+mod)%mod;
        return out;
    }
    Matrix operator * (const Matrix &b)
    {
        class Matrix out = Matrix(this->n,b.m,0);
       for(int i = 0; i < this->n;i++)
            for(int j = 0;j < b.m; j++)
                for(int x = 0;x < this->m;x++)
                {
                    out.mat[i][j] += (this->mat[i][x]*b.mat[x][j])%mod;
                    out.mat[i][j] %=mod;
                }
        return out;
    }
    Matrix operator ^ (const long long &p)
    {
        return matbin(*this,p);
    }
    Matrix matbin(Matrix a, long long b)
    {
        if (b==0)
            return (Matrix(a.n,a.n,1));
        Matrix res = matbin(a,b/2);
        if (b%2)
            return res*res*a;
        else
            return res*res;
    }
    int get(int x,int y)
    {
        return this->mat[x][y];
    }
};

int main (int argc, char *argv[])
{
	ll n;

	cin >> n;
	vector<vi> arr(2, vi(2));
	arr[0][0] = 1;
	arr[0][1] = 1;
	arr[1][0] = 1;
	arr[1][1] = 0;
	vector<vi> fib(2, vi(1));
	fib[0][0] = 0;
	fib[1][0] = 1;

	Matrix m1(arr);
	Matrix m2(fib);

	Matrix res(m1 ^ (n));

	res = res * m2;
	

	cout << res.get(0,0) << endl;

	return 0;
}
