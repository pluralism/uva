#include <iostream>
#include <algorithm>
using namespace std;


int main(int argc, char* argv[])
{
	int i, j;

	while (cin >> i >> j)
	{
		int max_length = 0;
		int tmp_i = i, tmp_j = j;

		if (i > j)
			swap(i, j);


		while (i <= j)
		{
			int n = i;
			int length = 1;

			while (n != 1)
			{
				if (n & 2 != 0)
					n = 3 * n + 1;
				else
					n >>= 1;

				length++;
			}

			if (length > max_length)
				max_length = length;
			i++;	
		}

		cout << tmp_i << " " << tmp_j << " " << max_length << endl;
	}

	return 0;
}

