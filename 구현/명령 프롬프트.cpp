#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
vector<string> vecStr;
string Answer;

int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		string sTemp;
		cin >> sTemp;
		vecStr.push_back(sTemp);
	}

	if (N == 1)
	{
		cout << vecStr[0] << '\n';
	}

	else
	{
		Answer = "";
		int StrSize = vecStr[0].size();		

		for (int i = 0; i < StrSize; i++)
		{
			bool bSame = true;
			char curChar = '\0';

			for (int j = 0; j < vecStr.size(); j++)
			{
				if (curChar == '\0')
				{
					curChar = vecStr[j][i];
				}

				else if(curChar != vecStr[j][i])
				{
					bSame = false;
					break;
				}
			}

			if (bSame == true)
			{
				Answer += curChar;
			}

			else
			{
				Answer += "?";
			}
		}

		cout << Answer << '\n';
	}

	return 0;
}