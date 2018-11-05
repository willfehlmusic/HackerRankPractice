#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int nEntry;
	cin >> nEntry;
	/*make a map*/
	map<string, string> phoneBook;
	for (int i = 0; i < nEntry; i++)
	{
		string namePerson, phoneNumber;
		cin >> namePerson;
		cin >> phoneNumber;
		bool isIn = phoneBook.find(namePerson) != phoneBook.end();
		if (isIn == true)
		{
			/*value is in phone book*/
		}
		else
		{
			/*value is not in phone book*/
			phoneBook.insert(make_pair(namePerson, phoneNumber));
		}
	}
	/*queries = nEntry*/
	string queryName;
	while (cin >> queryName)
	{
		bool isIn = phoneBook.find(queryName) != phoneBook.end();
		if (isIn == true)
		{
			/*value is in phone book*/
			cout << phoneBook.find(queryName)->first << "=" << phoneBook.find(queryName)->second << "\n";
		}
		else
		{
			/*value is not in phone book*/
			cout << "Not found\n";
		}
	}

	return 0;
}
