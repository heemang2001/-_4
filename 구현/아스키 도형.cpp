#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int h, w;
int cnt_Slash;
int Answer;
string sMemo[101];

int main()
{
	cin >> h >> w;

	for (int i = 0; i < h; i++)
	{
		string sTemp;
		cin >> sTemp;
		sMemo[i] = sTemp;
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (sMemo[i][j] == '/' || sMemo[i][j] == '\\')
			{
				cnt_Slash++;
				Answer++;
			}

			else if (cnt_Slash % 2 == 1 && sMemo[i][j] == '.')
			{
				Answer += 2;
			}
		}
	}

	cout << Answer / 2 << '\n';

	return 0;
}