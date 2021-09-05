#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int T;
vector<int> vecAnswer;

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;	// ������ ����
		int M;	// �� ������ �μ�Ǿ����� �ñ��� ������ ���� Queue���� ���°�� �����ִ°�(�ǿ��� 0)
		queue<pair<int, int>> qTemp;
		vector<int> vecTemp;

		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			int nTemp;
			cin >> nTemp;
			vecTemp.push_back(nTemp);
			qTemp.push({ nTemp, i });
		}

		int MaxValue = *max_element(vecTemp.begin(), vecTemp.end());	
		bool bFinish = false;

		while (1)
		{
			int count = 0;

			if (vecTemp.empty() || bFinish)
			{
				break;
			}

			while (1)
			{
				if (MaxValue != qTemp.front().first)
				{
					pair<int, int> qFront = qTemp.front();
					qTemp.pop();
					qTemp.push(qFront);
				}

				else
				{
					count++;

					if (qTemp.front().second == M)
					{
						vecAnswer.push_back(count);						
						bFinish = true;
						qTemp.pop();
						break;
					}

					vecTemp.erase(max_element(vecTemp.begin(), vecTemp.end()));
					MaxValue = *max_element(vecTemp.begin(), vecTemp.end());
					qTemp.pop();
				}
			}
		}
	}

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << '\n';
	}

	return 0;
}