#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int R, C;
string Map[11];
string Answer[11];
queue<pair<int, int>> q;
vector<pair<int, int>> vecRemain;
bool bChange[11][11];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second > p2.second;
}

void Check(int x, int y)
{
	int cnt_Sea = 0;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x < 0 || next_y < 0 || next_x >= R || next_y >= C || (Map[next_x][next_y] == '.' && !bChange[next_x][next_y]))
		{
			cnt_Sea++;			
		}
	}

	if (cnt_Sea >= 3)
	{
		Map[x][y] = '.';
		bChange[x][y] = true;
	}

	else
	{
		vecRemain.push_back({ x,y });
	}
}

int main()
{
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		cin >> Map[i];
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (Map[i][j] == 'X')
			{
				q.push({ i,j });
			}
		}
	}

	while (!q.empty())
	{
		Check(q.front().first, q.front().second);
		q.pop();
	}		

	int min_Sero = 987654321;
	int max_Sero = -1;
	int min_Garo = 987654321;
	int max_Garo = -1;

	for (int i = 0; i < vecRemain.size(); i++)
	{
		min_Sero = min(min_Sero, vecRemain[i].first);
		max_Sero = max(max_Sero, vecRemain[i].first);
		min_Garo = min(min_Garo, vecRemain[i].second);
		max_Garo = max(max_Garo, vecRemain[i].second);
	}

	for (int j = min_Sero; j <= max_Sero; j++)
	{
		for (int i = min_Garo; i <= max_Garo; i++)
		{
			cout << Map[j][i];
		}

		if (j != max_Sero)
		{
			cout << '\n';
		}		
	}	

	return 0;
}