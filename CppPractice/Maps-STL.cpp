#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int inputCount, type;
	cin >> inputCount;
	map<string, int> mapContainer;
	for (int i = 0; i < inputCount; i++)
	{
		cin >> type;
		if (type == 1)
		{
			string inString; int inInt;
			cin >> inString;
			cin >> inInt;
			if (mapContainer.find(inString) != mapContainer.end())
			{
				mapContainer.find(inString)->second = mapContainer[inString] + inInt;
			}
			else
			{
				mapContainer.insert(make_pair(inString, inInt));
			}
		}
		else if (type == 2)
		{
			string inString;
			cin >> inString;
			mapContainer.erase(inString);
		}
		else if (type == 3)
		{
			string inString;
			cin >> inString;
			cout << mapContainer[inString] << "\n";
		}
		else
		{

		}
	}
	return 0;
}