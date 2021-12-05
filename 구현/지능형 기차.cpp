#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int cnt_InTrain;
int Answer;

int main()
{
	for (int i = 0; i < 4; i++)
	{
		int nTemp1;
		int nTemp2;

		cin >> nTemp1 >> nTemp2;
				
		cnt_InTrain -= nTemp1;
		cnt_InTrain += nTemp2;

		Answer = max(Answer, cnt_InTrain);
	}

	cout << Answer << '\n';

	return 0;
}