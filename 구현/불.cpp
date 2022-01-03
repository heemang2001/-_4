#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int T;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int arrMap[1001][1001];
bool bVisited[1001][1001];
queue<pair<int, int>> qFire;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--)
	{
		int w, h;
		queue<pair<int, int>> q;

		// 초기화
		memset(arrMap, 0, sizeof(arrMap));
		memset(bVisited, false, sizeof(bVisited));
		while (!qFire.empty())
		{
			qFire.pop();
		}

		cin >> w >> h;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				char cTemp;
				cin >> cTemp;

				// 벽이면
				if (cTemp == '#')
				{
					arrMap[i][j] = 1;
				}

				// 불이면
				else if (cTemp == '*')
				{
					qFire.push({ i,j });
					arrMap[i][j] = -1;
				}

				// 상근이의 위치면
				else if (cTemp == '@')
				{
					q.push({ i,j });
					bVisited[i][j] = true;
					arrMap[i][j] = 2;
				}

				else
				{
					arrMap[i][j] = 0;
				}
			}
		}	

		int cnt_Moved = 0;
		while (1)
		{
			bool bClear = false;
			cnt_Moved++;

			// 불 확산부분
			int size_Fire = qFire.size();			
			while (size_Fire--)
			{
				int Fire_x = qFire.front().first;
				int Fire_y = qFire.front().second;
				qFire.pop();

				for (int i = 0; i < 4; i++)
				{
					int Fire_nx = Fire_x + dx[i];
					int Fire_ny = Fire_y + dy[i];

					if (Fire_nx >= 0 && Fire_ny >= 0 && Fire_nx < h && Fire_ny < w)
					{
						if (arrMap[Fire_nx][Fire_ny] == 0 || arrMap[Fire_nx][Fire_ny] == 2)
						{
							arrMap[Fire_nx][Fire_ny] = -1;
							qFire.push({ Fire_nx,Fire_ny });
						}
					}
				}
			}

			// 상근이 이동부분
			int size_People = q.size();
			if (size_People == 0)
			{
				cout << "IMPOSSIBLE" << '\n';
				break;
			}

			while (size_People--)
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				if (((x == 0 || x == h - 1) && (y >= 0 && y < w)) || (y == 0 || y == w - 1))
				{
					cout << cnt_Moved << '\n';
					bClear = true;
					break;
				}

				for (int i = 0; i < 4; i++)
				{
					int next_x = x + dx[i];
					int next_y = y + dy[i];

					if (next_x >= 0 && next_y >= 0 && next_x < h && next_y < w)
					{
						if (arrMap[next_x][next_y] == 0 && !bVisited[next_x][next_y])
						{
							bVisited[next_x][next_y] = true;
							arrMap[next_x][next_y] = 2;
							q.push({ next_x,next_y });
						}
					}
				}
			}

			if (bClear == true)
			{
				break;
			}
		}
	}

	return 0;
}