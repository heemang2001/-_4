#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int Answer;
bool bPeople[101];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;

		if (bPeople[nTemp] == false)
		{
			bPeople[nTemp] = true;
		}

		else
		{
			Answer++;
		}		
	}

	cout << Answer << '\n';

	return 0;
}