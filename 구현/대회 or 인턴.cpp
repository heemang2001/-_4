#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M, K;
int Answer;

int main()
{
	cin >> N >> M >> K;

	bool bK = false;

	while (1)
	{
		if (bK == false)
		{
			while (1)
			{
				if (K <= 0)
				{
					bK = true;
					break;					
				}

				if (N >= 2 * M)
				{
					K--;
					N--;
				}

				else
				{
					K--;
					M--;
				}
			}
		}

		if (N < 2 || M < 1)
		{
			break;
		}

		else
		{
			N -= 2;
			M -= 1;
			Answer++;
		}
		
	}

	cout << Answer << '\n';

	return 0;
}