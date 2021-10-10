#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string sTemp;

	while (1)
	{
		getline(cin, sTemp);

		if (sTemp == "")
		{
			break;
		}

		cout << sTemp << "\n";
	}

	return 0;
}