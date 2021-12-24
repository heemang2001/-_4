#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

bool IsPelrin(int num)
{
	string sNum = to_string(num);
	stack<char> stk;

	if (sNum.length() % 2 == 0)
	{
		int midindex = sNum.length() / 2;

		for (int i = 0; i < midindex; i++)
		{
			stk.push(sNum[i]);
		}

		for (int i = midindex; i < sNum.length(); i++)
		{
			if (!stk.empty())
			{
				int nTemp = stk.top();
				stk.pop();

				if (nTemp != sNum[i])
				{
					return false;
				}
			}
		}

		return true;
	}

	else
	{
		int midindex = sNum.length() / 2;

		for (int i = 0; i < midindex; i++)
		{
			stk.push(sNum[i]);
		}

		for (int i = midindex + 1; i < sNum.length(); i++)
		{
			if (!stk.empty())
			{
				int nTemp = stk.top();
				stk.pop();

				if (nTemp != sNum[i])
				{
					return false;
				}
			}
		}

		return true;
	}	
}

int main()
{
	vector<string> vecAnswer;

	while (1)
	{
		int nInput = -1;

		cin >> nInput;

		if (nInput == 0)
		{
			break;
		}

		if (IsPelrin(nInput))
		{
			vecAnswer.push_back("yes");
		}

		else
		{
			vecAnswer.push_back("no");
		}
	}

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << '\n';
	}

	return 0;
}