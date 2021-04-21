#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Tile
{
	int nX;
	int nY;
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	int nTemp = 0;

	string S = "LRUD";
	Tile tile[100][100] = { 0 };
	Tile Curtile;

	Curtile.nX = 1;
	Curtile.nY = 1;

	int i, k = 0;

	string input_String;

	cin >> N;

	//for (i = 0; i < N; i++)
	//{
	//	for (k = 0; k < N; k++)
	//	{		
	//		tile[i][k].nX = i + 1;
	//		tile[i][k].nY = k + 1;
	//	}			
	//}	

	cin.ignore(); // 버퍼 지우기

	getline(cin, input_String);

	for (int j = 0; j < input_String.size(); j++)
	{
		char nTempChar = input_String[j];

		if (nTempChar == ' ')
		{
			continue;
		}

		// L
		if (nTempChar == S[0])
		{
			if (Curtile.nY == 1)
			{
				continue;
			}

			else
			{
				Curtile.nY--;
			}
		}

		// R
		else if (nTempChar == S[1])
		{
			if (Curtile.nY == N)
			{
				continue;
			}

			else
			{
				Curtile.nY++;
			}
		}

		// U
		else if (nTempChar == S[2])
		{
			if (Curtile.nX == 1)
			{
				continue;
			}

			else
			{
				Curtile.nX--;
			}
		}

		// D
		else if (nTempChar == S[3])
		{
			if (Curtile.nX == N)
			{
				continue;
			}

			else
			{
				Curtile.nX++;
			}
		}
	}




	cout << Curtile.nX << " " << Curtile.nY;

	return 0;
}