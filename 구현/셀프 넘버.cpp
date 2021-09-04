#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 10001

vector<int> vecAnswer;
bool bVisited[MAX];

bool IsSelfNumber(int num)
{
	return false;
}

void MakeNewNumber(int num)
{
	string sTemp = to_string(num);
	int nTemp = 0;

	for (int i = 0; i < sTemp.size(); i++)
	{
		nTemp += sTemp[i] - '0';
	}

	int next_num = num + nTemp;

	if (bVisited[next_num] || next_num > 10000)
	{
		return;
	}

	bVisited[next_num] = true;
	MakeNewNumber(next_num);
}

int main()
{
	for (int i = 1; i <= MAX; i++)
	{
		if (bVisited[i])
		{
			continue;
		}	

		MakeNewNumber(i);
	}

	for (int i = 1; i <= MAX; i++)
	{
		if (bVisited[i] == false)
		{
			vecAnswer.push_back(i);
		}
	}

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		if (vecAnswer[i] < 10000)
		{
			cout << vecAnswer[i] << '\n';
		}		
	}

	return 0;
}