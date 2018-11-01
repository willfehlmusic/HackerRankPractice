#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
	/*at an altitude 0 is sea level*/
	int altitude = 0;
	int valleyCount = 0;
	/*loop through string*/
	for (int i = 0; i < s.length(); i++)
	{
		/*check the value of the step*/
		if (s[i] == 'U')
		{
			/*go up*/
			altitude += 1;
			//cout << "GO UP \t" << altitude << "\n";
		}
		else
		{
			/*is the altitude 0?*/
			if (altitude == 0)
			{
				valleyCount += 1;
			}
			/*go down*/
			altitude -= 1;
			//cout << "GO DOWN \t" << altitude << "\n";
		}
	}
	return valleyCount;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string s;
	getline(cin, s);

	int result = countingValleys(n, s);

	fout << result << "\n";

	fout.close();

	return 0;
}
