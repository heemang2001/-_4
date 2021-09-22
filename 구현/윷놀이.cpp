#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	for (int i = 0; i < 3; i++)
	{
		int nTemp1;
		int nTemp2;
		int nTemp3;
		int nTemp4;

		cin >> nTemp1 >> nTemp2 >> nTemp3 >> nTemp4;

		int sum = nTemp1 + nTemp2 + nTemp3 + nTemp4;

		switch (sum)
		{
		case 0:
			cout << "D";
			break;

		case 1:
			cout << "C";
			break;

		case 2:
			cout << "B";
			break;

		case 3:
			cout << "A";
			break;

		case 4:
			cout << "E";
			break;
		}

		cout << endl;
	}

	return 0;
}