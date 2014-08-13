#include <iostream>
#include <cmath>
using namespace std;


int perform_action(int N)
{
	int copy_paste_count = 0;


	while (true)
	{
		if (pow(2, copy_paste_count) >= N)
			return copy_paste_count;
		copy_paste_count++;
	}
}


int main(int argc, char* argv[])
{
	int i = 1, tmp;

	while (cin >> tmp)
	{
		if (tmp < 0)
			break;
		else
			cout << "Case " << i++ << ": " << perform_action(tmp) << endl;
	}

	return 0;
}

