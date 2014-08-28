#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

map<string, int> words;

void generate_dict()
{
	queue<string> q;
	string tmp;
	int start = 0;

	q.push("");
	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		words[tmp] = start++;
		if (tmp.size() == 5)
			continue;

		char s;
		if (tmp.empty())
			s = 'a';
		else
			s = tmp[tmp.size() - 1] + 1;
		for (s; s <= 'z'; s++)
			q.push(tmp + s);
	}
}


int main(int argc, char *argv[])
{
	generate_dict();
	map<string, int>::iterator it;
	string tmp;

	while (cin >> tmp)
	{
		it = words.find(tmp);
		if (it == words.end())
			cout << 0 << endl;
		else
			cout << (*it).second << endl;
	}
	return 0;
}