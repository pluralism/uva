#include <iostream>
using namespace std;



int main(int argc, char *argv[])
{
	int T;

	cin >> T;

	while (T)
	{
		long total = 0;
		int n;
		
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			total += a * c;
		}

		cout << total << endl;
		T--;
	}
	return 0;
}