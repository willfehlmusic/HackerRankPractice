#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */


	/*The first line of the input contains an integer N.
	The next line contains N space separated integers(1-based index).
	The third line contains a single integer x,denoting the position of an element that should be removed from the vector.
	The fourth line contains two integers a and b denoting the range that should be erased from the vector inclusive of a and exclusive of b.*/

	int inSize, count, val, minRangeVal, maxRangeVal, indexErase;
	vector<int> vectorVal;

	/*get input value for size*/
	cin >> inSize;
	/*resize vector*/
	vectorVal.resize(inSize);

	/*initialize count*/
	count = 0;
	while (count < inSize) {
		cin >> val;
		vectorVal[count] = val;
		count++;
	}
	cin >> val;
	indexErase = val;
	vectorVal.erase(vectorVal.begin() + indexErase - 1);

	/*initialize count*/
	count = 0;
	while (count < 2) {
		if (count == 0)
		{
			cin >> val;
			minRangeVal = val;
		}
		else
		{
			cin >> val;
			maxRangeVal = val;
		}
		count++;
	}
	vectorVal.erase(vectorVal.begin() + minRangeVal - 1,
		vectorVal.begin() + maxRangeVal - 1);
	/*Print the size of the vector in the first line
	and the elements of the vector after the two erase operations in the second line separated by space.*/
	cout << vectorVal.size() << "\n";
	for (int i = 0; i < vectorVal.size(); i++)
	{
		cout << vectorVal[i] << " ";
	}
	return 0;
}
