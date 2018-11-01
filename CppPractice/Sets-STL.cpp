#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
	/*create a set of values*/
	set<int> valSet;
	/*The first line of the input contains 'Q' where  is the number of queries.*/
	int q; cin >> q;
	for (int i = 0; i < q; i++)
	{
		/*The next 'Q' lines contain 1 query each.*/
		/*Each query consists of two integers 'y' and 'x' where 'y' is the type of the query and 'x' is an integer.*/
		int y, x;
		cin >> y; cin >> x;

		if (y == 1)
		{
			/*1 x : Add an element x to the set.*/
			valSet.insert(x);
		}
		else if (y == 2)
		{
			/*2 x : Delete an element x from the set. (If the number x is not present in the set, then do nothing).*/
			valSet.erase(x);
		}
		else if (y == 3)
		{
			/*3 x : If the number x is present in the set, then print "Yes"(without quotes) else print "No"(without quotes).*/
			bool isIn = valSet.find(x) != valSet.end();
			if (isIn == true)
			{
				cout << "Yes\n";
			}
			else
			{
				cout << "No\n";
			}
		}
		else {}


	}
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}



