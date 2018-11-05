#include <bits/stdc++.h>
#include <locale>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
	// Return the minimum number of characters to make the password strong
	int reqCharCount = 0;
	bool isCNumeric = false;
	bool isCUpper = false;
	bool isCLower = false;
	bool isCSpecial = false;
	/**/
	string numbers = "0123456789";
	string lower_case = "abcdefghijklmnopqrstuvwxyz";
	string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string special_characters = "!@#$%^&*()-+";
	/*check password characters*/
	for (auto c : password)
	{
		/*check only if a type value is not found*/
		if (isCNumeric == false)
		{
			/*loop through template string*/
			for (auto j : numbers)
			{
				/*if the value is found*/
				if (c == j)
				{
					/*switch to true and exit loop*/
					isCNumeric = true;
					break;
				}
			}
		}
		if (isCUpper == false)
		{
			for (auto j : upper_case)
			{
				if (c == j)
				{
					isCUpper = true;
					break;
				}
			}
		}
		if (isCLower == false)
		{
			for (auto j : lower_case)
			{
				if (c == j)
				{
					isCLower = true;
					break;
				}
			}
		}
		if (isCSpecial == false)
		{
			for (auto j : special_characters)
			{
				if (c == j)
				{
					isCSpecial = true;
					break;
				}
			}
		}
	}
	/*now count up exceptions to requirements*/
	if (isCNumeric == false)
	{
		reqCharCount++;
	}
	if (isCLower == false)
	{
		reqCharCount++;
	}
	if (isCUpper == false)
	{
		reqCharCount++;
	}
	if (isCSpecial == false)
	{
		reqCharCount++;
	}
	/*return correct calculation*/
	if ((6 - n) > reqCharCount)
	{
		return 6 - n;
	}
	else
	{
		return reqCharCount;
	}
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string password;
	getline(cin, password);

	int answer = minimumNumber(n, password);

	fout << answer << "\n";

	fout.close();

	return 0;
}
