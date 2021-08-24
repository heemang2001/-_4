#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int answer;
vector<int> vecNum;

int main()
{
	for (int i = 0; i < 7; i++)
	{
		int nTemp;
		cin >> nTemp;

		if (nTemp % 2 == 1)
		{
			vecNum.push_back(nTemp);
		}
	}

	if (vecNum.empty())
	{
		cout << -1 << '\n';
		return 0;
	}

	sort(vecNum.begin(), vecNum.end());

	for (int i = 0; i < vecNum.size(); i++)
	{
		answer += vecNum[i];
	}

	cout << answer << '\n';
	cout << vecNum.front() << '\n';

	return 0;
}