#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int K;
int answer;
vector<string> vecTopnee;
vector<bool> vecIsTurn(3);

string CalculTopnee(string strTopnee, int Direction)
{
	char front = strTopnee.front();
	char back = strTopnee.back();

	// 반시계방향 회전
	if (Direction == -1)
	{
		strTopnee.erase(strTopnee.begin());
		strTopnee += front;
		return strTopnee;
	}

	// 시계방향 회전
	else if(Direction == 1)
	{
		strTopnee.erase(strTopnee.end() - 1);
		strTopnee.insert(strTopnee.begin(), back);
		return strTopnee;
	}
}

void TurnTopnee(int TopneeNum, int Direction)

{
	if (TopneeNum == 1)
	{
		vecTopnee[1] = CalculTopnee(vecTopnee[1], Direction);

		if (vecIsTurn[0])
		{			
			vecTopnee[2] = CalculTopnee(vecTopnee[2], -Direction);

			if (vecIsTurn[1])
			{
				vecTopnee[3] = CalculTopnee(vecTopnee[3], Direction);

				if (vecIsTurn[2])
				{
					vecTopnee[4] = CalculTopnee(vecTopnee[4], -Direction);
				}
			}
		}
	}

	else if(TopneeNum == 2)
	{
		vecTopnee[2] = CalculTopnee(vecTopnee[2], Direction);

		if (vecIsTurn[0])
		{
			vecTopnee[1] = CalculTopnee(vecTopnee[1], -Direction);
		}

		if (vecIsTurn[1])
		{
			vecTopnee[3] = CalculTopnee(vecTopnee[3], -Direction);

			if (vecIsTurn[2])
			{
				vecTopnee[4] = CalculTopnee(vecTopnee[4], Direction);
			}
		}
	}

	else if (TopneeNum == 3)
	{
		vecTopnee[3] = CalculTopnee(vecTopnee[3], Direction);

		if (vecIsTurn[2])
		{
			vecTopnee[4] = CalculTopnee(vecTopnee[4], -Direction);
		}

		if (vecIsTurn[1])
		{
			vecTopnee[2] = CalculTopnee(vecTopnee[2], -Direction);

			if (vecIsTurn[0])
			{
				vecTopnee[1] = CalculTopnee(vecTopnee[1], Direction);
			}
		}
	}

	else if (TopneeNum == 4)
	{
		vecTopnee[4] = CalculTopnee(vecTopnee[4], Direction);

		if (vecIsTurn[2])
		{
			vecTopnee[3] = CalculTopnee(vecTopnee[3], -Direction);

			if (vecIsTurn[1])
			{
				vecTopnee[2] = CalculTopnee(vecTopnee[2], Direction);

				if (vecIsTurn[0])
				{
					vecTopnee[1] = CalculTopnee(vecTopnee[1], -Direction);
				}
			}
		}
	}
}

int main()
{
	vecTopnee.push_back("NULL");

	for (int i = 1; i <= 4; i++)
	{
		string sTemp;
		cin >> sTemp;
		vecTopnee.push_back(sTemp);
	}

	cin >> K;		

	for (int i = 0; i < K; i++)
	{
		int TopneeNum;
		int Direction;

		cin >> TopneeNum >> Direction;

		if (vecTopnee[1][2] != vecTopnee[2][6])
		{
			vecIsTurn[0] = true;
		}

		else
		{
			vecIsTurn[0] = false;
		}

		if (vecTopnee[2][2] != vecTopnee[3][6])
		{
			vecIsTurn[1] = true;
		}

		else
		{
			vecIsTurn[1] = false;
		}

		if (vecTopnee[3][2] != vecTopnee[4][6])
		{
			vecIsTurn[2] = true;
		}

		else
		{
			vecIsTurn[2] = false;
		}

		TurnTopnee(TopneeNum, Direction);		
	}

	// 점수 계산
	if (vecTopnee[1][0] == '1')
	{
		answer += 1;
	}

	if (vecTopnee[2][0] == '1')
	{
		answer += 2;
	}

	if (vecTopnee[3][0] == '1')
	{
		answer += 4;
	}

	if (vecTopnee[4][0] == '1')
	{
		answer += 8;
	}

	cout << answer << '\n';

	return 0;
}