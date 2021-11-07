#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int nTemp1;
	int nTemp2;
	int nTemp3;

	string Answer = "";
	string sTemp1;
	string sTemp2;

	cin >> nTemp1 >> nTemp2 >> nTemp3;

	if (nTemp1 == (nTemp2 + nTemp3))
	{
		sTemp1 = "=";
		sTemp2 = "+";
	}

	else if (nTemp1 == (nTemp2 - nTemp3))
	{
		sTemp1 = "=";
		sTemp2 = "-";
	}

	else if (nTemp1 == (nTemp2 * nTemp3))
	{
		sTemp1 = "=";
		sTemp2 = "*";
	}

	else if (nTemp1 == (nTemp2 / nTemp3))
	{
		sTemp1 = "=";
		sTemp2 = "/";
	}

	else if ((nTemp1 + nTemp2) == nTemp3)
	{
		sTemp1 = "+";
		sTemp2 = "=";
	}

	else if ((nTemp1 - nTemp2) == nTemp3)
	{
		sTemp1 = "-";
		sTemp2 = "=";
	}

	else if ((nTemp1 * nTemp2) == nTemp3)
	{
		sTemp1 = "*";
		sTemp2 = "=";
	}

	else if ((nTemp1 / nTemp2) == nTemp3)
	{
		sTemp1 = "/";
		sTemp2 = "=";
	}

	Answer += to_string(nTemp1);
	Answer += sTemp1;	
	Answer += to_string(nTemp2);
	Answer += sTemp2;
	Answer += to_string(nTemp3);

	cout << Answer << '\n';

	return 0;
}