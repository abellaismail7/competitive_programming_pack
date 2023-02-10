#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <deque>


using namespace std;
typedef vector<int> t_ints;

int main ()
{
	t_ints dp(1e6 + 1, -1);

	int n;
	dp[1] = 1;

	for (int i = 1; i <= 1e6; i++)
	{
		int a = (i % 3 == 0) ? dp[i / 3]: 10e7;
		int b = (i % 2 == 0) ? dp[i / 2]: 10e7;
		dp[i] = min({dp[i - 1], a, b}) + 1;

	}
	while (cin >> n)
	{
		std::cout << dp[n] << '\n';
	}

	return 0;
}

//bool dfs(stack<int> &st, t_ints adj[], t_ints &visited, int row){
//	if (visited[row] == 1)
//	{
//		visited[row] = 2;
//		return true;
//	}
//	visited[row] = 1;
//
//	st.push(row);
//
//	for(auto &node:adj[row])
//	{
//		if (dfs(st, adj,visited, node))
//			return true;
//		st.pop();
//	}
//	visited[row] = -1;
//	return false;
//}
//
//void has_cycle(int n)
//{
//	t_ints adj[n];
//	t_ints visited(n, 0);
//	
//	int m;
//	cin >> m;
//	for(int i = 0; i < m; i++)
//	{
//		int x, y;
//		cin >> x >> y;
//		x--;y--;
//		adj[x].push_back(y);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (visited[i])
//			continue;
//
//		stack<int> st;
//		if (dfs(st, adj, visited, i))
//		{
//			stack<int> res;
//			cout << "YES" << '\n';
//			while (!st.empty()) {
//				res.push(st.top());
//				if (visited[st.top()] == 2)
//					break;
//    	    	st.pop();
//    		}
//			while (!res.empty()) {
//				std::cout << res.top() +1  << ' ';
//				res.pop();
//			}
//			cout << '\n';
//			return;
//		}
//	}
//	cout << "NO" << std::endl;
//}
//



