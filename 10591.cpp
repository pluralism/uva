#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;


long long squared(long long number)
{
	long long total = 0;
	while (number)
	{
		total += pow(number % 10, 2);
		number /= 10;
	}

	return total;
}


bool already_found(long long number, set<long long> numbers)
{
	set<long long>::iterator it = find(numbers.begin(), numbers.end(), number);
	if (it != numbers.end())
		return true;
	return false;
}


bool happy_number(long long number)
{
	set<long long> found_numbers;
	long long original = number, tmp = original;

	while (tmp != 1)
	{
		tmp = squared(tmp);
		if (tmp == original || already_found(tmp, found_numbers))
			return false;
		else
			found_numbers.insert(tmp);
	}
	return true;
}



int main(int argc, char *argv[])
{
	long long tmp;
	int N;
	int i = 1;
	cin >> N;

	while (N--)
	{
		cin >> tmp;
		cout << "Case #" << i++ << ": " << tmp << " is ";
		if (happy_number(tmp))
			cout << "a Happy number.";
		else
			cout << "an Unhappy number.";
		cout << endl;
	}
	return 0;
}