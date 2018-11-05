#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
	/*Print a single integer denoting the number of characters you must delete to make the two strings anagrams of each other.*/
	int delCount = 0;
	/*the strings use ascii characters*/
	/*create vectors to count frequencies for 26 possible chars*/
	vector<int> countVectorA; countVectorA.resize(26);
	vector<int> countVectorB; countVectorB.resize(26);
	/*get ascii value of 'a'*/
	const int aVal = (int)'a';
	/*loop through strings:
	- subtract the value of ascii 'a' == 97
	- which gives us 0-25 possiblities
	- then increment count*/
	for (int i = 0; i < a.length(); i++)
	{
		//cout << a[i] << "\n";
		countVectorA[((int)a[i]) - aVal] += 1;
		//cout << countVectorA[((int)a[i]) - aVal] << "\n";
	}
	for (int i = 0; i < b.length(); i++)
	{
		countVectorB[((int)b[i]) - aVal] += 1;
	}
	/*loop through the lower case ascii table 'a-z'*/
	for (int i = 0; i < 26; i++)
	{
		/*find the magnitude of the difference between the vectors... IF the values are not equal*/
		if (countVectorA[i] != countVectorB[i])
		{
			delCount += abs(countVectorA[i] - countVectorB[i]);
		}
	}

	return delCount;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string a;
	getline(cin, a);

	string b;
	getline(cin, b);

	int res = makeAnagram(a, b);

	fout << res << "\n";

	fout.close();

	return 0;
}
