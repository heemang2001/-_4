#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int Garo, Sero;
int cnt_Store;
int Answer;

// [ù° ��]�� ������ ��ġ�� ���� // 1�� ����� ����, 2�� ����� ����, 3�� ����� ����, 4�� ����� ���ʿ� ������ ������ �ǹ�
// [��° ��]�� ������ ����� ���� �Ǵ� ���ʿ� ��ġ�� ��� ����� ���� ���κ����� �Ÿ��� ��Ÿ����, ������ ����� ���� �Ǵ� ���ʿ� ��ġ�� ��� ����� ���� ���κ����� �Ÿ��� ��Ÿ����
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
		// ������ ���ٸ�
		if (vecStore[i].first == vecStore.back().first)
		{
			Answer += abs(vecStore.back().second - vecStore[i].second);
		}

		// ������ �ٸ���
		else
		{
			// �� - ��
			if ((vecStore[i].first == 1 || vecStore[i].first == 2) && (vecStore.back().first == 1 || vecStore.back().first == 2))
			{
				Answer += min(Sero + vecStore.back().second + vecStore[i].second, Sero + (Garo - vecStore.back().second) + (Garo - vecStore[i].second));
			}

			// �� - ��
			else if ((vecStore[i].first == 3 || vecStore[i].first == 4) && (vecStore.back().first == 3 || vecStore.back().first == 4))
			{
				Answer += min(Garo + vecStore.back().second + vecStore[i].second, Garo + (Sero - vecStore.back().second) + (Sero - vecStore[i].second));
			}

			// ���� - ����
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

			// ���� - ����
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