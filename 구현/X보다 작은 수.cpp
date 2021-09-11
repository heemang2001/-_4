#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int N, X;
vector<int> vecAnswer;

int main()
{
	cin >> N >> X;

	vector<int> vecNum;

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecNum.push_back(nTemp);
	}	

	for (int i = 0; i < vecNum.size(); i++)
	{
		if (X > vecNum[i])
		{
			vecAnswer.push_back(vecNum[i]);
		}
	}

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << ' ';
	}

	return 0;
}