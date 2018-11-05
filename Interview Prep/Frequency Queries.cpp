#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
	/*
	You are given 'q' queries. Each query is of the form two integers described below:
	- 1 x: Insert x in your data structure.
	- 2 y: Delete one occurence of y from your
	data structure, if present.
	- 3 z: Check if any integer is present whose
	frequency is exactly z. If yes, print 1 else 0.
	The queries are given in the form of a 2-D array 'q' of size queries where queries[i][0] contains the operation, and queries[i][1] contains the data element.
	*/
	/*vector*/
	vector<int> outVector;
	/*make a map*/
	map<int, int> freqMap;
	/*loop through queries*/
	for (auto q : queries)
	{
		if (q.at(0) == 1)
		{
			int x = q.at(1);
			bool isIn = freqMap.find(x) != freqMap.end();
			if (isIn == false)
			{
				/*Insert x in your data structure.*/
				freqMap.insert(make_pair(x, 1));
			}
			else
			{
				/*increment value at key x in your data structure.*/
				freqMap.at(x)++;
			}
		}
		else if (q.at(0) == 2)
		{
			int y = q.at(1);
			bool isIn = freqMap.find(y) != freqMap.end();
			if (isIn == false)
			{
				/*Delete one occurence of y from your data structure,
				if present.*/
			}
			else
			{
				/*Delete one occurence of y from your data structure,
				if present.*/
				freqMap.at(y)--;
				if (freqMap.at(y) < 0)
				{
					freqMap.at(y) = 0;
				}
			}
		}
		else if (q.at(0) == 3)
		{
			int z = q.at(1);
			/*Check if any integer is present whose frequency
			is exactly z. If yes, print 1 else 0.*/
			bool isMatch = false;
			/*create iterators*/
			auto it = freqMap.begin();
			auto rit = freqMap.rbegin();
			/*loop through freqMap using forward iterator and backwards iterator...*/
			for (; it != freqMap.end(); it++, rit++)
			{
				if (it->second == z || rit->second == z)
				{
					isMatch = true;
					break;
				}
				if ((isMatch == false) && (*it == *rit))
				{
					break;
				}
			}
			if (isMatch == true)
			{
				outVector.push_back(1);
			}
			else
			{
				outVector.push_back(0);
			}
		}
		else {}
	}
	return outVector;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string q_temp;
	getline(cin, q_temp);

	int q = stoi(ltrim(rtrim(q_temp)));

	vector<vector<int>> queries(q);

	for (int i = 0; i < q; i++) {
		queries[i].resize(2);

		string queries_row_temp_temp;
		getline(cin, queries_row_temp_temp);

		vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

		for (int j = 0; j < 2; j++) {
			int queries_row_item = stoi(queries_row_temp[j]);

			queries[i][j] = queries_row_item;
		}
	}

	vector<int> ans = freqQuery(queries);

	for (int i = 0; i < ans.size(); i++) {
		fout << ans[i];

		if (i != ans.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";

	fout.close();

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
