#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct intValue {
	int value;
	bool is_red;

	bool operator <(const intValue &val)
	{
		return val.value < value;
	}
};


int perform_action(vector<intValue> values)
{
	if (values.empty())
		return 0;
	sort(values.begin(), values.end());

	int count = 1, index = 0;	
	bool last_color = values[index++].is_red;

	if (values.size() > 1)
	{
		for (int i = 1; i < values.size(); i++)
		{
			if (values[i].is_red != last_color)
			{
				last_color = values[i].is_red;
				count++;
			}
		}
	}
	return count;
}


int main(int argc, char *argv[])
{
	int P;
	cin >> P;

	while (P)
	{
		int N, tmp;
		vector<intValue> values;

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> tmp;
			intValue val;
			if (tmp > 0)
			{
				val.is_red = false;
				val.value = tmp;
			}
			else
			{
				val.is_red = true;
				val.value = abs(tmp);
			}
			values.push_back(val);
		}

		cout << perform_action(values) << endl;
		P--;
	}
	return 0;
}