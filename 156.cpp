#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


bool anagram(string s1, string s2)
{
	if (s1.size() != s2.size())
		return false;

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	return s1 == s2;
}


bool has_ananagrams(string word, vector<string> dictionary, int index)
{
	string s = word;
	for (int i = 0; i < dictionary.size(); i++)
		transform(dictionary[i].begin(), dictionary[i].end(), dictionary[i].begin(), ::tolower);
	transform(s.begin(), s.end(), s.begin(), ::tolower);

	for (int i = 0; i < dictionary.size(); i++)
		if (anagram(s, dictionary[i]) && i != index)
			return false;

	return true;
}


void perform_action(vector<string> dictionary)
{
	vector<string> ananagrams;

	for (int i = 0; i < dictionary.size(); i++)
		if (has_ananagrams(dictionary[i], dictionary, i))
			ananagrams.push_back(dictionary[i]);

	sort(ananagrams.begin(), ananagrams.end());
	for (int i = 0; i < ananagrams.size(); i++)
		cout << ananagrams[i] << endl;
}


int main(int argc, char *argv[])
{
	string line;
	ifstream fin;
	vector<string> dictionary;

	while (cin >> line)
	{
		if (line == "#")
			break;

		line.erase(unique(line.begin(), line.end(), [](char a, char b) {
			return isspace(a) && isspace(b);
		}), line.end());

		stringstream ss(line);
		string word;
		while (ss >> word)
			dictionary.push_back(word);
	}
	perform_action(dictionary);

	return 0;
}