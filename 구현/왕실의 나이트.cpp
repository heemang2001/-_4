#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int CanMove(int i, int k)
{
	int tValue = 0;

	// ¿ÞÂÊ 2Ä­, À§¾Æ·¡ 1Ä­
	if ((k - 2) >= 0)
	{
		if (i + 1 <= 7)
		{
			tValue++;
		}

		if (i - 1 >= 0)
		{
			tValue++;
		}
	}

	// ¿ÞÂÊ 1Ä­, À§¾Æ·¡ 2Ä­
	if ((k - 1) >= 0)
	{
		if (i + 2 <= 7)
		{
			tValue++;
		}

		if (i - 2 >= 0)
		{
			tValue++;
		}
	}

	// ¿À¸¥ÂÊ 2Ä­, À§¾Æ·¡ 1Ä­
	if ((k + 2) <= 7)
	{
		if (i + 1 <= 7)
		{
			tValue++;
		}

		if (i - 1 >= 0)
		{
			tValue++;
		}
	}

	// ¿À¸¥ÂÊ 1Ä­, À§¾Æ·¡ 2Ä­
	if ((k + 1) <= 7)
	{
		if (i + 2 <= 7)
		{
			tValue++;
		}

		if (i - 2 >= 0)
		{
			tValue++;
		}
	}

	return tValue;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string Col = "abcdefgh"; // ¿­
	string Row = "12345678"; // Çà

	string Map[8][8];
	
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			Map[i][k] += Col[k];
			Map[i][k] += Row[i];
		}
	}

	string input;

	int Cur_i;
	int Cur_k;

	cin >> input;

	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			if (input == Map[i][k])
			{
				Cur_i = i;
				Cur_k = k;
			}
		}
	}

	cout << CanMove(Cur_i, Cur_k);

	return 0;
}