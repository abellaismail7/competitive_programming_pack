#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <map>

#define mod (1000000007)
using namespace std;

void readGraph(int n)
{
	int mat[n][n];
	char cell;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			std::cin >> cell;
			mat[i][j] = -(cell == '.');
		}
	}
	if (mat[n-1][n-1] == 0)
	{
		std::cout << "0" << std::endl;
		return;
	}
	mat[n-1][n-1] = 1;

	for (int i = n - 1; i >= 0; i--){
		for (int j = n - 1; j >= 0; j--) {
			if ((i == j && i == n - 1) || mat[i][j] == 0)
				continue;
			mat[i][j] = ((i + 1 != n) ? mat[i + 1][j] % mod : 0) + ((j + 1 != n) ? mat[i][j + 1] % mod : 0);
		}
	}
	//for (size_t i = 0; i < n; i++) {
	//	for (size_t j = 0; j < n; j++) {
	//		cout << mat[i][j] << ' ';
	//	}
	//	std::cout << std::endl;
	//}
	std::cout << mat[0][0] % mod << std::endl;

}

int main ()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n;
	while(std::cin >> n && n != 0)
	{
		vector<short> adj[n];
		int edges;
		cin >> edges;
		while (edges--)
		{
			int a,b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}
	readGraph(n);
	return 0;
}
