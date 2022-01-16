#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int N;
int Answer;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		bool bGroup = true;
		bool bContinue = false;
		string sTemp;
		cin >> sTemp;

		unordered_map<char, bool> hashTemp;

		for (int i = 0; i < sTemp.size(); i++)
		{
			if (sTemp[i] == sTemp[i + 1])
			{
				if (bContinue)
				{
					continue;
				}

				if (hashTemp[sTemp[i]] == false)
				{
					hashTemp[sTemp[i]] = true;
				}

				else
				{
					bGroup = false;
					break;
				}

				bContinue = true;							
			}

			else
			{
				if (hashTemp[sTemp[i]] == false)
				{
					hashTemp[sTemp[i]] = true;
				}

				else if(bContinue == true)
				{
					bContinue = false;
					continue;
				}

				else
				{
					bGroup = false;
					break;
				}
			}
		}

		if (bGroup == true)
		{
			Answer++;
		}
	}

	cout << Answer << '\n';

	return 0;
}