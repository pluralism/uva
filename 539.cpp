#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int dfs(int node_index, int len, vector<vector<bool>> &G, vector<vector<bool>> &visited, int n)
{
	int max_len = len;
	for (int i = 0; i < n; i++)
	{
		if (G[node_index][i] && !visited[node_index][i])
		{
			visited[node_index][i] = visited[i][node_index] = true;
			max_len = max(dfs(i, len + 1, G, visited, n), max_len);
			visited[node_index][i] = visited[i][node_index] = false; //Backtrack
		}
	}

	return max_len;
}


int main(int argc, char* argv[])
{
	int n, m;

	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;

		vector<vector<bool>> G(25, vector<bool>(25, false)); //The Graph
		vector<vector<bool>> visited(25, vector<bool>(25, false)); //The vector of visited edges

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			G[a][b] = G[b][a] = true;
		}


		int max_len = 0;
		for (int i = 0; i < n; i++)
			max_len = max(dfs(i, 0, G, visited, n), max_len);
		cout << max_len << endl;
	}
	return 0;
}

