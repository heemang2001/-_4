#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int Answer;
string ChessMap[8];

int main()
{
	for (int i = 0; i < 8; i++)
	{
		cin >> ChessMap[i];
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (ChessMap[i][j] == 'F')
			{
				if (i % 2 == 0 && j % 2 == 0)
				{
					Answer++;
				}

				else if (i % 2 == 1 && j % 2 == 1)
				{
					Answer++;
				}
			}
		}
	}

	cout << Answer << '\n';

	return 0;
}