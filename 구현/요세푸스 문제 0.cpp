#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int N, K;
queue<int> q;

int main()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	cout << "<";

	while (N--)
	{
		for (int i = 0; i < K; i++)
		{
			// K��° ����̸�
			if (i == K - 1)
			{
				cout << q.front();

				if (q.size() != 1)
				{
					cout << ", ";
				}
			}

			// K��° ����� �ƴϸ�
			else
			{
				q.push(q.front());
			}

			q.pop();
		}
	}

	cout << ">" << '\n';

	return 0;
}