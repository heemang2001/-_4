#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, L;
int j;
int cnt;
int Answer;
int arrMap[101][101];

int main()
{
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arrMap[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arrMap[i + N][j] = arrMap[j][i];
		}
	}

	for (int i = 0; i < N * 2; i++)
	{
		cnt = 1;

		for (j = 0; j < N - 1; j++)
		{
			if (arrMap[i][j] == arrMap[i][j + 1])
			{
				cnt++;
			}

			else if(arrMap[i][j] + 1 == arrMap[i][j + 1] && cnt >= L)
			{
				cnt = 1;
			}

			else if (arrMap[i][j] - 1 == arrMap[i][j + 1] && cnt >= 0)
			{
				cnt = -L + 1;
			}

			else
			{
				break;
			}
		}

		if (j == N - 1 && cnt >= 0)
		{
			Answer++;
		}
	}

	cout << Answer << '\n';

	return 0;
}