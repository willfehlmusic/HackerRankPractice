#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
using namespace std;

/*store and attribute value pairing...*/
map<string, string> mapAttVal;
char markAttributeChar = ' ';
char markValChar = '\"';

vector<string> splitString(string inputString, char demarcator)
{
	/*make a word token string*/
	string blockString;
	/*vector to hold inidividual blocks*/
	vector<string> outputVector;
	for (int i = 0; i < inputString.length(); i++)
	{
		//cout << "inputString[i] " << inputString[i] << "\n";
		/*add element separated by the demarcator to individual vector elements*/
		if (inputString[i] != demarcator)
		{
			blockString.push_back(inputString[i]);
			//cout << "blockString " << blockString << "\n";
		}
		else
		{
			outputVector.push_back(blockString);
			blockString.clear();
		}
		if (i == inputString.length() - 1)
		{
			outputVector.push_back(blockString);
			blockString.clear();
		}
	}
	return outputVector;
}

int main() {
	int N, Q;
	cin >> N;
	cin >> Q;
	string tagOwnershipString = "";
	for (int i = 0; i < N + 1; i++)
	{
		/*get an input string*/
		string inputString;
		getline(cin, inputString);
		/*split string into vector*/
		vector<string> splitStringVector;
		splitStringVector = splitString(inputString, ' ');
		/*for each token...*/
		string nameString, valueString;
		for (auto i : splitStringVector)
		{
			string tagOpenString;
			string tagCloseString;
			if (i[0] == '<')
			{
				/*if we have a tag...*/
				if (i[1] != '/')
				{
					/*if we have a tag opening...
					<tag1*/
					tagOpenString = i;
					/*now edit to get rid of '<'*/
					tagOpenString = tagOpenString.substr(1, tagOpenString.length() - 1);
					/*add tag to a the ownership string*/
					if (tagOwnershipString == "")
					{
						/*if empty*/
						tagOwnershipString = tagOpenString;
					}
					else
					{
						/*if not empty...update the ownership string*/
						tagOwnershipString = tagOwnershipString + "." + tagOpenString;
					}
				}
				else
				{
					/*if we have a tag closing...
					</tag> */
					tagCloseString = i;
					/*now edit to get rid of '<', '/', '>'*/
					tagCloseString = tagCloseString.substr(2,
						tagCloseString.length() - 3);
					/*make an interator pointing to this closing string position*/
					int index = tagOwnershipString.find("." + tagCloseString);
					if (index == string::npos)
					{
						/*this tag has not been found...
						so this must be a top level tag...
						so lets close and reset everything...*/
						tagOwnershipString = "";
					}
					else
					{
						/*this tag has been found*/
						tagOwnershipString = tagOwnershipString.substr(0, index);
					}
				}
			}
			else if (i[0] == '\"')
			{
				/*we have an attribute value...
				"HelloWorld">*/
				valueString = i;
				/*now edit to get rid of '"', '">'*/
				valueString.erase(remove(valueString.begin(), valueString.end(), '\"'), valueString.end());
				valueString.erase(remove(valueString.begin(), valueString.end(), '>'), valueString.end());
				/*add the name value pairing to the map*/
				mapAttVal.insert(make_pair(nameString, valueString));
			}
			else if (i[0] != ' ' && i[0] != '=' && i[0] != '<' && i[0] != '\"')
			{
				/*we have an attribute name...
				value*/
				nameString = i;
				/*nothing to edit*/
				/*make the ownership title*/
				nameString = tagOwnershipString + "~" + nameString;
			}
			else
			{
				/*do nothing*/
			}
		}
	}
	/*sanity check print out map*/
	for (auto it = mapAttVal.begin(); it != mapAttVal.end(); it++)
	{
		//cout << it->first << " : " << it->second << " \n";
	}
	/*loop through queries*/
	for (int i = 0; i < Q; i++)
	{
		string inputString;
		getline(cin, inputString);
		bool isIn = mapAttVal.find(inputString) != mapAttVal.end();
		if (isIn == true)
		{
			cout << mapAttVal[inputString] << "\n";
		}
		else
		{
			cout << "Not Found!\n";
		}
	}
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}
/*
DOES NOT WORK FOR THE FOLLOWING BUT SEEMS TO GIVE THE RIGHT ANSWER
16 14
<tag1 v1 = "123" v2 = "43.4" v3 = "hello">
</tag1>
<tag2 v4 = "v2" name = "Tag2">
<tag3 v1 = "Hello" v2 = "World!">
</tag3>
<tag4 v1 = "Hello" v2 = "Universe!">
</tag4>
</tag2>
<tag5>
<tag7 new_val = "New">
</tag7>
</tag5>
<tag6>
<tag8 intval = "34" floatval = "9.845">
</tag8>
</tag6>

tag1~v1
tag1~v2
tag1~v3
tag4~v2
tag2.tag4~v1
tag2.tag4~v2
tag2.tag3~v2
tag5.tag7~new_val
tag5~new_val
tag7~new_val
tag6.tag8~intval
tag6.tag8~floatval
tag6.tag8~val
tag8~intval

ANSWER:
123
43.4
hello
Not Found!
Hello
Universe!
World!
New
Not Found!
Not Found!
34
9.845
Not Found!
Not Found!
*/