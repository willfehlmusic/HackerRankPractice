#include <bits/stdc++.h>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;

map<char, pair<int, bool>> asciiMap;
void initializeASCIIMap()
{
	/*key count, is decremented*/
	asciiMap.insert(make_pair('a', make_pair(0, false)));
	asciiMap.insert(make_pair('b', make_pair(0, false)));
	asciiMap.insert(make_pair('c', make_pair(0, false)));
	asciiMap.insert(make_pair('d', make_pair(0, false)));
	asciiMap.insert(make_pair('e', make_pair(0, false)));
	asciiMap.insert(make_pair('f', make_pair(0, false)));
	asciiMap.insert(make_pair('g', make_pair(0, false)));
	asciiMap.insert(make_pair('h', make_pair(0, false)));
	asciiMap.insert(make_pair('i', make_pair(0, false)));
	asciiMap.insert(make_pair('j', make_pair(0, false)));
	asciiMap.insert(make_pair('k', make_pair(0, false)));
	asciiMap.insert(make_pair('l', make_pair(0, false)));
	asciiMap.insert(make_pair('m', make_pair(0, false)));
	asciiMap.insert(make_pair('n', make_pair(0, false)));
	asciiMap.insert(make_pair('o', make_pair(0, false)));
	asciiMap.insert(make_pair('p', make_pair(0, false)));
	asciiMap.insert(make_pair('q', make_pair(0, false)));
	asciiMap.insert(make_pair('r', make_pair(0, false)));
	asciiMap.insert(make_pair('s', make_pair(0, false)));
	asciiMap.insert(make_pair('t', make_pair(0, false)));
	asciiMap.insert(make_pair('u', make_pair(0, false)));
	asciiMap.insert(make_pair('v', make_pair(0, false)));
	asciiMap.insert(make_pair('w', make_pair(0, false)));
	asciiMap.insert(make_pair('x', make_pair(0, false)));
	asciiMap.insert(make_pair('y', make_pair(0, false)));
	asciiMap.insert(make_pair('z', make_pair(0, false)));
}
map<int, int> freqOccurMap;

// Complete the isValid function below.
string isValid(string s)
{
	string outString = "NO";
	if (s.length() <= 3)
	{
		/*this case is always resolvable*/
		outString = "YES";
		return outString;
	}
	/*make a vector*/
	initializeASCIIMap();
	/*loop through string...*/
	for (auto c : s)
	{
		/*increment frequency count for that character*/
		asciiMap.at(c).first++;
	}

	/*loop through*/
	int maxFreq = 0;
	/*loop through string and find the maxFrequency*/
	for (auto c : s)
	{
		/*check the characters*/
		if (asciiMap.at(c).first > maxFreq)
		{
			maxFreq = asciiMap.at(c).first;
		}
	}
	int minFreq = maxFreq;
	/*loop through string and find the minFrequency*/
	for (auto c : s)
	{
		/*check the characters*/
		if (asciiMap.at(c).first < minFreq)
		{
			minFreq = asciiMap.at(c).first;
		}
	}
	if (minFreq == maxFreq)
	{
		/*a string such as 'abcde' or 'aabbccdd'
		is valid if the min and max frequencies are the same by definition*/
		outString = "YES";
		return outString;
	}
	/*sanity check*/
	//cout << "minFreq " << minFreq << "|maxFreq " << maxFreq <<"\n";

	/*make a table of frequencies*/
	for (auto it = asciiMap.begin(); it != asciiMap.end(); it++)
	{
		if (it->second.first > 0)
		{
			/*format frequency : freqOfFreq*/
			freqOccurMap[it->second.first]++;
			//cout << " Freq " << it->second.first << " ... " << freqOccurMap[it->second.first] << "\n";
		}
	}
	if (freqOccurMap.size() > 2)
	{
		/*a string such as 'abbcccdddd' or 'abbccc'
		has more than 2 sizes and therefore, is not valid by definition*/
		outString = "NO";
		return outString;
	}
	else
	{
		if (minFreq == 1 && freqOccurMap.at(minFreq) == 1)
		{
			/*a string such as 'abbcc' or 'abbb'
			is correctable and therefore is valid*/
			outString = "YES";
			return outString;
		}
		else if ((maxFreq - minFreq == 1) && freqOccurMap.at(maxFreq) == 1)
		{
			/*a string such as 'aabbbcc' or 'abb'
			is correctable and therefore is valid*/
			outString = "YES";
			return outString;
		}
	}

	return outString;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string s;
	getline(cin, s);

	string result = isValid(s);

	fout << result << "\n";

	fout.close();

	return 0;
}
