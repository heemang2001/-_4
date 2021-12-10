#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

string sInput;

int main()
{
	vector<string> vecStr;

	cin >> sInput;
	
	int start = 0;

	while (1)
	{
		if (start >= sInput.size())
		{
			break;
		}

		string sTemp = sInput.substr(start,10);		
		vecStr.push_back(sTemp);		
		start += 10;
	}

	for (int i = 0; i < vecStr.size(); i++)
	{
		cout << vecStr[i] << '\n';
	}

	return 0;
}