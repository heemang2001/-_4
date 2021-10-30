#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int T;
int H;
int W;
int N;
vector<int> vecAnswer;

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int nTemp = 101;
		int nTemp2 = 1;

		cin >> H >> W >> N;

		bool bVisited[100][100] = {false,};

		while (1)
		{
			if (nTemp2 == N)
			{
				vecAnswer.push_back(nTemp);
				break;
			}

			for (int j = 0; j < H; j++)
			{
				bool bFind = false;

				for (int k = 0; k < W; k++)
				{
					if (bVisited[j][k] == false)
					{
						bVisited[j][k] = true;
						nTemp += 100;

						if (nTemp > 100 * (H + 1))
						{
							nTemp = nTemp - (100 * H) + 1;
						}

						bFind = true;
						break;
					}

					else
					{
						continue;
					}
				}

				if (bFind == true)
				{
					break;
				}
			}

			nTemp2++;
		}		
	}

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << '\n';
	}

	return 0;
}