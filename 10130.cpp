#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int values[1001], weights[1001], C[1001][1001];

int ks(int N, int MW)
{
	for (int i = 0; i <= N; i++)
		C[i][0] = 0;
	for (int i = 0; i <= MW; i++)
		C[0][i] = 0;


	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= MW; j++)
			if (weights[i] <= j)
				C[i][j] = max(C[i - 1][j], C[i - 1][j - weights[i]] + values[i]);
			else
				C[i][j] = C[i - 1][j];

	return C[N][MW];
}


int main(int argc, char *argv[])
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, G, MW, total = 0;
		cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> values[i] >> weights[i];

		cin >> G;
		while (G--)
		{
			cin >> MW;
			total += ks(N, MW);
		}
		cout << total << endl;
	}
	return 0;
}