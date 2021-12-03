#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int X, Y;
string strDay[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
vector<string> vecStr[13][32];

int main()
{
	cin >> X >> Y;

	int CurDay = 0;

	for (int i = 1; i <= 12; i++)
	{
		int Day = 0;		

		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
		{
			Day = 31;
		}

		else if(i == 4 || i == 6 || i == 9 || i == 11)
		{
			Day = 30;
		}

		else
		{
			Day = 28;
		}

		for (int j = 1; j <= Day; j++)
		{			
			vecStr[i][j].push_back(strDay[CurDay]);

			if (strDay[CurDay] == "SUN")
			{
				CurDay = 0;
			}

			else
			{
				CurDay++;
			}
		}		
	}

	cout << vecStr[X][Y].front() << '\n';

	return 0;
}