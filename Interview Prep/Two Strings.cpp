#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
	bool inA, inB;
	string* longString; string* shortString;
	map<char, int> stringMap;
	/*get the largest and shortest string...*/
	if (s1.length() > s2.length())
	{
		longString = &s1;
		shortString = &s2;
	}
	else
	{
		longString = &s2;
		shortString = &s1;
	}

	/*add characters of longest string to the map*/
	for (int i = 0; i < longString->length(); i++)
	{
		if (stringMap.find(longString->at(i)) != stringMap.end())
		{
			/*if the char is in the map*/
			/*nothing to do*/
		}
		else
		{
			/*if the char is not in the map*/
			stringMap.insert(make_pair(longString->at(i), 1));
		}
	}

	/*loop shortest string to the map*/
	for (int i = 0; i < shortString->length(); i++)
	{
		if (stringMap.find(shortString->at(i)) != stringMap.end())
		{
			/*if the char is in the map*/
			return "YES";
		}
		else
		{
			/*if the char is not in the map*/
		}
	}
	return "NO";
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string s1;
		getline(cin, s1);

		string s2;
		getline(cin, s2);

		string result = twoStrings(s1, s2);

		fout << result << "\n";
	}

	fout.close();

	return 0;
}
