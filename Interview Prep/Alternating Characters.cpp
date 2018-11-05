#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
	long long delCount = 0;
	/*first char*/
	char currentChar = s[0];
	/*loop through string*/
	for (auto sIt = s.begin() + 1; sIt != s.end(); sIt++)
	{
		//cout << "current char" << currentChar << "    ";
		//cout << "candidate char" << *sIt << "\t";
		if (*sIt == currentChar)
		{
			//cout << "the chars are the same\n";
			/*the chars are the same*/
			delCount++;
		}
		else
		{
			//cout << "the chars are not the same\n";
			/*the char is not the same*/
			currentChar = *sIt;
		}
	}
	return delCount;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string s;
		getline(cin, s);

		int result = alternatingCharacters(s);

		fout << result << "\n";
	}

	fout.close();

	return 0;
}
