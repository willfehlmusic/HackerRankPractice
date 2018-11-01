#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	/*The first line of the input contains the number of integers 'N'.*/
	int n;
	cin >> n;
	vector<int> valueVector;
	valueVector.resize(n);
	for (int i = 0; i < n; i++)
	{
		/*The next line contains 'N' integers in sorted order.*/
		int yVal;
		cin >> yVal;
		valueVector[i] = yVal;
	}
	/*The next line contains 'Q', the number of queries.*/
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		/*Then 'Q' lines follow each containing a single integer 'Y'.*/
		int yVal;
		cin >> yVal;
		vector<int>::iterator it = lower_bound(valueVector.begin(), valueVector.end(), yVal);
		if (valueVector[it - valueVector.begin()] == yVal)
		{
			cout << "Yes " << (it - valueVector.begin() + 1) << "\n";
		}
		else
		{
			cout << "No " << (it - valueVector.begin() + 1) << "\n";
		}
	}

	/*Note that if the same number is present multiple times, you have to print the first index at which it occurs. Also, the input is such that you always have an answer for each query.*/
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}
