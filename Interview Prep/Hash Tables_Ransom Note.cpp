#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {
	map<string, int> magMap;
	if (magazine.size() < note.size())
	{
		/*if there are less words in the magazine than the note requirements*/
		cout << "No\n";
	}
	else
	{
		/*go through magazine vector*/
		for (int i = 0; i < magazine.size(); i++)
		{
			/*add magazine values to map*/
			bool isIn = magMap.find(magazine[i]) != magMap.end();
			if (isIn == true)
			{
				/*increment value*/
				magMap.find(magazine[i])->second = magMap.at(magazine[i]) + 1;
			}
			else
			{
				/*insert value*/
				magMap.insert(make_pair(magazine[i], 1));
			}
		}
		/*go through note vector*/
		for (int i = 0; i < note.size(); i++)
		{
			/*subtract note from magazine values*/
			bool isIn = magMap.find(note[i]) != magMap.end();
			if (isIn == true)
			{
				//cout << "value is in magainze\n";
				/*decrement value*/
				magMap.find(note[i])->second = magMap.at(note[i]) - 1;
				if (magMap.find(note[i])->second < 0)
				{
					cout << "No\n";
					return void();
				}
			}
			else
			{
				//cout << "value is not in magainze\n";
				/*word not in magazine*/
				cout << "No\n";
				return void();
			}
		}
		cout << "Yes\n";
	}

}

int main()
{
	string mn_temp;
	getline(cin, mn_temp);

	vector<string> mn = split_string(mn_temp);

	int m = stoi(mn[0]);

	int n = stoi(mn[1]);

	string magazine_temp_temp;
	getline(cin, magazine_temp_temp);

	vector<string> magazine_temp = split_string(magazine_temp_temp);

	vector<string> magazine(m);

	for (int i = 0; i < m; i++) {
		string magazine_item = magazine_temp[i];

		magazine[i] = magazine_item;
	}

	string note_temp_temp;
	getline(cin, note_temp_temp);

	vector<string> note_temp = split_string(note_temp_temp);

	vector<string> note(n);

	for (int i = 0; i < n; i++) {
		string note_item = note_temp[i];

		note[i] = note_item;
	}

	checkMagazine(magazine, note);

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
