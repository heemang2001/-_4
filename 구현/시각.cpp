#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool checkThree(int h, int m, int s)
{
	if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
	{
		return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	

	int nHour, nMinuate, nSecond = 0;
	int nValue = 0;

	cin >> nHour;

	for (int i = 0; i <= nHour; i++)
	{
		for (int j = 0; j <= 59; j++)
		{
			for (int k = 0; k <= 59; k++)
			{
				if (checkThree(i, j, k) == true)
				{
					nValue++;
				}
			}
		}
	}	
	
	cout << nValue;

	return 0;
}