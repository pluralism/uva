#include <iostream>
#include <string>
#include <cstring>	
#include <algorithm>
using namespace std;

int matrix[101][101];
int max_value;

void calculate(int i, int j, int sum, int R, int C)
{
	max_value = max(max_value, sum);
	if (i + 1 < R && matrix[i + 1][j] < matrix[i][j])
		calculate(i + 1, j, sum + 1, R, C);
	if (i - 1 >= 0 && matrix[i - 1][j] < matrix[i][j])
		calculate(i - 1, j, sum + 1, R, C);
	if (j + 1 < C && matrix[i][j + 1] < matrix[i][j])
		calculate(i, j + 1, sum + 1, R, C);
	if (j - 1 >= 0 && matrix[i][j - 1] < matrix[i][j])
		calculate(i, j - 1, sum + 1, R, C);
}


int main(int argc, char* argv[])
{
	int N;

	cin >> N;
	while (N--)
	{
		int R, C;
		string name;
		cin >> name >> R >> C;

		for (int i = 0; i < R; i++)	
			for (int j = 0; j < C; j++)
				cin >> matrix[i][j];

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				calculate(i, j, 1, R, C);

		cout << name << ": " << max_value << endl;
		memset(matrix, 0, sizeof(matrix));
		max_value = 0;
	}
	return 0;
}

