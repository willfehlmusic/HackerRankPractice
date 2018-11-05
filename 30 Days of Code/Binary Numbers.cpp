#include <bits/stdc++.h>

using namespace std;

string convertToBinary(int nVal)
{
	string outString;
	while (nVal != 0)
	{
		outString = (nVal % 2 == 0 ? "0" : "1") + outString;
		nVal = nVal / 2;
	}
	return outString;
}

int countConsecOnes(string inputBinary)
{
	int countMax = 0;
	int countCurrent = 0;
	/*loop through characters*/
	for (int c = 0; c < inputBinary.length(); c++)
	{
		if (inputBinary[c] == '1')
		{
			/*we have found a 1*/
			countCurrent++;
			if (countCurrent > countMax)
			{
				/*set the new max val*/
				countMax = countCurrent;
			}
		}
		else
		{
			/*ignore this*/
			countCurrent = 0;
		}
	}
	return countMax;
}

int main()
{
	int n, nCon;
	string nBinary;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	/*convert n to binary*/
	nBinary = convertToBinary(n);
	//cout << nBinary <<"\n";
	/*find the max number of consecutive 1's*/
	nCon = countConsecOnes(nBinary);
	cout << nCon << "\n";
	return 0;
}
