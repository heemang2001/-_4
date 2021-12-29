#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
int r, c, d;
int Answer;
int arrMap[51][51];

// 0 = 북 / 1 = 동 / 2 = 남 / 3 = 서
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int main()
{
	cin >> N >> M;
	cin >> r >> c >> d;	

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arrMap[i][j];
		}
	}

	while (1)
	{
		// 현재위치 청소
		if (arrMap[r][c] == 0)
		{
			arrMap[r][c] = 2;
			Answer++;
		}

		int next = 0;

		for (int i = 0; i < 4; i++)
		{
			// 왼쪽방향으로 회전
			d = (d + 3) % 4;
			int next_x = r + dx[d];
			int next_y = c + dy[d];
						
			if (arrMap[next_x][next_y] == 0)
			{
				r = next_x;
				c = next_y;
				next = 1;
				break;
			}
		}

		if (next == 1)
		{
			continue;
		}

		// 후진
		int newDirection = (d + 2) % 4;
		r = r + dx[newDirection];
		c = c + dy[newDirection];

		if (arrMap[r][c] == 1)
		{
			break;
		}
	}

	cout << Answer << '\n';

	return 0;
}