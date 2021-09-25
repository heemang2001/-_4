#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int Answer;
vector<int> vecAnswer;

bool cmp(int num1, int num2)
{
	int nTemp1 = abs(100 - num1);
	int nTemp2 = abs(100 - num2);

	if (nTemp1 == nTemp2)
	{
		return num1 > num2;
	}

	else
	{
		return nTemp1 < nTemp2;
	}
}

int main()
{
	vector<int> vecNum(10);

	for (int i = 0; i < 10; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecNum[i] = nTemp;
	}

	int nValue = vecNum.front();
	vecAnswer.push_back(nValue);

	for (int i = 1; i < vecNum.size(); i++)
	{
		nValue += vecNum[i];
		vecAnswer.push_back(nValue);

		if (nValue >= 100)
		{
			break;
		}
	}

	sort(vecAnswer.begin(), vecAnswer.end(), cmp);

	cout << vecAnswer.front() << '\n';

	return 0;
}