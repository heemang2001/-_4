#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

string sInput;
string Answer = "";

int main()
{
	cin >> sInput;

	Answer += sInput.front();

	for (int i = 1; i < sInput.size(); i++)
	{
		if (sInput[i] == '-')
		{
			Answer += sInput[i + 1];
		}
	}

	cout << Answer << '\n';

	return 0;
}