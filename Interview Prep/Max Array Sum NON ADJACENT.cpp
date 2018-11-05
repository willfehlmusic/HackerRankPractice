#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

vector<string> split_string(string);

/**/

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
	/*Given an array of integers,
	find the subset of non-adjacent elements with the maximum sum.*/
	int maxCurrent = 0;
	int initVal = arr[0];
	/*loop through al elements in the array*/
	for (int i = 1; i < arr.size(); i++)
	{
		/*which is max? the current max or the initial value?*/
		int val = max(maxCurrent, initVal);
		/*take the initial value and sum the
		current max with the array element*/
		initVal = maxCurrent + arr[i];
		/*set maxCurrent to the max value of dispute AFTER using it*/
		maxCurrent = val;
	}
	int valMax = (initVal > maxCurrent) ? initVal : maxCurrent;
	return valMax;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string arr_temp_temp;
	getline(cin, arr_temp_temp);

	vector<string> arr_temp = split_string(arr_temp_temp);

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		int arr_item = stoi(arr_temp[i]);

		arr[i] = arr_item;
	}

	int res = maxSubsetSum(arr);

	fout << res << "\n";

	fout.close();

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
