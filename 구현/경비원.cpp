#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int Garo, Sero;
int cnt_Store;
int Answer;

// [첫째 수]는 상점이 위치한 방향 // 1은 블록의 북쪽, 2는 블록의 남쪽, 3은 블록의 서쪽, 4는 블록의 동쪽에 상점이 있음을 의미
// [둘째 수]는 상점이 블록의 북쪽 또는 남쪽에 위치한 경우 블록의 왼쪽 경계로부터의 거리를 나타내고, 상점이 블록의 동쪽 또는 서쪽에 위치한 경우 블록의 위쪽 경계로부터의 거리를 나타낸다
int main()
{
	cin >> Garo >> Sero;
	cin >> cnt_Store;

	vector<pair<int, int>> vecStore;

	for (int i = 0; i < cnt_Store + 1; i++)
	{
		int nTemp1;
		int nTemp2;
		cin >> nTemp1 >> nTemp2;

		vecStore.push_back({ nTemp1,nTemp2 });
	}

	for (int i = 0; i < cnt_Store; i++)
	{
		// 방향이 같다면
		if (vecStore[i].first == vecStore.back().first)
		{
			Answer += abs(vecStore.back().second - vecStore[i].second);
		}

		// 방향이 다르면
		else
		{
			// 남 - 북
			if ((vecStore[i].first == 1 || vecStore[i].first == 2) && (vecStore.back().first == 1 || vecStore.back().first == 2))
			{
				Answer += min(Sero + vecStore.back().second + vecStore[i].second, Sero + (Garo - vecStore.back().second) + (Garo - vecStore[i].second));
			}

			// 동 - 서
			else if ((vecStore[i].first == 3 || vecStore[i].first == 4) && (vecStore.back().first == 3 || vecStore.back().first == 4))
			{
				Answer += min(Garo + vecStore.back().second + vecStore[i].second, Garo + (Sero - vecStore.back().second) + (Sero - vecStore[i].second));
			}

			// 남북 - 동서
			else if ((vecStore[i].first == 1 || vecStore[i].first == 2) && (vecStore.back().first == 3 || vecStore.back().first == 4))
			{
				if (vecStore[i].first == 1 && vecStore.back().first == 3)
				{
					Answer += vecStore.back().second + vecStore[i].second;
				}

				else if (vecStore[i].first == 1 && vecStore.back().first == 4)
				{
					Answer += vecStore.back().second + (Sero - vecStore[i].second);
				}

				else if (vecStore[i].first == 2 && vecStore.back().first == 3)
				{
					Answer += (Garo - vecStore.back().second) + vecStore[i].second;
				}

				else if (vecStore[i].first == 2 && vecStore.back().first == 4)
				{
					Answer += (Garo - vecStore.back().second) + (Sero - vecStore[i].second);
				}
			}

			// 동서 - 남북
			else if ((vecStore[i].first == 3 || vecStore[i].first == 4) && (vecStore.back().first == 1 || vecStore.back().first == 2))
			{
				if (vecStore[i].first == 3 && vecStore.back().first == 1)
				{
					Answer += vecStore.back().second + vecStore[i].second;
				}
				
				else if (vecStore[i].first == 3 && vecStore.back().first == 2)
				{
					Answer += vecStore.back().second + (Sero - vecStore[i].second);
				}

				else if (vecStore[i].first == 4 && vecStore.back().first == 1)
				{
					Answer += (Garo - vecStore.back().second) + vecStore[i].second;
				}

				else if (vecStore[i].first == 4 && vecStore.back().first == 2)
				{
					Answer += (Garo - vecStore.back().second) + (Sero - vecStore[i].second);
				}
			}
		}
	}

	cout << Answer << '\n';

	return 0;
}