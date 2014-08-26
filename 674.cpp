#include <iostream>
#include <climits>
using namespace std;


int final_coins[7500];


void coin_change(int coins[])
{
	final_coins[0] = 1;
	for (int i = 0; i < 5; i++)
		for (int j = coins[i]; j < 7500; j++)
			final_coins[j] += final_coins[j - coins[i]];
}


int main(int argc, char *argv[])
{
	int amount;
	int coins[] = { 1, 5, 10, 25, 50 };
	coin_change(coins);

	while (cin >> amount)
		cout << final_coins[amount] << endl;

	return 0;
}